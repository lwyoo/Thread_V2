#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QThread>
#include "testlistmodel.h"
//#include "enginethread.h"
class EngineThread;


class DataThread : public QObject
{
    Q_OBJECT
public:
    DataThread(QObject * parent = 0);
    static DataThread* instance();
    bool event(QEvent *event) override;
    virtual void dataModeling();
    void setThread(EngineThread * test);
    TestListModel * getData();

    enum State{
        INIT,
        WAIT, // 런을 할수 있는 상태
        WORK // 런 하고있음 못하는 상태
    };
private:
    State state ;
    EngineThread *mData;
    TestListModel * mList;
//    QObject* guiThread;

signals:
    void testSignal();



public slots:
    void run();

};

#endif // DATATHREAD_H
