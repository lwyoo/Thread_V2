#include "dataclass.h"
#include "datalistmodel.h"
#include "engineclass.h"
#include "enginedatalistmodel.h"
#include "guilistcontrol.h"
#include <QEvent>
#include <QDebug>
#include <QCoreApplication>
DataClass * dataClassInstance = NULL;

DataClass::DataClass(QObject *parent)
    : QObject(parent)
    , m_List(new DataListModel)
{

}

DataClass *DataClass::instance()
{
    if (dataClassInstance == NULL)
    {
        dataClassInstance = new DataClass;
    }
    return dataClassInstance;
}

void DataClass::dataModeling()
{
    //get data from EngineClass
    qDebug() << Q_FUNC_INFO;
    EngineDataListModel* engineModel =  EngineClass::instance()->getEngineDataModel();

    qDebug() <<"dataModeling start" ;
    m_List->listClean();
    for (int i = 0 ; i < engineModel->rowCount() ; i++)
    {
        m_List->addItem(DataElement(  engineModel->getEngineCount(i)
                                      , engineModel->getEngineText1(i)
                                      , engineModel->getEngineText1(i) ));
    }
    qApp->postEvent(GuiListControl::instance(), new QEvent(DataUpdateComplete));
    qDebug() <<"dataModeling end";
}

bool DataClass::event(QEvent *event)
{
    qDebug() << Q_FUNC_INFO;
    switch(event->type())
    {
    case EngineClass::EngineDataUpdate:
        dataModeling();
        break;
    default:
        return QObject::event(event);

    }
}

DataListModel *DataClass::getData()
{
    return m_List;
}
