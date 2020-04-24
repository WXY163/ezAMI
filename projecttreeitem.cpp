#include "projecttreeitem.h"

projectTreeItem::projectTreeItem(const QVector<QVariant> &data, projectTreeItem *parent)
    :m_itemData(data), m_parentItem(parent)
{

}

projectTreeItem::~projectTreeItem()
{
    qDeleteAll(m_childItems);
}

void projectTreeItem::appendChild(projectTreeItem *child)
{
    m_childItems.append(child);
}

projectTreeItem* projectTreeItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int projectTreeItem::childCount() const
{
    return m_childItems.count();
}

int projectTreeItem::row() const
{
    if(m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<projectTreeItem*>(this));
    return 0;
}

int projectTreeItem::columnCount() const
{
    return m_itemData.count();
}

projectTreeItem *projectTreeItem::parentItem()
{
    return m_parentItem;
}

QVariant projectTreeItem::data(int column) const
{
    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}
