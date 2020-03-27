#include "excitationdialog.h"
#include "ui_excitationdialog.h"
#include <QIcon>
#include <QRandomGenerator>
#include <stdlib.h>

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
    userSineValue = new QHash<QString, qreal>();
    userSineUnit = new QHash<QString, QString>();

    updateHash();
    setupCoordinate();
    drawWave();


}

excitationDialog::~excitationDialog()
{
    delete ui;
    delete scene;

    delete userPRBSValue;
    delete userPRBSUnit;
    delete userSineValue;
    delete userSineUnit;

}

void excitationDialog::updateHash()
{
    userPRBSValue->insert("Data Rate", ui->dataRateInput->text().toDouble());
    userPRBSValue->insert("Sample Interval", ui->timeIntervalInput->text().toDouble());
    userPRBSValue->insert("Length", ui->lengthInput->text().toDouble());
    userPRBSValue->insert("Amplitude", ui->amplitudeInput->text().toDouble());
    userPRBSValue->insert("Offset", ui->offsetInput->text().toDouble());

    userPRBSUnit->insert("Data Rate", ui->DataRatecomboBox->currentData().toString());
    userPRBSUnit->insert("Sample Interval", ui->timeIntervalComboBox->currentData().toString());
    userPRBSUnit->insert("Length", ui->lengthComboBox->currentData().toString());
    userPRBSUnit->insert("Amplitude", ui->AmplitudeComboBox->currentData().toString());
    userPRBSUnit->insert("Offset", ui->offsetComboBox->currentData().toString());

    userSineValue->insert("Amplitude", ui->amplitudeSineInput->text().toDouble());
    userSineValue->insert("Offset", ui->offsetSineInput->text().toDouble());
    userSineValue->insert("Frequency", ui->FrequencyInput->text().toDouble());
    userSineValue->insert("Sample Interval", ui->timeIntervalSineInput->text().toDouble());
    userSineValue->insert("Length", ui->lengthSineInput->text().toDouble());


    userSineUnit->insert("Amplitude", ui->AmplitudeSineComboBox->currentData().toString());
    userSineUnit->insert("Offset", ui->offsetSineComboBox->currentData().toString());
    userSineUnit->insert("Frequency", ui->FrequencyComboBox->currentData().toString());
    userSineUnit->insert("Sample Interval", ui->timeIntervalSineComboBox->currentData().toString());
    userSineUnit->insert("Length", ui->lengthSineComboBox->currentData().toString());
}


void excitationDialog::on_buttonBox_accepted()
{
    updateHash();
}

void excitationDialog::getSamples()
{
    if(ui->prbsRadioButton->isChecked())
    {

        QString dataRateUnit = userPRBSUnit->value("Data Rate");
        if(dataRateUnit == "GBPS")
        {
            if (userPRBSUnit->value("Sample Interval") == "ps")
            {
                samplePerUnitLength = static_cast<int> (userPRBSValue->value("Data Rate")/
                                                        userPRBSValue->value("Sample Interval") * 1e3);
            }
            if(userPRBSUnit->value("Length") == "s")
            {
                numberBit = static_cast<int>(userPRBSValue->value("Data Rate")/userPRBSValue->value("Length") * 1e9);
            }
            if(userPRBSUnit->value("Length") == "ms")
            {
                numberBit = static_cast<int>(userPRBSValue->value("Data Rate")/userPRBSValue->value("Length") * 1e6);
            }
            if(userPRBSUnit->value("Length") == "us")
            {
                numberBit = static_cast<int>(userPRBSValue->value("Data Rate")/userPRBSValue->value("Length") * 1e3);
            }

        }
    }
}

void excitationDialog::setupCoordinate()
{
   qreal width = ui->displayView->width();
   qreal height = ui->displayView->height();

   QPen corPen(QColor(0,0,0));

   corPen.setWidth(3);

   scene = new QGraphicsScene (this);
   ui->displayView->setScene(scene);

   xaxis = scene->addLine(50,height/2, width - 100, height/2, corPen);
   yaxis = scene->addLine(50, 25, 50,height - 25, corPen );
   scene->addLine(50,25, 55,30, corPen);
   scene->addLine(50,25, 45,30, corPen);
   scene->addLine(width - 99,height/2, width - 105,height/2 + 5, corPen);
   scene->addLine(width - 99,height/2, width - 105,height/2 - 5, corPen);
   for (auto i = 1; i < 10; i++)
   {

         scene->addLine(50 + i * (width - 150) / 10 ,height/2, 50 + i * (width - 150) / 10 ,height/2 - 5, corPen);
   }

}

void excitationDialog::drawWave()
{
    qreal width = ui->displayView->width();
    qreal height = ui->displayView->height();
    QPen wavePen(QColor(0,0,0));

    wavePen.setWidth(2);

    if(ui->prbsRadioButton->isChecked())
    {
        qreal bits = userPRBSValue->value("Data Rate")*10;
        qreal bitWidth = (width - 150) / bits;
        bool flag = false;
        if(!prbs.isEmpty())
        {
            for(auto it = prbs.begin(); it!= prbs.end(); ++it)
            {
                scene->removeItem((QGraphicsItem*)it);
            }
        }

        for (auto i = 0; i < static_cast<int>(bits) ; i ++ )
        {
            if(i == 0)
            {
                if((flag = rand()%2))
                {
                    prbs.append(scene->addLine(50 + i * bitWidth, height / 4,
                                               50 + (i +1) * bitWidth, height / 4,wavePen));
                }
                else
                {
                    prbs.append(scene->addLine(50 + i * bitWidth, height * 3 / 4,
                                               50 + (i +1) * bitWidth, height * 3  / 4,wavePen));
                }

            }
            else
            {
                if (rand()%2)
                {
                     prbs.append(scene->addLine(50 + i * bitWidth, height / 4,
                                                50 + (i +1) * bitWidth, height / 4,wavePen));
                     if(!flag)
                         prbs.append(scene->addLine(50 + i * bitWidth, height / 4,
                                                    50 + i * bitWidth, height * 3 / 4,wavePen));
                     flag = true;
                }
                else
                {
                    prbs.append(scene->addLine(50 + i * bitWidth, height * 3 / 4,
                                               50 + (i +1) * bitWidth, height * 3  / 4,wavePen));
                    if(flag)
                        prbs.append(scene->addLine(50 + i * bitWidth, height * 3  / 4,
                                                   50 + i * bitWidth, height / 4,wavePen));
                    flag = false;
                }
            }

        }
    }

}




void excitationDialog::on_dataRateInput_textEdited(const QString &arg1)
{
    updateHash();
    drawWave();
}
