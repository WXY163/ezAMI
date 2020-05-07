#include "projecttreemodel.h"
#include <QModelIndex>
#include <QFile>
#include <QTextStream>


projectTreeModel::projectTreeModel(QObject *parent, const QStringList &pathList, bool isNewProject) : QAbstractItemModel(parent)
{
    rootItem = new projectTreeItem({tr("Project"), tr("Path")});
    if(!pathList.isEmpty())
    {
        if (isNewProject)
        {

            setupModelData(pathList);
        }
        else {
            parseProjectFile(pathList);
            //setup model here after modify parse Project file
        }
    }
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
    projectTreeItem* parentItem = item->parentItem();
    if (parentItem == rootItem)
    {
        return QModelIndex();
    }

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

void projectTreeModel::setupModelData(const QStringList &pathList)
{
    QString projectName = pathList.value(0);
    QString projectFileName = projectName + ".ezproj";
    QString path = pathList.value(1) + "/" + projectFileName;

    projectTreeItem *projectRoot = new projectTreeItem({QVariant(projectName), QVariant("")}, rootItem);
    rootItem->appendChild(projectRoot);
    projectTreeItem *projectFileNode = new projectTreeItem({QVariant(projectFileName), QVariant(path)}, projectRoot);
    projectRoot->appendChild(projectFileNode);
    projectTreeItem *sourceCodeNode = new projectTreeItem({QVariant("Source Code"), QVariant("")}, projectRoot);
    projectRoot->appendChild(sourceCodeNode);
    projectTreeItem *excutableNode = new projectTreeItem({QVariant("Excutble"), QVariant("")}, projectRoot);
    projectRoot->appendChild(excutableNode);
    projectTreeItem *amiModelNode = new projectTreeItem({QVariant("AMI Model"), QVariant("")}, projectRoot);
    projectRoot->appendChild(amiModelNode);
    projectTreeItem *resourceNode = new projectTreeItem({QVariant("Resource"), QVariant("")}, projectRoot);
    projectRoot->appendChild(resourceNode);
    /*
    int count = 0;
    projectTreeItem* temp;
    projectTreeItem* childNode;
    for (auto it = vectorList.begin(); it != vectorList.end(); it++)
    {

        if (count==0 || count==2 || count==5 ||count== 7)
            {
                temp = new projectTreeItem(*it, parent);
                parent->appendChild(temp);
            }
        else {

        switch (count) {
        case 1:
            childNode = new projectTreeItem(*it, temp);
            temp->appendChild(childNode);
            break;
        case 3:
            childNode = new projectTreeItem(*it, temp);
            temp->appendChild(childNode);
            break;
        case 4:
            childNode = new projectTreeItem(*it, temp);
            temp->appendChild(childNode);
            break;
        case 6:
            childNode = new projectTreeItem(*it, temp);
            temp->appendChild(childNode);
            break;
        case 8:
            childNode = new projectTreeItem(*it, temp);
            temp->appendChild(childNode);
            break;
        case 9:
            childNode = new projectTreeItem(*it, temp);
            temp->appendChild(childNode);
            break;
        }
                }
        count++;
    }
    */
}

QVector<QVector<QVariant>> projectTreeModel::parseProjectFile(const QStringList &pathList)

{
    QString projectName = pathList.value(0);
    QString projectFileName = projectName + ".ezproj";
    QString path = pathList.value(1) + "/" + projectFileName;

    QFile projectFile(path);
    if (!projectFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return QVector<QVector<QVariant>>();
    }
    QVector<QVector<QVariant>> modelVector;
    QTextStream in(&projectFile);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if(line == "Project")
        {
            QVector<QVariant> vave;
            vave.append(QVariant(line));
            vave.append(QVariant(" "));
            modelVector.append(vave);
            line = in.readLine();
            QStringList list = line.split("\t");
            QVector<QVariant> vave1;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                vave1.append(QVariant(*it));
            }
            modelVector.append(vave1);
        }
        if(line == "Source Code")
        {
            QVector<QVariant> vave;
            vave.append(QVariant(line));
            vave.append(QVariant(" "));
            modelVector.append(vave);
            line = in.readLine();
            QStringList list = line.split("\t");
            QVector<QVariant> vave1;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                vave1.append(QVariant(*it));
            }
            modelVector.append(vave1);
            line = in.readLine();
            list = line.split("\t");
            QVector<QVariant> vave2;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                vave2.append(QVariant(*it));
            }
            modelVector.append(vave2);
        }
        if(line == "Excutable")
        {
            QVector<QVariant> vave;
            vave.append(QVariant(line));
            vave.append(QVariant(" "));
            modelVector.append(vave);
            line = in.readLine();
            QStringList list = line.split("\t");
            QVector<QVariant> vave1;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                vave1.append(QVariant(*it));
            }
            modelVector.append(vave1);
        }
        if(line == "AMI Model")
        {
            QVector<QVariant> vave;
            vave.append(QVariant(line));
            vave.append(QVariant(" "));
            modelVector.append(vave);
            line = in.readLine();
            QStringList list = line.split("\t");
            QVector<QVariant> vave1;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                vave1.append(QVariant(*it));
            }
            modelVector.append(vave1);
            line = in.readLine();
            list = line.split("\t");
            QVector<QVariant> vave2;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                vave2.append(QVariant(*it));
            }
            modelVector.append(vave2);
        }
    }
    return modelVector;
}

QModelIndex projectTreeModel::getProjectRoot() const
{
    if(rootItem->childCount() == 1)
    {
        return createIndex(0, 0, rootItem->child(0));
    }
    return QModelIndex();
}


