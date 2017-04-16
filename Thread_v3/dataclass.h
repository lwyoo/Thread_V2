#ifndef DATACLASS_H
#define DATACLASS_H

#include <QObject>
#include <QEvent>
//#include "datalistmodel.h"
class DataListModel;
class QEvent;
class DataClass : public QObject
{
    Q_OBJECT
public:
    static const QEvent::Type DataUpdateComplete = QEvent::Type(QEvent::User + 2);
    DataClass(QObject* parent = 0);
    static DataClass* instance();
    void dataModeling();
    bool event(QEvent *event);
    DataListModel * getData();
private:
    DataListModel* m_List;

};

#endif // DATACLASS_H
