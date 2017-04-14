#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QThread>
class DataThread : public QObject
{
    Q_OBJECT
public:
    DataThread(QObject * parent = 0);
    bool event(QEvent *event) override;
    virtual void dataModeling();

    enum State{
        INIT,
        WAIT, // 런을 할수 있는 상태
        WORK // 런 하고있음 못하는 상태
    };
private:
    State state ;
public slots:
    void run();

};

#endif // DATATHREAD_H
