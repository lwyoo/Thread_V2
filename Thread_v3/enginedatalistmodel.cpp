#include "enginedatalistmodel.h"

EngineDataListModel::EngineDataListModel(QObject *parent)
{

}

QHash<int, QByteArray> EngineDataListModel::roleNames() const
{
    QHash<int , QByteArray> roles;

    roles[LIST_COUNT   ] = "listCount";
    roles[LIST_TEXT_1  ] = "listText1";
    roles[LIST_TEXT_2  ] = "listText2";
    roles[LIST_TEXT_3  ] = "listText3";
    roles[LIST_TEXT_4  ] = "listText4";
    roles[LIST_TEXT_5  ] = "listText5";
    return roles;
}

QModelIndex EngineDataListModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return createIndex(row, column, quintptr(0));
}

//QModelIndex EngineDataListModel::parent(const QModelIndex &child) const
//{

//}

int EngineDataListModel::rowCount(const QModelIndex &parent) const
{
    return mList.count();
}

QVariant EngineDataListModel::data(const QModelIndex &index, int role) const
{
    if (!indexIsValid(index))
    {
        return QVariant();
    }
    else
    {
        const EngineDataElement & item = mList[index.row()];
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
        case LIST_TEXT_3:
            return item.getText3();
            break;
        case LIST_TEXT_4:
            return item.getText4();
            break;
        case LIST_TEXT_5:
            return item.getText5();
            break;
        default:
            return QVariant();
            break;
        }

    }

}

bool EngineDataListModel::setData(const QModelIndex &index, const QVariant &value, int role)
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
        case LIST_TEXT_3:
            mList[index.row()].setText3(value.toString());
            break;
        case LIST_TEXT_4:
            mList[index.row()].setText4(value.toString());
            break;
        case LIST_TEXT_5:
            mList[index.row()].setText5(value.toString());
            break;

        default:
            return false;
            break;
        }

        emit dataChanged(index , index);
        return true;
    }
}

void EngineDataListModel::listClean()
{
    beginResetModel();
    mList.clear();
    endResetModel();
}

bool EngineDataListModel::indexIsValid(const QModelIndex &index) const
{
    return index.isValid() && (index.row() < rowCount() ) && (index.row() > -1);
}

void EngineDataListModel::addItem(const EngineDataElement &item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mList.append(item);
    endInsertRows();
}

void EngineDataListModel::resetList(const QList<EngineDataElement> &item)
{
    beginResetModel();
    mList = item;
    endResetModel();
}

void EngineDataListModel::appendList(const QList<EngineDataElement> &item)
{
    beginResetModel();
    mList += item;
    endResetModel();
}

bool EngineDataListModel::removeRows(int row, int count, const QModelIndex &parent)
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

QList<EngineDataElement> EngineDataListModel::getList()
{
    return mList;
}

int EngineDataListModel::getEngineCount(int index)
{
    return mList[index].getCount();
}

QString EngineDataListModel::getEngineText1(int index)
{
    return mList[index].getText1();
}

QString EngineDataListModel::getEngineText2(int index)
{
    return mList[index].getText2();
}


//int EngineDataListModel::columnCount(const QModelIndex &parent) const
//{

//}

//bool EngineDataListModel::hasChildren(const QModelIndex &parent) const
//{

//}

