#ifndef GUILISTCONTROL_H
#define GUILISTCONTROL_H
#include <QQmlContext>
#include <QObject>
#include <QEvent>

class DataListModel;

class GuiListControl : public QObject
{
    Q_OBJECT
public:
    static GuiListControl * instance();
    void setRootContext(QQmlContext* context);
    bool event(QEvent *event);
    void guiListUpdate();


private:
    GuiListControl(QObject * parent = 0);
private:
    QQmlEngine* mQmlEngine;
    DataListModel * mList;

};

#endif // GUILISTCONTROL_H
