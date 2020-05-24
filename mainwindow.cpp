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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <iostream>
#include <QMessageBox>
#include <QProcess>
#include <QString>
#include <QFileDialog>
#include <QProcess>
#include <QStringList>
#include <QIcon>
#include <QSize>
#include <QGraphicsSvgItem>
#include <QList>
#include <QLineF>
#include <QPointF>
#include <QFile>
#include <QModelIndex>
#include <QDir>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/img/Logo.svg"));
    this->setWindowTitle(tr("ezAMI1.0"));
    toolBar = new QToolBar(this);
    ui->actionExcitation->setIcon(QIcon(":/img/Excitation.svg"));
    ui->actionExcitation->setIconText("Excitation");
    ui->actionAMI->setIcon(QIcon(":/img/AMI.svg"));
    ui->actionPlot->setIcon(QIcon(":/img/Plotting.svg"));
    ui->amiModelCheckBox->setEnabled(false);
    toolBar->addAction(ui->actionExcitation);
    toolBar->addAction(ui->actionAMI);
    toolBar->addAction(ui->actionPlot);
    toolBar->addSeparator();
    toolBar->addAction(ui->actionSave);
    toolBar->addAction(ui->actionSave_All);
    toolBar->addSeparator();
    toolBar->addAction(ui->actionBuild_2);
    toolBar->addAction(ui->actionRun_2);
    toolBar->addSeparator();
    toolBar->addAction(ui->actionAMI_Generation);
    this->addToolBar(toolBar);

    ui->amiInit->setFont(QFont("Courier", 8));
    ui->amiGetWave->setFont(QFont("Courier", 8));
    ui->amiClose->setFont(QFont("Courier", 8));
    scene = new sceneClick();
    scene->setParent(ui->diagramWindow);
    ui->diagramWindow->setScene(scene);
    svgexcite = new SvgLoad(":/img/Excitation.svg");
    svgAMI = new SvgLoad(":/img/AMI.svg");
    svgPlot = new SvgLoad(":/img/Plotting.svg");
    eaLine = new QGraphicsLineItem();
    epLine = new QGraphicsLineItem();
    eaLine->setPen(QPen(Qt::black,6,Qt::SolidLine,Qt::SquareCap, Qt::BevelJoin));
    epLine->setPen(QPen(Qt::black,6,Qt::SolidLine,Qt::SquareCap, Qt::BevelJoin));
    plot = new plotting(this);
    amiDlg = new amiDialog(this);
    plotDlg = new plotDialog(this);
    excitationDlg = new excitationDialog(this);
    aboutDlg = new aboutDialog(this);
    generateDllDlg = new generateDllDialog(this);
    gccCompiler = new compiler(this);
    simulateEngine = new simulator(this);
    newProjectDlg = new newProjectDialog(this);

    projectArch = new projectTreeModel(this);
    ui->projectTreeView->setModel(projectArch);

    ui->projectTreeView->setContextMenuPolicy(Qt::CustomContextMenu);

    setupContextMenu();


    connect(ui->projectTreeView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenu(const QPoint &)));
    connect(scene, SIGNAL(doubleClick(QPointF)), this, SLOT(on_doubleClicked(QPointF)));
    connect(excitationDlg, SIGNAL(excitationReady(QHash<QString, QString>)), plot, SLOT(coordinateSetup(QHash<QString, QString>)));
    connect(plot, SIGNAL(waveFormReady(QVector<qreal>*)), simulateEngine, SLOT(receiveInputWave(QVector<qreal> *)));
    connect(amiDlg, SIGNAL(filePath(QString)), simulateEngine, SLOT(setDllPath(QString)));
    connect(simulateEngine, SIGNAL(outputReady(QVector<qreal>*)), plot, SLOT(addSimulatedWave(QVector<qreal>*)));
    connect(ui->projectTreeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_projectTreeView_doubleClicked(QMdodelIndex)));
    connect(newProjectDlg, SIGNAL(projectInfo(const QHash<QString, QString> &)), this, SLOT(setProjectInfo(const QHash<QString, QString> &)));
    connect(contextMenu, SIGNAL(triggered(QAction *)), this, SLOT(on_CustomContextMenu_triggered(QAction *)));
    connect(this, SIGNAL(projectArchtoCompiler(projectTreeModel *)), gccCompiler, SLOT(updateProjectArch(projectTreeModel *)));
    connect(generateDllDlg, SIGNAL(generateDll()), gccCompiler, SLOT(amiGeneration()));
    connect(gccCompiler, SIGNAL(sendBuildInfo(const QString &, const QString &)), generateDllDlg, SLOT(dllGenerateStatus(const QString &, const QString &)));
    connect(gccCompiler, SIGNAL(updateProjectArch()), this, SLOT(updateProjectTreeFromCompiler()));




    //set dll path connect amiDlg -> simulateEngine
}

