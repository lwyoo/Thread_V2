#include "datalistmodel.h"

DataListModel::DataListModel(QObject *parent)
{

}

QHash<int, QByteArray> DataListModel::roleNames() const
{
    QHash<int , QByteArray> roles;

    roles[LIST_COUNT   ] = "listCount";
    roles[LIST_TEXT_1  ] = "listText1";
    roles[LIST_TEXT_2  ] = "listText2";
    return roles;
}

QModelIndex DataListModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return createIndex(row, column, quintptr(0));
}

int DataListModel::rowCount(const QModelIndex &parent) const
{
    return mList.count();
}

QVariant DataListModel::data(const QModelIndex &index, int role) const
{
    if (!indexIsValid(index))
    {
        return QVariant();
    }
    else
    {
        const DataElement & item = mList[index.row()];
        switch (role)
        {
        case LIST_COUNT:
            return item.getCount();
            break;
        case LIST_TEXT_1:
            return item.getText1();
            break;
        case LIST_TEXT_2:
            return item.getText2();
            break;
        default:
            return QVariant();
            break;
        }

    }

}

bool DataListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!indexIsValid(index))
    {
        return false;
    }
    else
    {
        switch (role)
        {
        case LIST_COUNT:
            mList[index.row()].setCount(value.toInt());
            break;
        case LIST_TEXT_1:
            mList[index.row()].setText1(value.toString());
            break;
        case LIST_TEXT_2:
            mList[index.row()].setText2(value.toString());
            break;
        default:
            return false;
            break;
        }

        emit dataChanged(index , index);
        return true;
    }
}

void DataListModel::listClean()
{
    beginResetModel();
    mList.clear();
    endResetModel();
}

bool DataListModel::indexIsValid(const QModelIndex &index) const
{
    return index.isValid() && (index.row() < rowCount() ) && (index.row() > -1);
}

void DataListModel::addItem(const DataElement &item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mList.append(item);
    endInsertRows();
}

void DataListModel::resetList(const QList<DataElement> &item)
{
    beginResetModel();
    mList = item;
    endResetModel();
}

void DataListModel::appendList(const QList<DataElement> &item)
{
    beginResetModel();
    mList += item;
    endResetModel();
}

bool DataListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (0 < count)
    {
        beginRemoveRows(parent, row, row + count - 1);
        while (count--) mList.removeAt(row);
        endRemoveRows();

        return true;
    }
    else
    {
        return false;
    }
}

QList<DataElement> DataListModel::getList()
{
    return mList;
}

