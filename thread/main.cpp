#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>

#include "enginethread.h"
    /*
     * 메인 최소 Thread 3
     * Thread1 : Main Thread , GUI Update 하는 Thread
     * Thread2 : Egine Thread - 주기적으로 데이터를 전달하는 놈
     * Thread3 : 데이터를 받아서 처리 하는 Thread
     */

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    QThread::currentThread()->setObjectName("Main Thread"); // Gui를 담당 하는 Thread

    EngineThread * engineThread = new EngineThread;
    engineThread->start();





    return app.exec();
}
