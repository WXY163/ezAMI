#ifndef PROJECTTREEITEM_H
#define PROJECTTREEITEM_H
#include <QVector>
#include <QVariant>

class projectTreeItem
{
public:
   explicit projectTreeItem(const QVector<QVariant> &data, projectTreeItem *parentItem = nullptr);
    ~projectTreeItem();
    void setParent(projectTreeItem* parent){m_parentItem = parent;}
    void appendChild(projectTreeItem *child);

    projectTreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    int row() const;

    projectTreeItem *parentItem();
    QVariant data(int column) const;

private:
    QVector<projectTreeItem*> m_childItems;
    QVector <QVariant> m_itemData;
    projectTreeItem *m_parentItem;
};

#endif // PROJECTTREEITEM_H
