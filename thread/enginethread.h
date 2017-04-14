#ifndef ENGINETHREAD_H
#define ENGINETHREAD_H

#include <QThread>
#include <QEvent>
#include "datathread.h"
#include "testlistmodel.h"
class QTimer;
class EngineThread : public QObject
{
    Q_OBJECT
public:
    static const QEvent::Type INIT = QEvent::Type(QEvent::User + 1);
    static const QEvent::Type GUI_UPDATE = QEvent::Type(QEvent::User + 2);
    EngineThread(QObject* parent = 0);
    static EngineThread* instance();
    void setThread(DataThread * test);

    void makeData();
    TestListModel * getData();

public slots:
    void run();
private:
    DataThread* mData;
    TestListModel * mList;

};

#endif // ENGINETHREAD_H
