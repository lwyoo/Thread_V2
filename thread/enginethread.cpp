#include "enginethread.h"
#include <QDebug>
#include <QTimer>
#include <QCoreApplication>
/*
 * 주기적으로 signal 을 날리는 class
 * Engine 이라는 가정 하에
 */

EngineThread::EngineThread(QObject* parent)
    :QThread(parent)
{
    setObjectName("Engine Thread");
    qDebug() << Q_FUNC_INFO  << QThread::currentThread();
//    connect(this , SIGNAL(request()) , this , SLOT (response()));
}

void EngineThread::run()
{
    for (;;)
    {
        //5초마다 특정 시그널 날림
        qDebug() << Q_FUNC_INFO << QThread::currentThread();
        QThread::currentThread()->msleep(500);
        if (parent() != Q_NULLPTR)
        {
            QCoreApplication::postEvent(this->parent(), new QEvent(INIT));
        }
        else
        {
            qDebug() << Q_FUNC_INFO << "parent not found";
        }
//        emit request();
    }
}

