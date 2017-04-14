#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>
#include <QDebug>

#include "enginethread.h"
#include "datathread.h"
#include "listmodelcontrol.h"
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
    ListModelControl::instance()->setRootContext(engine.rootContext());

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    QThread::currentThread()->setObjectName("Main Thread"); // Gui를 담당 하는 Thread


//    QThread* parentThread = new QThread;
//    parentThread->start();

    QThread * subThread1 = new QThread;
    QThread * subThread2 = new QThread;

//    subThread1->moveToThread(parentThread);
//    subThread2->moveToThread(parentThread);

    subThread1->setObjectName("sub 1 Thread"); // manager Thread
    subThread2->setObjectName("sub 2 Thread"); // manager Thread

    dataThread = DataThread::instance();
    engineThread = EngineThread::instance();

    engineThread->setThread(dataThread);
    dataThread->setThread(engineThread);

    dataThread->moveToThread(subThread1);
    engineThread->moveToThread(subThread2);

    QObject::connect(subThread1, SIGNAL(started()), dataThread, SLOT(run()));
    QObject::connect(subThread2, SIGNAL(started()), engineThread, SLOT(run()));

    subThread1->start();
    subThread2->start();

    return app.exec();

    engineThread->deleteLater();
    dataThread->deleteLater();
}
