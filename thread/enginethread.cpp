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

EngineThread* engineThreadInstance = NULL;
EngineThread::EngineThread(QObject* parent)
    :QObject(parent)
{
    setObjectName("Engine Thread");
    qDebug() << Q_FUNC_INFO  << QThread::currentThread();
    mData = NULL;
    mList = new TestListModel;
}

EngineThread *EngineThread::instance()
{
    if (engineThreadInstance == NULL)
    {
        engineThreadInstance = new EngineThread;
    }
    return engineThreadInstance;
}

void EngineThread::setThread(DataThread *test)
{
    qDebug() << Q_FUNC_INFO  ;
    mData = test;
}

void EngineThread::makeData()
{
    qDebug() << Q_FUNC_INFO  << "dldyddn ";
    if (mList == NULL)
    {
        mList = new TestListModel;
    }
    else
    {

    }
    //    mList->listClean();
    for (int i = 0 ; i < 1000000 ; i++)
    {
        mList->addItem(TestListElement(i , "text1" , "text2", "text3", "iconUrl"));
    }

    qDebug() << Q_FUNC_INFO  << "post event call";
    qApp->postEvent(mData, new QEvent(INIT));

}

TestListModel *EngineThread::getData()
{
    qDebug() << Q_FUNC_INFO  ;
    return mList;
}

void EngineThread::run()
{
    qDebug() << Q_FUNC_INFO  << QThread::currentThread();
    //특정 시간마다 해당 동작
    for(;;)
    {
        makeData();
    }

    //    일단
    //            엔진 쓰레드에서 무작위로 값을 저장해
}

