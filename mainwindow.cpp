/*
 *     <ezAMI: IBIS-AMI model generation tool>
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
    this->addToolBar(toolBar);

    ui->amiInit->setFont(QFont("Courier", 12));
    ui->amiGetWave->setFont(QFont("Courier", 12));
    ui->amiClose->setFont(QFont("Courier", 12));
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

    treeModel = new projectTreeModel(this);
    ui->projectTreeView->setModel(treeModel);

    ui->projectTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->projectTreeView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenu(const QPoint &)));


    connect(scene, SIGNAL(doubleClick(QPointF)), this, SLOT(on_doubleClicked(QPointF)));
    connect(excitationDlg, SIGNAL(excitationReady(QHash<QString, QString>)), plot, SLOT(coordinateSetup(QHash<QString, QString>)));
    connect(plot, SIGNAL(waveFormReady(QVector<qreal>*)), simulateEngine, SLOT(receiveInputWave(QVector<qreal> *)));
    connect(amiDlg, SIGNAL(filePath(QString)), simulateEngine, SLOT(setDllPath(QString)));
    connect(simulateEngine, SIGNAL(outputReady(QVector<qreal>*)), plot, SLOT(addSimulatedWave(QVector<qreal>*)));
    connect(ui->projectTreeView, SIGNAL(on_doubleClicked(QModelIndex)), this, SLOT(on_projectTreeView_doubleClicked(QMdodelIndex)));
    connect(newProjectDlg, SIGNAL(projectInfo(const QHash<QString, QString> &)), this, SLOT(setProjectInfo(const QHash<QString, QString> &)));

    setupContextMenu();

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

    delete treeModel;

    delete contextMenu;
    delete contextMenuNewAction;
    delete contextMenuAddAction;
    delete contextMenuCopyAction;
    delete contextMenuPasteAction;
    delete contextMenuDeleteAction;


}
//#define AMI_INIT
#define AMI_GETWAVE
//#define AMI_CLOSE
void MainWindow::on_simulateButton_clicked()
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
void MainWindow::on_generateAmiButton_clicked()
{


    generateDllDlg->show();


}


void MainWindow::on_compileButton_clicked()
{

    gccCompiler->show();

}

void MainWindow::on_saveButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                 "F:/Research/ezAMI/AMI",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    QString fileName = "ami.cpp";
    QString filePath = dir + "/" + fileName;

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
        ui->saveButton->setEnabled(false);
    }
    else {
        QMessageBox::critical(this, tr("Error"), tr("Cannot Save in file"));
         return;
    }

}

void MainWindow::drawExcitPlot()
{

}
void MainWindow::on_amiInit_textChanged()
{
    ui->saveButton->setEnabled(true);
}

void MainWindow::on_amiGetWave_textChanged()
{
    ui->saveButton->setEnabled(true);
}

void MainWindow::on_amiClose_textChanged()
{
    ui->saveButton->setEnabled(true);
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

bool MainWindow::isInRegion(QGraphicsItem *item, QPointF clickPos)
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("open project"),
                                                 "F:/Research/ezAMI/AMI",
                                                 tr("project files(*.txt *.ezproj)"));
    if(treeModel)
        delete treeModel;

    treeModel = new projectTreeModel(this, fileName);

    ui->projectTreeView->setModel(treeModel);
    ui->projectTreeView->expandAll();


}

void MainWindow:: on_projectTreeView_doubleClicked(const QModelIndex &index)
{
    projectTreeItem *item = static_cast<projectTreeItem*>(index.internalPointer());
    QString fileName = item->data(1).toString() + item->data(0).toString();
    QFile file(fileName);
    if (file.exists())
    {
        file.open(QIODevice::ReadOnly| QIODevice::Text);
        QTextStream in(&file);
        ui->myCode->clear();
        ui->codeArea->setTabText(0,item->data(0).toString());
        ui->myCode->append(in.readAll());
        ui->myCode->setFont(QFont("Courier", 12));
    }
}

void MainWindow::onCustomContextMenu(const QPoint &point)
{
    QModelIndex index = ui->projectTreeView->indexAt(point);
        if (index.isValid()) {
            contextMenu->exec(ui->projectTreeView->viewport()->mapToGlobal(point));
        }
}

void MainWindow::setupContextMenu(void)
{
   contextMenu = new QMenu(this);
   contextMenuNewAction = new QAction(contextMenu);
   contextMenuNewAction->setObjectName(QString::fromUtf8("New"));
   contextMenuNewAction->setText(QString::fromUtf8("New"));
   contextMenuAddAction= new QAction(contextMenu);
   contextMenuAddAction->setObjectName(QString::fromUtf8("Add"));
   contextMenuAddAction->setText(QString::fromUtf8("Add"));
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
   contextMenu->addAction(contextMenuCopyAction);
   contextMenu->addAction(contextMenuPasteAction);
   contextMenu->addAction(contextMenuDeleteAction);
}


void MainWindow::on_actionProject_triggered()
{
    newProjectDlg->show();
}

void MainWindow::setProjectInfo(const QHash<QString, QString> &projInfo)
{
    projectDir = projInfo.value("Path");
    projectName = projInfo.value("Name");
    QString path = projectDir+ "/" + projectName+".ezproj";

    QFile file(path);

    if(!file.exists())
    {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            file.write("hello ezAMI");

        }
    }


}
