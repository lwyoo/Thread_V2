#include "enginethread.h"
#include <QDebug>
#include <QTimer>
#include <QCoreApplication>
#include <QObject>
#include "datathread.h"

/*
 * 주기적으로 signal 을 날리는 class
 * Engine 이라는 가정 하에
 */

EngineThread::EngineThread(QObject* parent)
    :QObject(parent)
{
    setObjectName("Engine Thread");
    qDebug() << Q_FUNC_INFO  << QThread::currentThread();
}

void EngineThread::setThread(QObject *test)
{
    mData = test;
}

void EngineThread::run()
{
//    for (;;)
//    {
        qDebug() << Q_FUNC_INFO  << QThread::currentThread();
//        QThread::currentThread()->msleep(5000);
        int value = 0;
        for (int i = 0; i<1000; i++)
        {
            for (int j = 0; j<1000; j++)
            {
                value++;
            }
        }
        qDebug() << Q_FUNC_INFO  << "post event call";
        qApp->postEvent(mData, new QEvent(INIT));
//    }
}

