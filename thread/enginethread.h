#ifndef ENGINETHREAD_H
#define ENGINETHREAD_H

#include <QThread>

class QTimer;
class EngineThread : public QThread
{
    Q_OBJECT
public:
    EngineThread(QObject* parent = 0);

    void run();
    bool event(QEvent * e);
signals:
    void request();
public slots:
private:
};

#endif // ENGINETHREAD_H
