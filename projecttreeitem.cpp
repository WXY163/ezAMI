/*
 *     ezAMI: IBIS-AMI model generation tool
 *    Copyright (C) 2020
 *   Author: Xinying Wang (xinying@illinois.edu)
 *           Department of Electrical Computer Engineering
 *           University of Illinois at Urbana-Champaign
 *

 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

bool projectTreeItem::removeChild(int row)
{
    if(row < m_childItems.size()&&row >= 0)
        m_childItems.remove(row);
    else {
        return false;
    }
    return true;
}
bool projectTreeItem::removeAllChild()
{
    if(m_childItems.size())
    {
        m_childItems.clear();
    }
    if(m_childItems.size())
        return false;
    return true;
}
