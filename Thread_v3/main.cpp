#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>
#include "engineclass.h"
#include "dataclass.h"
#include "guilistcontrol.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    GuiListControl::instance()->setRootContext(engine.rootContext());
    DataClass::instance();
    EngineClass::instance();

    QThread * subThread1 = new QThread;
    QThread * subThread2 = new QThread;

    subThread1->setObjectName("sub 1 Thread"); // manager Thread
    subThread2->setObjectName("sub 2 Thread"); // manager Thread

    EngineClass::instance()->moveToThread(subThread1);
    DataClass::instance()->moveToThread(subThread2);

    subThread1->start();
    subThread2->start();

    QObject::connect(subThread1, SIGNAL(started()), EngineClass::instance(), SLOT(makeData()));

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
