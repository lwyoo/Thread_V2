#ifndef DATATHREAD_H
#define DATATHREAD_H

#include <QThread>
class DataThread : public QThread
{
    Q_OBJECT
public:
    DataThread(QObject * parent);


};

#endif // DATATHREAD_H
