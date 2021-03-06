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


#include "excitationdialog.h"
#include "ui_excitationdialog.h"
#include <QIcon>
#include <QRandomGenerator>
#include <stdlib.h>
#include <QGraphicsTextItem>

excitationDialog::excitationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::excitationDialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("img/preferences.png"));
    this->setWindowTitle("Excitation");
    ui->prbsRadioButton->setChecked(true);
    userPRBSValue = new QHash<QString, qreal>();
    userPRBSUnit = new QHash<QString, QString>();
    userPAM4Value = new QHash<QString, qreal>();
    userPAM4Unit = new QHash<QString, QString>();

    prbs = new QVector<QGraphicsLineItem *>;

    excitateScene = new QGraphicsScene (this);

    updateHash();
    setupCoordinate();
    drawWave();


}

excitationDialog::~excitationDialog()
{
    delete ui;
    delete excitateScene;

    delete userPRBSValue;
    delete userPRBSUnit;
    delete userPAM4Value;
    delete userPAM4Unit;

    delete prbs;

}




void excitationDialog::on_buttonBox_accepted()
{
    updateHash();
    emit excitationReady(sampleInfo);
}


void excitationDialog::on_dataRateInput_textEdited()
{
    updateHash();
    drawWave();
}

void excitationDialog::on_amplitudeInput_textEdited()
{
    updateHash();
    drawWave();
}

void excitationDialog::on_offsetInput_textEdited()
{
    updateHash();
    drawWave();
}

void excitationDialog::on_dataRatePAM4Input_textEdited()
{
    updateHash();
    drawWave();
}

void excitationDialog::on_amplitudePAM4Input_textEdited()
{
    updateHash();
    drawWave();
}


void excitationDialog::on_offsetPAM4Input_textEdited()
{
    updateHash();
    drawWave();
}

void excitationDialog::on_prbsRadioButton_clicked(bool checked)
{
    if(checked)
    {
        ui->PAM4RadioButton->setChecked(false);
        updateHash();
        drawWave();
    }
}

void excitationDialog::on_PAM4RadioButton_clicked(bool checked)
{
    if(checked)
    {
        ui->prbsRadioButton->setChecked(false);
        updateHash();
        drawWave();
    }
}


void excitationDialog::updateHash()
{
    userPRBSValue->insert("Data Rate", ui->dataRateInput->text().toDouble());
    userPRBSValue->insert("Sample Per Bit", ui->samplePerBitInput->text().toDouble());
    userPRBSValue->insert("Number Of Bits", ui->numberOfBitsInput->text().toDouble());
    userPRBSValue->insert("Amplitude", ui->amplitudeInput->text().toDouble());
    userPRBSValue->insert("Offset", ui->offsetInput->text().toDouble());

    userPRBSUnit->insert("Data Rate", ui->DataRatecomboBox->currentText());
    userPRBSUnit->insert("Amplitude", ui->AmplitudeComboBox->currentText());
    userPRBSUnit->insert("Offset", ui->offsetComboBox->currentText());

    userPAM4Value->insert("Amplitude", ui->amplitudePAM4Input->text().toDouble());
    userPAM4Value->insert("Offset", ui->offsetPAM4Input->text().toDouble());
    userPAM4Value->insert("Data Rate", ui->dataRatePAM4Input->text().toDouble());
    userPAM4Value->insert("Sample Per Bit", ui->samplePerBitPAM4Input->text().toDouble());
    userPAM4Value->insert("Number Of Bits", ui->numberOfBitsPAM4Input->text().toDouble());


    userPAM4Unit->insert("Amplitude", ui->AmplitudePAM4ComboBox->currentText());
    userPAM4Unit->insert("Offset", ui->offsetPAM4ComboBox->currentText());
    userPAM4Unit->insert("Data Rate", ui->dataRatePAM4ComboBox->currentText());

    getSamples();
}
void excitationDialog::getSamples()
{
    if(ui->prbsRadioButton->isChecked())
    {

        QString dataRateUnit = userPRBSUnit->value("Data Rate");
        numberBit = static_cast<int>(userPRBSValue->value("Number Of Bits"));
        samplePerUnitLength = static_cast<int>(userPRBSValue->value("Sample Per Bit"));
        amplitude = userPRBSValue->value("Amplitude");
        offset = userPRBSValue->value("Offset");
        sampleInfo.insert("Type", "NRZ");
        sampleInfo.insert("Number of Sample Per Bit", QString::number(samplePerUnitLength));
        sampleInfo.insert("Total Bits", QString::number(numberBit));
        sampleInfo.insert("Amplitude", QString::number(amplitude));
        sampleInfo.insert("Offset", QString::number(offset));
    }
    if(ui->PAM4RadioButton->isChecked())
    {

        QString dataRateUnit = userPAM4Unit->value("Data Rate");
        samplePerUnitLength = static_cast<int>(userPAM4Value->value("Sample Per Bit"));
        numberBit = static_cast<int>(userPAM4Value->value("Number Of Bits"));
        amplitude = userPAM4Value->value("Amplitude");
        offset = userPAM4Value->value("Offset");
        sampleInfo.insert("Type", "PAM4");
        sampleInfo.insert("Number of Sample Per Bit", QString::number(samplePerUnitLength));
        sampleInfo.insert("Total Bits", QString::number(numberBit));
        sampleInfo.insert("Amplitude", QString::number(amplitude));
        sampleInfo.insert("Offset", QString::number(offset));
    }
}