MainWindow::~MainWindow()
{
    delete ui;
    delete plot;
    delete svgexcite;
    delete svgAMI;
    delete svgPlot;

    delete toolBar;
    delete eaLine;
    delete epLine;

    delete amiDlg;
    delete plotDlg;
    delete excitationDlg;
    delete aboutDlg;
    delete generateDllDlg;
    delete gccCompiler;
    delete simulateEngine;

    delete scene;
    delete projectArch;

    delete contextMenu;


}
//#define AMI_INIT
#define AMI_GETWAVE
//#define AMI_CLOSE
void MainWindow::on_actionRun_2_triggered()
{
    if(ui->amiModelCheckBox->isChecked())
    {
        simulateEngine->run();
    }

    plot->show();


#ifdef AMI_INIT

             typedef long (*FunctionPrototype)(double *impulse_matrix,
                                               long row_size,
                                               long aggressors,
                                               double sample_interval,
                                               double bit_time,
                                               char **AMI_parameters_in,
                                               char **AMI_parameters_out,
                                               void *AMI_memory_handle,
                                               char *msg);

            //FunctionPrototype AMI_GetWave = (FunctionPrototype)lib.resolve("AMI_GetWave");
             FunctionPrototype AMI_Init = (FunctionPrototype)lib.resolve("AMI_Init");
            // if null means the symbol was not loaded

            if (AMI_Init){
                double *impulse_matrix = nullptr;
                long row_size = 0;
                long aggressors = 0;
                double sample_interval = 1.0;
                double bit_time =1.0;
                char **AMI_parameters_in = nullptr;
                char **AMI_parameters_out = nullptr;
                void **AMI_memory_handle = nullptr;
                char **msg = nullptr;
                long result = AMI_Init(impulse_matrix,
                                       row_size,aggressors,
                                       sample_interval,
                                       bit_time,
                                       AMI_parameters_in,
                                       AMI_parameters_out,
                                       AMI_memory_handle,
                                       msg);
                ui->statusWindow->append(QString::number(result));
            }
            else {
                ui->statusWindow->append("Cannot use add function Add in dll");
            }

          }
        }

#endif
#ifdef AMI_CLOSE
             typedef long (*FunctionPrototype)( void *AMI_memory_handle);
FunctionPrototype AMI_Close = (FunctionPrototype)lib.resolve("AMI_Close");
if(AMI_Close)
{

    void *AMI_memory_handle = nullptr;
    long result = AMI_Close(AMI_memory_handle);

}
else {

}

}
    }
    #endif
}
void MainWindow::on_actionAMI_Generation_triggered()
{


    generateDllDlg->show();

}


void MainWindow::on_actionBuild_2_triggered()
{

    gccCompiler->show();

}

void MainWindow::on_actionSave_All_triggered()
{
    if(!saveProjectFile())
    {
        QMessageBox::warning(this, "cannot save project!", "Check project file!", "ok");
    }
    if(!saveCodeFile())
    {
        QMessageBox::warning(this, "cannot save code!", "Check code file!", "ok");
    }

}

