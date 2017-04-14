#ifndef ENGINETHREAD_H
#define ENGINETHREAD_H

#include <QThread>
#include <QEvent>
#include "datathread.h"
class QTimer;
class EngineThread : public QObject
{
    Q_OBJECT
public:
    static const QEvent::Type INIT = QEvent::Type(QEvent::User + 1);
    EngineThread(QObject* parent = 0);
    void setThread(QObject * test);
//    bool event(QEvent * e);
//signals:
//    void request();
public slots:
    void run();
private:
    QObject*mData;
};

#endif // ENGINETHREAD_H
