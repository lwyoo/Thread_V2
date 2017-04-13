#include "datathread.h"
#include <QDebug>
#include <QTimer>
/*
 * Egine Thread 에서 오는 시그널을 가지고 모델리 / parsing 하는 class
 */

DataThread::DataThread(QObject *parent)
    : QThread (parent)
{
    setObjectName("Engine Thread");
}

