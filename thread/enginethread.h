#ifndef ENGINETHREAD_H
#define ENGINETHREAD_H

#include <QThread>
#include <QEvent>

class QTimer;
class EngineThread : public QThread
{
    Q_OBJECT
public:
    static const QEvent::Type INIT = QEvent::Type(QEvent::User + 1);
    EngineThread(QObject* parent = 0);

    void run();
//    bool event(QEvent * e);
signals:
    void request();
public slots:
private:
};

#endif // ENGINETHREAD_H
