#ifndef PROJECTTREEMODEL_H
#define PROJECTTREEMODEL_H
#include "projecttreeitem.h"
#include <QAbstractItemModel>
#include <QVariant>
#include <QModelIndex>

class projectTreeModel : public QAbstractItemModel
{

public:
    explicit projectTreeModel(QObject *parent = nullptr,  const QStringList &pathList = QStringList(), bool isNewProject = true);
    ~projectTreeModel() override;

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    void openModelData(const QStringList &filename);
    QModelIndex getProjectRoot(void) const;
    bool removeRow(int row, const QModelIndex &parent = QModelIndex());

    void setupModelData(const QStringList &pathList);

private:

    projectTreeItem *rootItem;
    projectTreeItem *projectRoot;
    projectTreeItem *projectInfo;
    projectTreeItem *sourceCode;
    projectTreeItem *excutable;
    projectTreeItem *amiModel;
    projectTreeItem *resource;
};

#endif // PROJECTTREEMODEL_H
