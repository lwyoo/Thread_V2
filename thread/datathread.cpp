#include "datathread.h"
#include "enginethread.h"
#include <QDebug>
#include <QTimer>
#include <QEvent>
#include <QMutex>
#include <QWaitCondition>
#include <QCoreApplication>
/*
 * Egine Thread 에서 오는 시그널을 가지고 모델리 / parsing 하는 class
 */

QWaitCondition wc;
QMutex mutex;

DataThread::DataThread(QObject *parent)
    : QThread (parent)
    , state(INIT)
{
    setObjectName("Data Thread");
}

void DataThread::run()
{

    for (;;)
    {
        if (state == INIT)
        {
            state = WAIT;

        }
        else if (state == WAIT)
        {
            qDebug() << "lock";
            mutex.lock();
            qDebug() << "wait";
            wc.wait(&mutex);
            // Event 가 오면 모델링 시작 그전까지는 그냥 대기
            state = WORK;
            dataModeling();
            mutex.unlock();
            qDebug() << "unLock";
        }
        else if(state == WORK)
        {
            state = WAIT;
        }
    }
}

bool DataThread::event(QEvent *event)
{
    switch (int (event->type()))
    {
    case EngineThread::INIT:
        if (state == WAIT)
        {
            qDebug() << "current state is Wait --> wake ";
            wc.wakeOne();
        }
        else
        {
            qDebug() << "current state pass";
        }
        break;
    default:
        return QObject::event(event);
    }
    return QThread::event(event);
}

void DataThread::dataModeling()
{
    qDebug() << "start modeling";
    QThread::currentThread()->msleep(10000);
    qDebug() << "end modeling";
}

