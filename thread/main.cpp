#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>
#include <QDebug>

#include "enginethread.h"
#include "datathread.h"
    /*
     * 메인 최소 Thread 3
     * Thread1 : Main Thread , GUI Update 하는 Thread
     * Thread2 : Egine Thread - 주기적으로 데이터를 전달하는 놈
     * Thread3 : 데이터를 받아서 처리 하는 Thread
     */
EngineThread * engineThread = Q_NULLPTR;
DataThread * dataThread = Q_NULLPTR;


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    QThread::currentThread()->setObjectName("Main Thread"); // Gui를 담당 하는 Thread

    QThread * subThread = new QThread;
    subThread->setObjectName("sub Thread"); // manager Thread
    subThread->start();

    dataThread = new DataThread;
    engineThread = new EngineThread(dataThread);
    engineThread->moveToThread(subThread);


    engineThread->moveToThread(subThread);


    engineThread->start(); // thread start  , 시간마다 이벤트 발생
    dataThread->start(); // thread start , engine Thread 에서 이벤트가 오면 받아서 모델링 하는 Thread





//    for (;;)
//    {
//        qDebug() << QThread::currentThread() << "@@@@@@@@@@@@";
//        QThread::currentThread()->msleep(5000);
//    }



    return app.exec();

    engineThread->deleteLater();
    dataThread->deleteLater();
}
