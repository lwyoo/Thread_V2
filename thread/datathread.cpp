#include "datathread.h"
#include "enginethread.h"
#include <QDebug>
#include <QTimer>
#include <QEvent>
#include <QMutex>
#include <QWaitCondition>
#include <QCoreApplication>
#include <QObject>

/*
 * Egine Thread 에서 오는 시그널을 가지고 모델리 / parsing 하는 class
 */

QWaitCondition wc;
QMutex mutex;

DataThread::DataThread(QObject *parent)
    : QObject (parent)
    , state(INIT)
{
    setObjectName("Data Thread");
}

void DataThread::run()
{
    qDebug() << Q_FUNC_INFO  << QThread::currentThread();

        if (state == INIT)
        {
            qDebug() << "[state ]init ";
            state = WAIT;
        }
        else if (state == WAIT)
        {
            qDebug() << "[state ] wait";
            qDebug() << "[state ] wait lock";
//            mutex.lock();
            qDebug() << "[state ] wait wait";
//            wc.wait(&mutex);
            qDebug() << "[state ] wait wake!!!!!";
            // Event 가 오면 모델링 시작 그전까지는 그냥 대기
            state = WORK;
            dataModeling();
            state = WAIT;
//            mutex.unlock();
            qDebug() << "[state ] wait unLock";
        }
        else if(state == WORK)
        {
            qDebug() << "[state ] work";
            state = WAIT;
        }
    qDebug() << "data end";
}

bool DataThread::event(QEvent *event)
{
    switch (int (event->type()))
    {
    case EngineThread::INIT:
        if (state == WAIT)
        {
            qDebug() << "current state is Wait --> wake ";
            run();
        }
        else
        {
            qDebug() << "current state pass";
        }
        break;
    default:
        return QObject::event(event);
    }
    return QObject::event(event);
}

void DataThread::dataModeling()
{
    qDebug() << "start modeling";
    qDebug() << Q_FUNC_INFO << QThread::currentThread();
    int value = 0;
    for (int i = 0; i<100000; i++)
    {
        for (int j = 0; j<10000; j++)
        {
            value++;
        }
    }
    qDebug() << "end modeling";
}

