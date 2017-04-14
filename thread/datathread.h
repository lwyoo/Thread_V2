#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QThread>
class DataThread : public QThread
{
    Q_OBJECT
public:
    DataThread(QObject * parent = 0);
    void run();
    bool event(QEvent *event);
    virtual void dataModeling();

    enum State{
        INIT,
        WAIT, // 런을 할수 있는 상태
        WORK // 런 하고있음 못하는 상태
    };
private:
    State state ;
};

#endif // DATATHREAD_H