void MainWindow::on_actionSave_triggered()
{
    if(!saveCodeFile())
    {
        QMessageBox::warning(this, "cannot save code!", "Check code file!", "ok");
    }

}

void MainWindow::drawExcitPlot()
{

}
void MainWindow::on_amiInit_textChanged()
{
    ui->actionSave->setEnabled(true);
}

void MainWindow::on_amiGetWave_textChanged()
{
    ui->actionSave->setEnabled(true);
}

void MainWindow::on_amiClose_textChanged()
{
    ui->actionSave->setEnabled(true);
}

void MainWindow::on_actionExcitation_triggered()
{

    qreal drawWindowHeight = ui->diagramWindow->height();
    qreal drawWindowWidth = ui->diagramWindow->width();

    QGraphicsSvgItem *exItem = svgexcite->svgItem();
    exItem->setParent(scene);
    QSize sz = svgexcite->svgSize();
    qreal scale = 0.4*drawWindowHeight/sz.height();
    exItem->setScale(scale);
    exItem->setPos(QPoint(0, 0));
    exItem->setData(1,QVariant("Excitation"));
    QPointF pt1(scale*(sz.height()-50), 0.5*sz.height()*scale);

    QGraphicsSvgItem *pitem = svgPlot->svgItem();
    pitem->setParent(scene);
    pitem->setScale(scale);
    pitem->setPos(0.66*drawWindowWidth,0);
    QPointF pt2(0.66*1.01*drawWindowWidth,0.5*sz.height()*scale);
    pitem->setData(1,QVariant("Plot"));
    eaLine->setLine(QLineF(pt1, pt2));
    eaLine->setData(1, QVariant("Line"));

    scene->addItem(pitem);
    scene->addItem(eaLine);
    scene->addItem(exItem);

     ui->diagramWindow->fitInView(ui->diagramWindow->sceneRect(),Qt::KeepAspectRatio);
     ui->amiModelCheckBox->setEnabled(true);
}

void MainWindow::on_actionAMI_triggered()
{
    QList<QGraphicsItem *> lst = scene->items();
    qreal drawWindowHeight = ui->diagramWindow->height();
    qreal drawWindowWidth = ui->diagramWindow->width();
    if(lst.isEmpty())
    {
        on_actionExcitation_triggered();
        QGraphicsSvgItem *item = svgAMI->svgItem();
        item->setParent(scene);
        QSize sz = svgexcite->svgSize();
        qreal scale = 0.4*drawWindowHeight/sz.height();
        item->setScale(scale);
        item->setPos(0.33*drawWindowWidth,0);
        item->setZValue(1);
        item->setData(1,QVariant("AMI"));
        scene->addItem(item);
        ui->diagramWindow->fitInView(ui->diagramWindow->sceneRect(),Qt::KeepAspectRatio);
        ui->amiModelCheckBox->setEnabled(true);
        ui->amiModelCheckBox->setChecked(true);
    }
    else if(lst.length()==3)
    {
        QGraphicsSvgItem *item = svgAMI->svgItem();
        item->setParent(scene);
        QSize sz = svgexcite->svgSize();
        qreal scale = 0.4*drawWindowHeight/sz.height();
        item->setScale(scale);
        item->setPos(0.33*drawWindowWidth,0);
        item->setZValue(1);
        item->setData(1,QVariant("AMI"));
        scene->addItem(item);
        ui->diagramWindow->fitInView(ui->diagramWindow->sceneRect(),Qt::KeepAspectRatio);
        ui->amiModelCheckBox->setEnabled(true);
        ui->amiModelCheckBox->setChecked(true);
    }
    else
    {
        if(!ui->amiModelCheckBox->isChecked())
        {
            QGraphicsSvgItem *item = svgAMI->svgItem();
            item->setParent(scene);
            QSize sz = svgexcite->svgSize();
            qreal scale = 0.4*drawWindowHeight/sz.height();
            item->setScale(scale);
            item->setPos(0.33*drawWindowWidth,0);
            item->setZValue(1);
            scene->addItem(item);
            ui->diagramWindow->fitInView(ui->diagramWindow->sceneRect(),Qt::KeepAspectRatio);
        }
    }
}

