#include "engineclass.h"
#include "enginedatalistmodel.h"
#include <QDebug>
#include <QTimer>
#include <QCoreApplication>
#include "dataclass.h"
EngineClass * engineClassInstance = NULL;

EngineClass::EngineClass(QObject *parent)
    : QObject(parent)
    , m_List(new EngineDataListModel)
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()) , this , SLOT (makeData()));
    timer->start(5000);
}

EngineClass *EngineClass::instance()
{
    if (engineClassInstance == NULL)
    {
        engineClassInstance = new EngineClass;
    }
    else
    {

    }
    return engineClassInstance;
}

EngineDataListModel *EngineClass::getEngineDataModel()
{
    return m_List;
}

void EngineClass::makeData()
{
    qDebug() << Q_FUNC_INFO << "make list start";
    m_List->listClean();
    for (int i = 0 ; i < 1000000 ; i++)
    {
        m_List->addItem(EngineDataElement(qrand()  , "text1" , "text2", "text3", "text4" , "text5"));
    }
    qApp->postEvent(DataClass::instance(), new QEvent(EngineDataUpdate));

    qDebug() << Q_FUNC_INFO << "make list end";
}