void excitationDialog::setupCoordinate()
{
   qreal width = ui->displayView->width();
   qreal height = ui->displayView->height();
   qreal vmiddle = height / 2;
   qreal unitVoltage = height / 4;

   QPen corPen(QColor(0,0,0));

   corPen.setWidth(3);


   ui->displayView->setScene(excitateScene);

   xaxis = excitateScene->addLine(50,height/2, width - 100, height/2, corPen);
   yaxis = excitateScene->addLine(50, 25, 50,height - 25, corPen );
   excitateScene->addLine(50,25, 55,30, corPen);
   excitateScene->addLine(50,25, 45,30, corPen);
   excitateScene->addLine(width - 99,height/2, width - 105,height/2 + 5, corPen);
   excitateScene->addLine(width - 99,height/2, width - 105,height/2 - 5, corPen);
   for (auto i = 1; i < 10; i++)
   {

         excitateScene->addLine(50 + i * (width - 150) / 10 ,height/2, 50 + i * (width - 150) / 10 ,height/2 - 5, corPen);
   }
   excitateScene->addLine(50, vmiddle - unitVoltage, 45, vmiddle - unitVoltage, corPen);
   excitateScene->addLine(50, vmiddle + unitVoltage, 45, vmiddle + unitVoltage, corPen);

   QGraphicsTextItem *postiveVolt = excitateScene->addText("1.0 V");
   postiveVolt->setPos(15, vmiddle - unitVoltage - 10);
   QGraphicsTextItem *negtiveVolt = excitateScene->addText("-1.0 V");
    negtiveVolt->setPos(10, vmiddle + unitVoltage - 10);
}

void excitationDialog::drawWave()
{
    if(!prbs->isEmpty())
    {
        for(auto it = prbs->begin(); it!= prbs->end(); ++it)
        {
            excitateScene->removeItem((QGraphicsItem*)(*it));
        }
        prbs->clear();
    }

    if(ui->prbsRadioButton->isChecked())
    {
       pam2Draw();
    }
    if(ui->PAM4RadioButton->isChecked())
    {
        pam4Draw();
    }

}





