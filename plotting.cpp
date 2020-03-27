/*
 *     <ezAMI: IBIS-AMI model generation tool>
 *    Copyright (C) 2020
 *   Author: Xinying Wang (xinying@illinois.edu)
 *           Department of Electrical Computer Engineering
 *           University of Illinois at Urbana-Champaign
 *

 *   This program is a free software: you can redistribute it and/or modify
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


#include "plotting.h"
#include "ui_plotwindow.h"
#include <QTextStream>


plotting::plotting(QWidget *parent) :
    QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setupCor();




}

plotting::~plotting()
{
    delete ui;
}


void plotting::setupCor()
{
    scene = new QGraphicsScene (this);
    ui->graphicsView->setScene(scene);


     QPen corPen(QColor(50,50,50));
     QPen corPenMarker(QColor(150,150,150));

     corPen.setWidth(3);
     corPenMarker.setWidth(1.5);
     corPenMarker.setStyle(Qt::DashLine);

      markerLineY = new QVector<QGraphicsLineItem *>(10);
      markerLineX = new QVector<QGraphicsLineItem *>(10);
     // YaxisText = new QVector<QGraphicsTextItem *> (10);
     //rect = scene->addRect(QRecF(0,0,100,100));
     QBrush brush,brush1;
     brush.setStyle(Qt::SolidPattern);
     brush.setColor(QColor(240,240,240));
     brush1.setStyle(Qt::SolidPattern);
     brush1.setColor(Qt::white);
     scene->setBackgroundBrush(brush);
     rect = scene->addRect(0,0,550,350,corPen);
     rect->setBrush(brush1);
     uchar i;
     for (i=0; i<10; i++)
     {
       markerLineY->append(scene->addLine(0, 35*i, 550,35*i,corPenMarker));
       markerLineX->append(scene->addLine(55*i,0, 55*i, 350,corPenMarker));
       str = QString::number((10-i)*100);
       YaxisText.append(scene->addText(str));
       YaxisText[i]->setPos(-40,i*35-10);
       str = QString::number((i+1));
       text = new QGraphicsTextItem(str);
       XaxisText10min.append(text);
       text->setPos((i+1)*55-10, 350);
       scene->addItem(XaxisText10min[i]);
     }
      text = scene->addText("Voltage(mV)",QFont("Voltage(mV)",8,QFont::Bold));
      text->setPos(-65,225);
      text->setRotation(270);
      text = scene->addText("Time(s)",QFont("Time(s)",8,QFont::Bold));
      text->setPos(275,360);
}

void plotting::XaxisSetup(uchar min)
{

    uchar i;
    if(min == 10)
     {
        for (i=0;i<10;i++)
        {
            scene->removeItem(scene->itemAt(XaxisText10min[i]->pos(),XaxisText10min[i]->transform()));
            scene->addItem(XaxisText10min[i]);
        }


     }
}



void plotting::closeEvent(QCloseEvent *event)
{
    emit dialogClosed();
    event->accept();
}


void plotting::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button == ui->buttonBox->button(QDialogButtonBox::Ok))
    {
        this->close();
    }
    else
    {
        QString fn = QFileDialog::getSaveFileName(this, tr("Save file..."),"C://", "Text File (*.txt);;" );
        if(fn!="")
        {
            QFile file(fn);
            if(file.open(QFile::WriteOnly | QFile::Text))
            {
                QTextStream out(&file);
                out<<"Time(s)"<<'\t'<<"Voltage(mV)"<<endl;
             }
        }
    }
}