void MainWindow::on_actionPlot_triggered()
{

    qreal drawWindowHeight = ui->diagramWindow->height();
    qreal drawWindowWidth = ui->diagramWindow->width();

    QGraphicsSvgItem *pitem = svgPlot->svgItem();
    pitem->setParent(scene);
    QSize sz = svgexcite->svgSize();

    pitem->setScale(0.4*drawWindowHeight/sz.height());
    pitem->setPos(0.66*drawWindowWidth,0);
    pitem->setData(1,QVariant("Plot"));
    scene->addItem(pitem);
    QList<QGraphicsItem *> sceneItems = scene->items();
    ui->diagramWindow->fitInView(ui->diagramWindow->sceneRect(),Qt::KeepAspectRatio);

}

void MainWindow::on_actionAbout_triggered()
{
    aboutDlg->show();
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_amiModelCheckBox_stateChanged(int arg1)
{
    if(ui->amiModelCheckBox->isChecked())
    {
        on_actionAMI_triggered();
    }
    else
    {
        QList<QGraphicsItem *> lst = scene->items();
        QList<QGraphicsItem *>::iterator it;
        if(!lst.isEmpty())
        {
            for(it = lst.begin();it!=lst.end(); ++it)
            {
                if((*it)->data(1)=="AMI")
                {
                    scene->removeItem(*it);
                }
            }
        }
    }
}

void MainWindow::on_doubleClicked(QPointF position)
{

    QList<QGraphicsItem *> lst = scene->items();
    QList<QGraphicsItem *>::iterator it;
    if(!lst.isEmpty())
    {
        for (it = lst.begin(); it != lst.end(); ++it)
        {
            if (isInRegion((*it), position))
            {
                if((*it)->data(1).toString() == "AMI")
                {
                    amiDlg->show();
                }
                if ((*it)->data(1).toString() == "Excitation")
                {
                    excitationDlg->show();
                    excitationInfo = excitationDlg->getSampleInfo();

                }
                if ((*it)->data(1).toString() == "Plot")
                {
                    plotDlg->show();
                }

            }
        }
    }
}

bool MainWindow::isInRegion(QGraphicsItem *item, const QPointF &clickPos)
{
    if(clickPos.x() > item->x() &&
       clickPos.x() < item->x() + item->scale() * item->boundingRect().width() &&
       clickPos.y() > item->y() &&
       clickPos.y() < item->y() + item->scale() * item->boundingRect().height())
    {
        return true;
    }
    return false;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fullFileName = QFileDialog::getOpenFileName(this, tr("open project"),
                                                 "F:/Research/ezAMI/AMI",
                                                 tr("project files(*.ezproj)"));
    QDir dir = QFileInfo(fullFileName).absoluteDir();
    projectDir = dir.absolutePath();
    QString fileName = QFileInfo(fullFileName).fileName();
    projectName = fileName.split(".").value(0);
    QStringList projectFileList({projectName,projectDir});
    if(projectArch)
        delete projectArch;

    projectArch = new projectTreeModel(this,projectFileList, false);
    emit(projectArchtoCompiler(projectArch));

    ui->projectTreeView->setModel(projectArch);
    ui->projectTreeView->expandAll();


}

void MainWindow:: on_projectTreeView_doubleClicked(const QModelIndex &index)
{
    projectTreeItem *item = static_cast<projectTreeItem*>(index.internalPointer());
    QString fileName = item->data(1).toString();
    QFile file(fileName);
    if (file.exists())
    {
        file.open(QIODevice::ReadOnly| QIODevice::Text);
        QTextStream in(&file);
        ui->myCode->clear();
        ui->codeArea->setTabText(0,item->data(0).toString());
        ui->myCode->append(in.readAll());
        ui->myCode->setFont(QFont("Courier", 8));
    }
}

void MainWindow::onCustomContextMenu(const QPoint &point)
{
    treeItemToModify = ui->projectTreeView->indexAt(point);
        if (treeItemToModify.isValid()) {
            projectTreeItem *item = static_cast<projectTreeItem*>(treeItemToModify.internalPointer());
            if(item->data(0) != "Source Code")
                contextMenuNewAction->setEnabled(false);
            else
            {
                contextMenuNewAction->setEnabled(true);
            }
            if(item->data(0) == "Source Code" || item->data(0) == "Resource")
            {
                contextMenu->exec(ui->projectTreeView->viewport()->mapToGlobal(point));
                return;
            }
            if(item->childCount() == 0 && item->data(0) != "Excutable" && item->data(0) != "AMI Model")
            {
                contextMenu->exec(ui->projectTreeView->viewport()->mapToGlobal(point));
                return;
            }

        }
}

void MainWindow::setupContextMenu(void)
{
   contextMenu = new QMenu(this);
   contextMenuNewAction = new QAction(contextMenu);
   contextMenuNewAction->setObjectName(QString::fromUtf8("New"));
   contextMenuNewAction->setText(QString::fromUtf8("Add New"));
   contextMenuAddAction= new QAction(contextMenu);
   contextMenuAddAction->setObjectName(QString::fromUtf8("Add"));
   contextMenuAddAction->setText(QString::fromUtf8("Add Exist"));
   contextMenuCopyAction= new QAction(contextMenu);
   contextMenuCopyAction->setObjectName(QString::fromUtf8("Copy"));
   contextMenuCopyAction->setText(QString::fromUtf8("Copy"));
   contextMenuPasteAction= new QAction(contextMenu);
   contextMenuPasteAction->setObjectName(QString::fromUtf8("Paste"));
   contextMenuPasteAction->setText(QString::fromUtf8("Paste"));
   contextMenuDeleteAction= new QAction(contextMenu);
   contextMenuDeleteAction->setObjectName(QString::fromUtf8("Delete"));
   contextMenuDeleteAction->setText(QString::fromUtf8("Delete"));

   contextMenu->addAction(contextMenuNewAction);
   contextMenu->addAction(contextMenuAddAction);
   //contextMenu->addAction(contextMenuCopyAction);
   //contextMenu->addAction(contextMenuPasteAction);
   contextMenu->addAction(contextMenuDeleteAction);
}


void MainWindow::on_actionProject_triggered()
{
    newProjectDlg->show();
}

void MainWindow::on_actionClose_Project_triggered()
{
    saveProjectFile();
    ui->projectTreeView->setModel(new projectTreeModel());
}

void MainWindow::setProjectInfo(const QHash<QString, QString> &projInfo)
{

    projectDir = projInfo.value("Path");
    projectName = projInfo.value("Name");
    QStringList pathList;
    pathList<<projectName<<projectDir;

    QString path = projectDir+ "/" + projectName+".ezproj";
    if(!projectArch)
        delete projectArch;
    projectArch = new projectTreeModel(ui->projectTreeView, pathList, true);
    emit(projectArchtoCompiler(projectArch));
    ui->projectTreeView->setModel(projectArch);

    QFile file(path);

    if(!file.exists())
    {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << "Software Version: ezAMI1.0"<<endl<<endl<<endl<<endl;
            QModelIndex projectRoot = projectArch->getProjectRoot();

            projectTreeItem *projectRootItem = projectRoot.isValid()? static_cast<projectTreeItem*>(projectRoot.internalPointer()) : nullptr;
            if(projectRootItem)
            {
                out<<" " <<"\t"<<projectRootItem->data(0).toString()<<"\t"<<projectRootItem->data(1).toString()<<endl;
                out<<"root"<<"\t"<<projectRootItem->child(0)->data(0).toString()<<"\t"<<projectRootItem->child(0)->data(1).toString()<<endl;
                projectTreeItem *sourceCode = projectRootItem->child(1);
                out<<"source code"<<"\t"<<sourceCode->data(0).toString()<<"\t"<<sourceCode->data(1).toString()<<endl;
                int count = sourceCode->childCount();
                if(count)
                {
                    for (auto i = 0; i < count; i++)
                    {
                        out<<"source code"<<"\t"<<"source code"<<"\t"<<sourceCode->child(i)->data(0).toString() <<"\t"<<sourceCode->child(i)->data(1).toString();
                        out<<endl;
                    }
                }

                projectTreeItem *excutable = projectRootItem->child(2);
                out<<"excutable"<<"\t"<<excutable->data(0).toString()<<"\t"<<excutable->data(1).toString()<<endl;
                count = excutable->childCount();
                if(count)
                {
                    for (auto i = 0; i < count; i++)
                    {
                        out<<"excutable"<<"\t"<<"excutable"<<"\t"<<excutable->child(i)->data(0).toString() <<"\t"<<excutable->child(i)->data(1).toString();
                        out<<endl;
                    }
                }

                projectTreeItem *amiModel = projectRootItem->child(3);
                out<<"ami model"<<"\t"<<amiModel->data(0).toString()<<"\t"<<amiModel->data(1).toString()<<endl;

                count = amiModel->childCount();
                if(count)
                {
                    for (auto i = 0; i < count; i++)
                    {
                        out<<"ami model"<<"\t"<<"ami model"<<"\t"<<amiModel->child(i)->data(0).toString() <<"\t"<<amiModel->child(i)->data(1).toString();
                        out<<endl;
                    }
                }

                projectTreeItem *resource = projectRootItem->child(4);
                out<<"resource"<<"\t"<<resource->data(0).toString()<<"\t"<<resource->data(1).toString()<<endl;
                count = resource->childCount();
                if(count)
                {
                    for (auto i = 0; i < count; i++)
                    {
                        out<<"resource"<<"\t"<<"resource"<<"\t"<<resource->child(i)->data(0).toString() <<"\t"<<resource->child(i)->data(1).toString();
                        out<<endl;
                    }
                }
            }
        }
    }
}


