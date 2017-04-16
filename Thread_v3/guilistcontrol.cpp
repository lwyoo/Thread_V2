#include "guilistcontrol.h"
#include "datalistmodel.h"
#include "dataclass.h"
#include <QDebug>
GuiListControl* guiListControlInstance = NULL;

GuiListControl::GuiListControl(QObject *parent)
    :QObject (parent)
    , mQmlEngine(NULL)
    , mList(new DataListModel)
{

}

GuiListControl *GuiListControl::instance()
{
    if (guiListControlInstance == NULL)
    {
        guiListControlInstance = new GuiListControl;
    }
    else
    {

    }

    return guiListControlInstance;
}

void GuiListControl::setRootContext(QQmlContext *context)
{
    //
    qDebug() << "resigter context for qml";
    context->setContextProperty("TestListModel", mList);
    context->setContextProperty("TestList", this);
}

bool GuiListControl::event(QEvent *event)
{
    switch (event->type())
    {
    case DataClass::DataUpdateComplete:
        guiListUpdate();
        break;
    }

    return QObject::event(event);
}

void GuiListControl::guiListUpdate()
{
    qDebug() << Q_FUNC_INFO << "start ";
    mList->resetList(DataClass::instance()->getData()->getList());

    qDebug() << Q_FUNC_INFO << "end" << mList->rowCount();
}

//업데이트 되면 화면 갱신 하는것
