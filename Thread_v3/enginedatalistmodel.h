#ifndef ENGINEDATALISTMODEL_H
#define ENGINEDATALISTMODEL_H

#include <QAbstractListModel>
#include "enginedataelement.h"

class EngineDataListModel : public QAbstractListModel
{
public:
    enum EngineDataModelRole{
        LIST_COUNT,
        LIST_TEXT_1,
        LIST_TEXT_2,
        LIST_TEXT_3,
        LIST_TEXT_4,
        LIST_TEXT_5,
    };

    EngineDataListModel(QObject * parent = 0);
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

    void addItem(const EngineDataElement &item);
    void resetList(const QList<EngineDataElement> & item);
    void appendList(const QList<EngineDataElement> & item);


    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    QList<EngineDataElement> getList();
    int getEngineCount(int index) ;
    QString getEngineText1(int index);
    QString getEngineText2(int index);

private:
    QList<EngineDataElement> mList;
};

#endif // ENGINEDATALISTMODEL_H