void  MainWindow::on_CustomContextMenu_triggered(QAction *action)
{
     projectTreeItem *rightClickedItem = nullptr;
    if(treeItemToModify.isValid())
    {
        rightClickedItem = static_cast<projectTreeItem*>(treeItemToModify.internalPointer());
    }

    if(action == contextMenuNewAction)
    {
        if(rightClickedItem && rightClickedItem->data(0) == "Source Code")
        {
            QString newFile = QFileDialog::getSaveFileName(this,tr("New File Name"), projectDir,tr("Source Files (*.cpp *.h)"));
            if (newFile.isNull())
                return;

            QString fname = QFileInfo(newFile).fileName();


            QFile file(newFile);
            file.open(QIODevice::ReadWrite | QIODevice::Text);
            QTextStream in(&file);
            ui->myCode->clear();
            ui->codeArea->setTabText(0,fname);
            ui->myCode->append(in.readAll());
            ui->myCode->setFont(QFont("Courier", 8));
            file.close();



            rightClickedItem->appendChild(new projectTreeItem({QVariant(fname), QVariant(newFile)}, rightClickedItem));
            ui->projectTreeView->reset();
            ui->projectTreeView->expandAll();

        }
    }

    if(action == contextMenuAddAction)
    {
        if(rightClickedItem && rightClickedItem->data(0) == "Source Code" )
        {
            QString newFile = QFileDialog::getOpenFileName(this,tr("Choose file to add"), projectDir,tr("Source Files (*.cpp *.h)"));
            if (newFile.isNull())
                return;
            QString fname = QFileInfo(newFile).fileName();

            QFile file(newFile);
            file.open(QIODevice::ReadWrite | QIODevice::Text);
            QTextStream in(&file);
            ui->myCode->clear();
            ui->codeArea->setTabText(0,fname);
            ui->myCode->append(in.readAll());
            ui->myCode->setFont(QFont("Courier", 8));
            file.close();

            rightClickedItem->appendChild(new projectTreeItem({QVariant(fname), QVariant(newFile)}, rightClickedItem));
            ui->projectTreeView->reset();
            ui->projectTreeView->expandAll();

        }

        if(rightClickedItem &&  rightClickedItem->data(0) == "Resource")
        {
            QString newFile = QFileDialog::getOpenFileName(this,tr("Choose file to add"), projectDir,tr("Text File (*.txt)"));
            if (newFile.isNull())
                return;
            QString fname = QFileInfo(newFile).fileName();

            QFile file(newFile);
            file.open(QIODevice::ReadWrite | QIODevice::Text);
            QTextStream in(&file);
            ui->myCode->clear();
            ui->codeArea->setTabText(0,fname);
            ui->myCode->append(in.readAll());
            ui->myCode->setFont(QFont("Courier", 8));
            file.close();

            rightClickedItem->appendChild(new projectTreeItem({QVariant(fname), QVariant(newFile)}, rightClickedItem));
            ui->projectTreeView->reset();
            ui->projectTreeView->expandAll();

        }
    }

    if(action == contextMenuDeleteAction)
    {

        if(rightClickedItem && rightClickedItem->childCount() == 0)
        {
            QModelIndex parent = projectArch->parent(treeItemToModify);
            projectTreeItem* prntItem = static_cast<projectTreeItem*>(parent.internalPointer());
            int rowCount = prntItem->childCount();
            int row = rightClickedItem->row();
            if(parent.isValid())
                projectArch->removeRow(row, parent);
            rowCount = prntItem->childCount();
            ui->projectTreeView->reset();
            ui->projectTreeView->expandAll();
        }
    }
    emit(projectArchtoCompiler(projectArch));

}