void excitationDialog::pam2Draw()
{
    qreal width = ui->displayView->width();
    qreal height = ui->displayView->height();
    qreal vmiddle = height / 2;
    qreal unitVoltage = height / 4;

    QPen wavePen(Qt::blue);

    wavePen.setWidth(2);
    qreal bits = userPRBSValue->value("Data Rate")*10;
    qreal bitWidth = (width - 150) / bits;
    bool flag = false;

    for (auto i = 0; i < static_cast<int>(bits) ; i ++ )
    {
        if(i == 0)
        {
            if((flag = rand()%2))
            {
                prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle - unitVoltage * (amplitude + offset),
                                           50 + (i +1) * bitWidth, vmiddle - unitVoltage * (amplitude + offset),
                                                    wavePen));
            }
            else
            {
                prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + unitVoltage * ( amplitude - offset),
                                           50 + (i +1) * bitWidth, vmiddle + unitVoltage * (amplitude - offset),
                                                    wavePen));
            }

        }
        else
        {
            if (rand()%2)
            {
                 prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle - unitVoltage * (amplitude + offset),
                                            50 + (i +1) * bitWidth, vmiddle - unitVoltage * (amplitude + offset),
                                                     wavePen));
                 if(!flag)
                     prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle - unitVoltage * (amplitude + offset),
                                                50 + i * bitWidth, vmiddle + unitVoltage * (amplitude - offset),
                                                         wavePen));
                 flag = true;
            }
            else
            {
                prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + unitVoltage * (amplitude - offset),
                                           50 + (i +1) * bitWidth, vmiddle + unitVoltage * (amplitude - offset),
                                                    wavePen));
                if(flag)
                    prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + unitVoltage * (amplitude - offset),
                                                        50 + i * bitWidth, vmiddle - unitVoltage * (amplitude + offset),
                                                        wavePen));
                flag = false;
            }
        }

    }
}
void excitationDialog::pam4Draw()
{
    qreal width = ui->displayView->width();
    qreal height = ui->displayView->height();
    qreal vmiddle = height / 2;
    qreal unitVoltage = height / 4;
    qreal bitHeight = height / 6;

    QPen wavePen(Qt::blue);

    wavePen.setWidth(2);
    qreal bits = userPAM4Value->value("Data Rate")*10;
    qreal bitWidth = (width - 150) / bits;

    QVector<int> code;
    for (auto i = 0; i < static_cast<int>(bits) ; i ++ )
    {
        code.append(rand()%4);
        if(code.size() == 1)
        {
            switch (code[i])
            {
            case 0:
                prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + 1.5 * bitHeight * amplitude - unitVoltage * offset,
                                           50 + (i +1) * bitWidth, vmiddle + 1.5 * bitHeight * amplitude - unitVoltage * offset,
                                                    wavePen));

                break;
            case 1:
                prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + 0.5 * bitHeight * amplitude - unitVoltage * offset,
                                           50 + (i +1) * bitWidth, vmiddle + 0.5 * bitHeight * amplitude - unitVoltage * offset,
                                                    wavePen));

                break;
            case 2:
                prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle - (0.5 * bitHeight * amplitude + unitVoltage * offset),
                                           50 + (i +1) * bitWidth, vmiddle - (0.5 * bitHeight * amplitude + unitVoltage * offset),
                                                    wavePen));
                break;
            case 3:
                prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle - (1.5 * bitHeight * amplitude + unitVoltage * offset),
                                           50 + (i +1) * bitWidth, vmiddle - unitVoltage * (amplitude + offset),
                                                    wavePen));
                break;
            }
           }

         else
         {
                switch (code[i])
                {
                case 0:
                    prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + 1.5 * bitHeight * amplitude - unitVoltage * offset,
                                               50 + (i +1) * bitWidth, vmiddle + 1.5 * bitHeight * amplitude - unitVoltage * offset,
                                                        wavePen));
                    if (code[i] != code[i-1])
                        prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + amplitude * (height * 1 / 4 - code[i-1] * bitHeight)  - unitVoltage * offset,
                                                50 + i * bitWidth,  vmiddle + amplitude * (height * 1 / 4 - code[i] * bitHeight)  - unitVoltage * offset, wavePen));
                    break;
                case 1:
                    prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + 0.5 * bitHeight * amplitude - unitVoltage * offset,
                                               50 + (i +1) * bitWidth, vmiddle + 0.5 * bitHeight * amplitude - unitVoltage * offset,
                                                        wavePen));
                    if (code[i] != code[i-1])
                        prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + amplitude * (height * 1 / 4 - code[i-1] * bitHeight)  - unitVoltage * offset,
                                                50 + i * bitWidth,  vmiddle + amplitude * (height * 1 / 4 - code[i] * bitHeight)  - unitVoltage * offset, wavePen));
                    break;
                case 2:
                    prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle - (0.5 * bitHeight * amplitude + unitVoltage * offset),
                                               50 + (i +1) * bitWidth, vmiddle - (0.5 * bitHeight * amplitude + unitVoltage * offset),
                                                        wavePen));

                        if (code[i] != code[i-1])
                            prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + amplitude * (height * 1 / 4 - code[i-1] * bitHeight)  - unitVoltage * offset,
                                                    50 + i * bitWidth,  vmiddle + amplitude * (height * 1 / 4 - code[i] * bitHeight)  - unitVoltage * offset, wavePen));
                    break;
                case 3:
                    prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle - (1.5 * bitHeight * amplitude + unitVoltage * offset),
                                               50 + (i +1) * bitWidth, vmiddle - unitVoltage * (amplitude + offset),
                                                        wavePen));
                    if (code[i] != code[i-1])
                        prbs->append(excitateScene->addLine(50 + i * bitWidth, vmiddle + amplitude * (height * 1 / 4 - code[i-1] * bitHeight)  - unitVoltage * offset,
                                                50 + i * bitWidth,  vmiddle + amplitude * (height * 1 / 4 - code[i] * bitHeight)  - unitVoltage * offset, wavePen));
                    break;
                  }
            }


        }

}





