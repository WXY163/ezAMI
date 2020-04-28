#include "projecttreemodel.h"
#include <QModelIndex>


projectTreeModel::projectTreeModel(QList<projectTreeItem *> itemList, QObject *parent) : QAbstractItemModel(parent)
{
    rootItem = new projectTreeItem({tr("Title"), tr("Summary")});
    setupModelData(itemList, rootItem);
}

projectTreeModel::~projectTreeModel()
{
    delete rootItem;
}


QModelIndex projectTreeModel::index(int row, int column, const QModelIndex &parent) const
{

    if (!hasIndex(row, column, parent))
        return QModelIndex();

    projectTreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<projectTreeItem*>(parent.internalPointer());

    projectTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}


QVariant projectTreeModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(role != Qt::DisplayRole)
        return QVariant();
    projectTreeItem *item = static_cast<projectTreeItem*>(index.internalPointer());
    return item->data(index.column());
}

Qt::ItemFlags projectTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::NoItemFlags;
    }
    return QAbstractItemModel::flags(index);
}

QVariant projectTreeModel::headerData(int section, Qt::Orientation orientation,int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);
    return QVariant();
}

QModelIndex projectTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();
    projectTreeItem *item = static_cast<projectTreeItem*>(index.internalPointer());
    if (item == rootItem)
    {
        return QModelIndex();
    }
    projectTreeItem* parentItem = item->parentItem();
    return createIndex(parentItem->row(), 0, parentItem);
}

int projectTreeModel::rowCount(const QModelIndex &parent) const
{
    projectTreeItem *parentItem;
    if (!parent.isValid())
        parentItem = rootItem;
    else {
        parentItem = static_cast<projectTreeItem*>(parent.internalPointer());
    }
    return parentItem->childCount();
}

int projectTreeModel::columnCount(const QModelIndex &parent) const
{
     projectTreeItem *parentItem;
    if(parent.isValid())
    {
        parentItem = static_cast<projectTreeItem*>(parent.internalPointer());
    }
    else {
        parentItem = rootItem;
    }
    return parentItem->columnCount();
}

void projectTreeModel::setupModelData(const QList<projectTreeItem*> itemList, projectTreeItem *parent)
{

    for (auto it = itemList.begin(); it != itemList.end(); it++)
    {
        parent->appendChild(*it);
    }

}

