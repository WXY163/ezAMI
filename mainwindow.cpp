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
    ui->checkBox->setEnabled(false);
    toolBar->addAction(ui->actionExcitation);
    toolBar->addAction(ui->actionAMI);
    toolBar->addAction(ui->actionPlot);
    this->addToolBar(toolBar);

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

    connect(scene, SIGNAL(doubleClick(QPointF)), this, SLOT(on_doubleClicked(QPointF)));
    connect(excitationDlg, SIGNAL(excitationReady(QHash<QString, QString>)), plot, SLOT(coordinateSetup(QHash<QString, QString>)));
    connect(plot, SIGNAL(waveFormReady(QVector<qreal>*)), this, SLOT(receiveWaveForm(QVector<qreal> *)));
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
    delete scene;

}
//#define AMI_INIT
#define AMI_GETWAVE
//#define AMI_CLOSE
void MainWindow::on_simulateButton_clicked()
{

    if (QLibrary::isLibrary("ami.dll")) {
          ui->statusWindow->append("Simulation is running...");
          QLibrary lib("ami.dll");
          lib.load();
          if (!lib.isLoaded()) {
            qDebug() << lib.errorString();
          }

          if (lib.isLoaded()) {

            ui->statusWindow->append("success");
#ifdef AMI_GETWAVE
            typedef long (*FunctionPrototype) (double *wave,
                                               long wave_size,
                                               long aggressors,
                                               double *clock_times,
                                               char **AMI_parameters_out,
                                               void *AMI_memory);
            FunctionPrototype AMI_GetWave = (FunctionPrototype) lib.resolve("AMI_GetWave");
            if(AMI_GetWave)
            {
                long wave_size = waveForm->size();
                double *wave = new double [wave_size];
                for (auto i = 0 ; i < wave_size; i++)
                {
                    wave[i] = waveForm->value(i);
                }
                long aggressors = 0;
                double *clock_times = nullptr;
                char **AMI_parameters_out = nullptr;
                void *AMI_memory = nullptr;

                long result = AMI_GetWave(wave, wave_size, aggressors, clock_times, AMI_parameters_out,AMI_memory);
                ui->statusWindow->append(QString::number(result));
                for (auto i = 0; i < 10; i++)
                    ui->statusWindow->append(QString::number(wave[i]));
                delete [] wave;
            }
            else {
                ui->statusWindow->append("Cannot use GetWave function Add in dll");
            }
            lib.unload(); 

          }
    }
#endif

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
    ui->statusWindow->append(QString::number(result));
}
else {
     ui->statusWindow->append("Cannot use add function Add in dll");
}

}
    }
    #endif
}
void MainWindow::on_generateAmiButton_clicked()
{


    generateDllDlg->show();
    ui->statusWindow->append("generating AMI model (*.dll *.ami)");


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
    //ui->statusWindow->append(QString::number(pitem->boundingRect().width()));
    eaLine->setLine(QLineF(pt1, pt2));
    eaLine->setData(1, QVariant("Line"));

    scene->addItem(pitem);
    scene->addItem(eaLine);
    scene->addItem(exItem);

     ui->diagramWindow->fitInView(ui->diagramWindow->sceneRect(),Qt::KeepAspectRatio);
     ui->checkBox->setEnabled(true);
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
        ui->checkBox->setEnabled(true);
        ui->checkBox->setChecked(true);
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
        ui->checkBox->setEnabled(true);
        ui->checkBox->setChecked(true);
    }
    else
    {
        if(!ui->checkBox->isChecked())
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

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked())
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


void MainWindow::receiveWaveForm(QVector<qreal> *sample)
{
    if(sample)
    {
        waveForm = sample;
        if(waveForm->isEmpty())
        {
            QMessageBox::critical(this,"error", "No sample received!", "ok");
        }
    }

    else {
        QMessageBox::critical(this,"error", "receive waveform failed!", "ok");
    }


}
