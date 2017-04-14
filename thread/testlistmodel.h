#ifndef TESTLISTMODEL_H
#define TESTLISTMODEL_H

#include <QAbstractListModel>
#include "testlistelement.h"

class TestListModel : public QAbstractListModel
{
public:

    enum TestListModelRoleName{
        LIST_COUNT,
        LIST_TEXT_1,
        LIST_TEXT_2,
        LIST_TEXT_3,
        LIST_ICON_URL,
    };


    TestListModel(QObject * parent = 0);

    QHash<int , QByteArray> roleNames() const;

    Q_INVOKABLE QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const ;
    Q_INVOKABLE QModelIndex parent(const QModelIndex &child) const ;

    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    Q_INVOKABLE int columnCount(const QModelIndex &parent = QModelIndex()) const ;
    Q_INVOKABLE bool hasChildren(const QModelIndex &parent = QModelIndex()) const;

    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);

    void listClean();

    Q_INVOKABLE bool indexIsValid(const QModelIndex & index) const;

    void addItem(const TestListElement &item);
    void resetList(const QList<TestListElement> & item);
    void appendList(const QList<TestListElement> & item);


    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    QList<TestListElement> getList();

private:
    QList<TestListElement> mList;
};

#endif // TESTLISTMODEL_H