bool MainWindow::saveProjectFile()
{
    if(projectDir.isNull())
    {
        QMessageBox::warning(this,"No project path set!", "Please create project first!", "ok");
        return false;
    }
    QString projectFilePath = projectDir + "/" + projectName + ".ezproj";

    QFile proj(projectFilePath);
    if (proj.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&proj);
        out << "Software Version: ezAMI1.0"<<endl<<endl<<endl<<endl;
        QModelIndex projectRoot = projectArch->getProjectRoot();

        projectTreeItem *projectRootItem = projectRoot.isValid()? static_cast<projectTreeItem*>(projectRoot.internalPointer()) : nullptr;
        if(projectRootItem)
        {
            out<<" " <<"\t"<<projectRootItem->data(0).toString()<<"\t"<<projectRootItem->data(1).toString()<<endl;
            out<<"root"<<"\t"<<projectRootItem->child(0)->data(0).toString()<<"\t"<<projectRootItem->child(0)->data(1).toString()<<endl;
            projectTreeItem *sourceCode = projectRootItem->child(1);
            out<<"source code"<<"\t"<<sourceCode->data(0).toString()<<"\t"<<sourceCode->data(1).toString()<<endl;
            int count = sourceCode->childCount();
            if(count)
            {
                for (auto i = 0; i < count; i++)
                {
                    out<<"source code"<<"\t"<<"source code"<<"\t"<<sourceCode->child(i)->data(0).toString() <<"\t"<<sourceCode->child(i)->data(1).toString();
                    out<<endl;
                }
            }

            projectTreeItem *excutable = projectRootItem->child(2);
            out<<"excutable"<<"\t"<<excutable->data(0).toString()<<"\t"<<excutable->data(1).toString()<<endl;
            count = excutable->childCount();
            if(count)
            {
                for (auto i = 0; i < count; i++)
                {
                    out<<"excutable"<<"\t"<<"excutable"<<"\t"<<excutable->child(i)->data(0).toString() <<"\t"<<excutable->child(i)->data(1).toString();
                    out<<endl;
                }
            }

            projectTreeItem *amiModel = projectRootItem->child(3);
            out<<"ami model"<<"\t"<<amiModel->data(0).toString()<<"\t"<<amiModel->data(1).toString()<<endl;

            count = amiModel->childCount();
            if(count)
            {
                for (auto i = 0; i < count; i++)
                {
                    out<<"ami model"<<"\t"<<"ami model"<<"\t"<<amiModel->child(i)->data(0).toString() <<"\t"<<amiModel->child(i)->data(1).toString();
                    out<<endl;
                }
            }

            projectTreeItem *resource = projectRootItem->child(4);
            out<<"resource"<<"\t"<<resource->data(0).toString()<<"\t"<<resource->data(1).toString()<<endl;
            count = resource->childCount();
            if(count)
            {
                for (auto i = 0; i < count; i++)
                {
                    out<<"resource"<<"\t"<<"resource"<<"\t"<<resource->child(i)->data(0).toString() <<"\t"<<resource->child(i)->data(1).toString();
                    out<<endl;
                }
            }
        }
    }
    return true;
}

