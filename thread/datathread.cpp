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
            mutex.lock();
            wc.wait(&mutex);
            // Event 가 오면 모델링 시작 그전까지는 그냥 대기
            dataModeling();
            //
            mutex.unlock();

        }
        else if (state == WAIT)
        {
            //이벤트가 올떄까지 대기  , 이벤트가 오면 동작 할수 있게
//            qDebug() << QThread::currentThread() << "모델링 합니다!!!!!!!!!!!!!";
//            state = WORK;

        }
        else if(state == WORK)
        {
            qDebug() << QThread::currentThread() << "나중에 합시다 ";
        }
    }
}

bool DataThread::event(QEvent *event)
{
    switch (int (event->type()))
    {
    case EngineThread::INIT:
        //        신호가 오면 상태를 봐서 동작을 하게 만든다
        if (state == WAIT)
        {
            qDebug() << "current state is Wait --> wake ";
            //런 동작 하게
            wc.wakeAll();
        }
        else
        {
            qDebug() << "current state pass";
            //            그냥 넘긴다
        }
        break;
    default:
        return QObject::event(event);
        break;

    }
    return QThread::event(event);
}

void DataThread::dataModeling()
{
    qDebug() << "start modeling";

    state = WORK;
    QThread::currentThread()->msleep(10000);
    qDebug() << "end modeling";
    state = INIT;
    //    wc.wakeOne();
    //완료 하면 event 날리기 ..
    //    QCoreApplication::postEvent(this, new QEvent(EngineThread::INIT));

}

