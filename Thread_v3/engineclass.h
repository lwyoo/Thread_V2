#ifndef ENGINECLASS_H
#define ENGINECLASS_H

#include <QObject>
#include <QEvent>
//#include "enginedatalistmodel.h"

class EngineDataListModel;
class EngineClass : public QObject
{
    Q_OBJECT
public:
    static const QEvent::Type EngineDataUpdate = QEvent::Type(QEvent::User + 1);
    EngineClass(QObject* parent = 0);
    static EngineClass * instance();
    EngineDataListModel* getEngineDataModel();
public slots:
    void makeData();
private:
    EngineDataListModel* m_List;


};

#endif // ENGINECLASS_H
