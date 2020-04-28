#ifndef PROJECTTREEMODEL_H
#define PROJECTTREEMODEL_H
#include "projecttreeitem.h"
#include <QAbstractItemModel>
#include <QVariant>
#include <QModelIndex>

class projectTreeModel : public QAbstractItemModel
{

public:
    explicit projectTreeModel( QList<projectTreeItem*> itemList, QObject *parent = nullptr);
    ~projectTreeModel() override;

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    void setupModelData(const QList<projectTreeItem *> itemList, projectTreeItem *parent);
    projectTreeItem *rootItem;
};

#endif // PROJECTTREEMODEL_H
