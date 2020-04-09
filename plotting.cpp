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
#include <QLineF>
#include <stdlib.h>


plotting::plotting(QWidget *parent) :
    QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    markerLineY = new QVector<QGraphicsLineItem *>(10);
    markerLineX = new QVector<QGraphicsLineItem *>(10);
    scene = new QGraphicsScene (this);
    ui->graphicsView->setScene(scene);

    plotPoints = new QVector<QPointF>();
    plotSegments = new QVector<QGraphicsLineItem*>();
    waveForm = new QVector<qreal>();

    setupCor();
}

plotting::~plotting()
{
    delete ui;
   /* recheck this part because sometimes this code segment results in memory fault/leak*/
    delete plotPoints;
    delete plotSegments;
    delete scene;
    delete waveForm;
/*
    if(line)
        delete line;
    delete rect;
    delete ellips;
    delete text;
    delete markerLineY;
    delete markerLineX;
    */

}


void plotting::setupCor()
{

    qreal width = 550;
    qreal height = 350;

     QPen corPen(QColor(50,50,50));
     QPen corPenMarker(QColor(150,150,150));

     corPen.setWidth(3);
     corPenMarker.setWidth(1);
     corPenMarker.setStyle(Qt::DashLine);


     // YaxisText = new QVector<QGraphicsTextItem *> (10);
     //rect = scene->addRect(QRecF(0,0,100,100));
     QBrush brush,brush1;
     brush.setStyle(Qt::SolidPattern);
     brush.setColor(QColor(240,240,240));
     brush1.setStyle(Qt::SolidPattern);
     brush1.setColor(Qt::white);
     scene->setBackgroundBrush(brush);
     rect = scene->addRect(0,0,width,height,corPen);
     rect->setBrush(brush1);
     uchar i;
     for (i=0; i<10; i++)
     {


       if( i )
       {
           markerLineX->append(scene->addLine(55*i,0, 55*i, 350,corPenMarker));
           if (i == 5)
           {
               markerLineY->append(scene->addLine(0, 35*i, 550,35*i,corPen));
           }
           else
           {
               markerLineY->append(scene->addLine(0, 35*i, 550,35*i,corPenMarker));
           }

       }

       str = QString::number(1.5 - i * 0.3);
       YaxisText.append(scene->addText(str));
       YaxisText[i]->setPos(-30,i*35-10);
       str = QString::number((i+1));
       text = new QGraphicsTextItem(str);
       XaxisText10min.append(text);
       text->setPos((i+1)*55-10, 350);
       scene->addItem(XaxisText10min[i]);
     }
      YaxisText.append(scene->addText("-1.5"));
      YaxisText.last()->setPos(-30,340);

      text = scene->addText("Voltage(V)",QFont("Voltage(V)",10,QFont::Bold));
      text->setPos(-65,225);
      text->setRotation(270);
      text = scene->addText("Time(s)",QFont("Time(s)",10,QFont::Bold));
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

void plotting::coordinateSetup(QHash<QString, QString> excitationInfo)
{
    type = excitationInfo.value("Type");
    samplePerBit = excitationInfo.value("Number of Sample Per Bit").toInt();
    numberBit = excitationInfo.value("Total Bits").toLong();
    amplitude = excitationInfo.value("Amplitude").toDouble();
    offset = excitationInfo.value("Offset").toDouble();
    updatePlotPoints();
    updateCoor();
    emit waveFormReady(waveForm);
}

void plotting::updateCoor()
{
    QPen graphPen(Qt::blue);
    graphPen.setWidth(1);
    if(!plotSegments->isEmpty())
    {
        for(auto it = plotSegments->begin(); it != plotSegments->end(); it++)
            scene->removeItem(static_cast<QGraphicsItem*>(*it));
        scene->update();
        plotSegments->clear();
    }
    if(!plotPoints->isEmpty())
    {
        for(auto i= plotPoints->begin(); i != plotPoints->end() - 1; i ++)
            plotSegments->append(scene->addLine(QLineF(*i,*(i+1)), graphPen));
    }
}

void plotting::updatePlotPoints()
{
    qreal width = 550;
    qreal height = 350;
    qreal midHeight = height / 2;
    long totalSample = numberBit * samplePerBit;

    qreal sampleWidth = width / totalSample;
    qreal sampleHeight = midHeight * amplitude / 1.5;
    qreal pam4SampleHeight = midHeight * amplitude * 2 / 1.5 / 3;


    if(!plotPoints->isEmpty())
    {
        plotPoints->clear();
    }
    if(!waveForm->isEmpty())
    {
        waveForm->clear();
    }
    if (type == "NRZ")
    {
        for (auto i = 0; i < numberBit; i++)
        {
            if (rand()%2)
            {
                for(auto j = 0; j< samplePerBit; j++)
                {
                    //offset to be implemented later. Offset right now is just a absolute value
                    waveForm->append(amplitude);
                    plotPoints->append(QPointF((i*samplePerBit + j)*sampleWidth, midHeight  - sampleHeight));
                }
            }
            else
            {
                for(auto j = 0; j< samplePerBit; j++)
                {
                    plotPoints->append(QPointF((i*samplePerBit + j)*sampleWidth, midHeight + sampleHeight));
                    waveForm->append(-1*amplitude);
                }
            }
        }
    }
    if(type == "PAM4")
    {
        for (auto i = 0; i< numberBit; i++)
        {
            int number = rand()%4;
            switch(number)
            {
            case 0:
                for (auto j = 0; j < samplePerBit; j++)
                {
                     waveForm->append(-1*amplitude);
                    plotPoints->append(QPointF((i*samplePerBit + j)*sampleWidth, midHeight + pam4SampleHeight * 1.5));
                }
                break;
            case 1:
                for (auto j = 0; j < samplePerBit; j++)
                {
                    waveForm->append(-1* amplitude / 3);
                    plotPoints->append(QPointF((i*samplePerBit + j)*sampleWidth, midHeight + pam4SampleHeight * 0.5));
                }
                break;
            case 2:
                for (auto j = 0; j < samplePerBit; j++)
                {
                    waveForm->append(amplitude / 3);
                    plotPoints->append(QPointF((i*samplePerBit + j)*sampleWidth, midHeight - pam4SampleHeight * 0.5));
                }
                break;
            case 3:
                for (auto j = 0; j < samplePerBit; j++)
                {
                    waveForm->append( amplitude );
                    plotPoints->append(QPointF((i*samplePerBit + j)*sampleWidth, midHeight - pam4SampleHeight * 1.5));
                }
                break;

         }
     }
    }


}
