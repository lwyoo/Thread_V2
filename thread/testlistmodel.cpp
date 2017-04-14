#include "testlistmodel.h"
#include <QDebug>
#include <QThread>
TestListModel::TestListModel(QObject *parent)
{
    qDebug() << "create TestListModel ";
}

QHash<int, QByteArray> TestListModel::roleNames() const
{
    QHash<int , QByteArray> roles;

    roles[LIST_COUNT   ] = "listCount";
    roles[LIST_TEXT_1  ] = "listText1";
    roles[LIST_TEXT_2  ] = "listText2";
    roles[LIST_TEXT_3  ] = "listText3";
    roles[LIST_ICON_URL] = "listIconUrl";
    return roles;
}

QModelIndex TestListModel::index(int row, int column, const QModelIndex &parent) const
{
//    qDebug() << "TestListModel index";
    Q_UNUSED(parent)
    return createIndex(row, column, quintptr(0));
}

QModelIndex TestListModel::parent(const QModelIndex &child) const
{
    qDebug() << "TestListModel parent";
}

int TestListModel::rowCount(const QModelIndex &parent) const
{
//    qDebug() << "TestListModel rowCount";
    return mList.count();
}

int TestListModel::columnCount(const QModelIndex &parent) const
{
    qDebug() << "TestListModel columnCount";
}

bool TestListModel::hasChildren(const QModelIndex &parent) const
{
    qDebug() << "TestListModel hasChildren";
}

QVariant TestListModel::data(const QModelIndex &index, int role) const
{
//    qDebug() << "TestListModel data";

    if (!indexIsValid(index))
    {
        return QVariant();
    }
    else
    {
        const TestListElement & item = mList[index.row()];
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
        case LIST_ICON_URL:
            return item.getIconUrl();
            break;
        default:
            return QVariant();
            break;
        }

    }

}

bool TestListModel::setData(const QModelIndex &index, const QVariant &value, int role)
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
        case LIST_ICON_URL:
            mList[index.row()].setIconUrl(value.toString());
            break;
        default:
            return false;
            break;
        }

        emit dataChanged(index , index);
        return true;
    }
}

void TestListModel::listClean()
{
    beginResetModel();
    mList.clear();
    endResetModel();
}

bool TestListModel::indexIsValid(const QModelIndex &index) const
{
    return index.isValid() && (index.row() < rowCount() ) && (index.row() > -1);
}

void TestListModel::addItem(const TestListElement &item)
{
//    qDebug() << Q_FUNC_INFO << QThread::currentThread() ;
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mList.append(item);
    endInsertRows();
}

void TestListModel::resetList(const QList<TestListElement> &item)
{
    beginResetModel();
    mList = item;
    endResetModel();
}

void TestListModel::appendList(const QList<TestListElement> &item)
{
    beginResetModel();
    mList += item;
    endResetModel();
}

bool TestListModel::removeRows(int row, int count, const QModelIndex &parent)
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

QList<TestListElement> TestListModel::getList()
{
    return mList;
}
