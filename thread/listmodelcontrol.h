#ifndef LISTMODELCONTROL_H
#define LISTMODELCONTROL_H
#include <QObject>
#include <QEvent>
#include <QQmlContext>

class TestListModel;
class TestThread;
class ListModelControl : public QObject
{
    Q_OBJECT
private:
    ListModelControl(QObject * parent = 0);

public:
    static const QEvent::Type INIT = QEvent::Type(QEvent::User + 1);
    static ListModelControl * instance();

public:

    // 리스트 초기화
    Q_INVOKABLE void listInit();
    // 리스트 x 개 추가
    Q_INVOKABLE void addListModel(const int nValue);
    // 리스트 삭제
    Q_INVOKABLE void removListModel(const int startOffSet , const int endOffSet);
    // 리스트 전체 삭제
    Q_INVOKABLE void allRemoveListModel();

    Q_INVOKABLE void addListModelThread(const int nValue);


    void setRootContext(QQmlContext * context);

    bool event(QEvent *e);

    TestListModel * mList;

private:
    QQmlEngine* mQmlEngine;
//    TestThread* mThread;

//public slots:
//    void receivedFinish(int nValue);

};

#endif // LISTMODELCONTROL_H
