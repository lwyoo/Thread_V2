#include "datathread.h"
#include "enginethread.h"
#include "listmodelcontrol.h"
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
DataThread* dataThreadInstance = NULL;
QWaitCondition wc;
QMutex mutex;

DataThread::DataThread(QObject *parent)
    : QObject (parent)
    , state(INIT)
    , mList(new TestListModel)
{
    setObjectName("Data Thread");
}

DataThread *DataThread::instance()
{
    if (dataThreadInstance == NULL)
    {
        dataThreadInstance = new DataThread;
    }
    else
    {
    }
    return dataThreadInstance;
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
            state = WORK;
            dataModeling();
            state = WAIT;
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
    qDebug() << Q_FUNC_INFO  ;
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
    //데이터 가지고 와서 파싱하기
    qDebug() << Q_FUNC_INFO ;

    if (mData == NULL)
    {
        qDebug() << Q_FUNC_INFO << "data NULL";
    }
    else
    {
        qDebug() << Q_FUNC_INFO << "get Data";
        mList = mData->getData();
        qDebug() << Q_FUNC_INFO  <<  "count : " << mList->rowCount();
//        emit testSignal();
        QCoreApplication::postEvent(ListModelControl::instance(), new QEvent(EngineThread::GUI_UPDATE));
        //postevent 날리기
    }

}

void DataThread::setThread(EngineThread *test)
{
    qDebug() << Q_FUNC_INFO  ;
    mData = test;
}

TestListModel *DataThread::getData()
{
    qDebug() << Q_FUNC_INFO  <<  "count : " << mList->rowCount();
    return mList;
}

