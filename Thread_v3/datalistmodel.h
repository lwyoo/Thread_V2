#ifndef DATALISTMODEL_H
#define DATALISTMODEL_H

#include <QAbstractListModel>
#include "dataelement.h"

class DataListModel : public QAbstractListModel
{
public:
    enum DataListModelRole{
        LIST_COUNT,
        LIST_TEXT_1,
        LIST_TEXT_2,
    };

    DataListModel(QObject * parent = 0);
    QHash<int , QByteArray> roleNames() const;

    Q_INVOKABLE QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const ;
//    Q_INVOKABLE QModelIndex parent(const QModelIndex &child) const ;

    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const ;
//    Q_INVOKABLE int columnCount(const QModelIndex &parent = QModelIndex()) const ;
//    Q_INVOKABLE bool hasChildren(const QModelIndex &parent = QModelIndex()) const;

    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);

    void listClean();

    Q_INVOKABLE bool indexIsValid(const QModelIndex & index) const;

    void addItem(const DataElement &item);
    void resetList(const QList<DataElement> & item);
    void appendList(const QList<DataElement> & item);


    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    QList<DataElement> getList();

private:
    QList<DataElement> mList;
};

#endif // DATALISTMODEL_H