bool MainWindow::saveCodeFile()
{
    //QString dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
    //                                             "F:/Research/ezAMI/AMI",
    //                                             QFileDialog::ShowDirsOnly
    //                                             | QFileDialog::DontResolveSymlinks);

    QString fileName = "ami.cpp";
    QString filePath = projectDir + "/" + fileName;

    QFile cFile(filePath);
    if(cFile.open(QIODevice::ReadWrite)){
        QTextStream stream(&cFile);
        stream<<ui->amiInit->toPlainText();
        stream<<endl;
        stream<<ui->amiGetWave->toPlainText();
        stream<<endl;
        stream<<ui->amiClose->toPlainText();

        cFile.flush();
        cFile.close();
    }
    else {
        QMessageBox::critical(this, tr("Error"), tr("Cannot Save in file"));
         return false;
    }


    QString userFileName = ui->codeArea->tabText(0);
    QString userFilePath = projectDir + "/" + userFileName;
    QFile usrFile(userFilePath);
    if(usrFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(&usrFile);
        stream<<ui->myCode->toPlainText();
        usrFile.flush();
        usrFile.close();
    }
    else {
        return false;
    }


  return true;
}

void MainWindow::on_actionClean_2_triggered()
{
    QDir projDir(projectDir);
    if (projDir.exists())
    {
        QStringList fileToDelete = projDir.entryList(QStringList()<<"*.dll"<<"*.obj"<<"*.lib", QDir::Files);
        for (auto it = fileToDelete.begin(); it != fileToDelete.end(); it++)
        {
            projDir.remove(*it);
        }
    }
    QDir amiDir(projectDir + "/x64/Release");

    if (amiDir.exists())
    {
        QStringList fileToDelete = amiDir.entryList(QStringList()<<"*.*", QDir::Files);
        for (auto it = fileToDelete.begin(); it != fileToDelete.end(); it++)
        {
            amiDir.remove(*it);
        }
    }
}

void MainWindow::on_actionLVFFN_triggered()
{
    QString fullFileName = "F:/Research/ezAMI/AMI/LVFFN.ezproj";
    QDir dir = QFileInfo(fullFileName).absoluteDir();
    projectDir = dir.absolutePath();
    QString fileName = QFileInfo(fullFileName).fileName();
    projectName = fileName.split(".").value(0);
    QStringList projectFileList({projectName,projectDir});
    if(projectArch)
        delete projectArch;

    projectArch = new projectTreeModel(this,projectFileList, false);
    emit(projectArchtoCompiler(projectArch));

    ui->projectTreeView->setModel(projectArch);
    ui->projectTreeView->expandAll();
}

void MainWindow::updateProjectTreeFromCompiler()
{
    QModelIndex projectRoot = projectArch->getProjectRoot();
    projectTreeItem *root = projectRoot.isValid()? static_cast<projectTreeItem*>(projectRoot.internalPointer()):nullptr;
    if(root)
    {
        //root->child(2)
    }

}
