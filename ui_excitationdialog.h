/********************************************************************************
** Form generated from reading UI file 'excitationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCITATIONDIALOG_H
#define UI_EXCITATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_excitationDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QFrame *PRBS_form;
    QLabel *dataRateLabel;
    QLineEdit *dataRateInput;
    QComboBox *DataRatecomboBox;
    QLineEdit *timeIntervalInput;
    QComboBox *timeIntervalComboBox;
    QLabel *timeIntervalLabel;
    QLineEdit *lengthInput;
    QComboBox *lengthComboBox;
    QLabel *lengthLabel;
    QLabel *prbsTitle;
    QRadioButton *prbsRadioButton;
    QLabel *AmplitudeLabel;
    QLineEdit *amplitudeInput;
    QComboBox *AmplitudeComboBox;
    QComboBox *offsetComboBox;
    QLineEdit *offsetInput;
    QLabel *offsetLabel;
    QFrame *Sine_form;
    QLabel *sineWaveLabel;
    QRadioButton *sineWaveRadioButton;
    QLineEdit *amplitudeSineInput;
    QLineEdit *offsetSineInput;
    QLabel *offsetSineLabel;
    QLabel *AmplitudeSineLabel;
    QComboBox *offsetSineComboBox;
    QComboBox *AmplitudeSineComboBox;
    QLineEdit *FrequencyInput;
    QLabel *FrequencyLabel;
    QComboBox *FrequencyComboBox;
    QLabel *timeISinentervalLabel;
    QLabel *lengthSineLabel;
    QComboBox *lengthSineComboBox;
    QComboBox *timeIntervalSineComboBox;
    QLineEdit *timeIntervalSineInput;
    QLineEdit *lengthSineInput;
    QDialogButtonBox *buttonBox;
    QFrame *WaveForm;
    QGraphicsView *displayView;

    void setupUi(QDialog *excitationDialog)
    {
        if (excitationDialog->objectName().isEmpty())
            excitationDialog->setObjectName(QString::fromUtf8("excitationDialog"));
        excitationDialog->resize(545, 438);
        gridLayout = new QGridLayout(excitationDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PRBS_form = new QFrame(excitationDialog);
        PRBS_form->setObjectName(QString::fromUtf8("PRBS_form"));
        PRBS_form->setFrameShape(QFrame::StyledPanel);
        PRBS_form->setFrameShadow(QFrame::Sunken);
        PRBS_form->setLineWidth(4);
        PRBS_form->setMidLineWidth(4);
        dataRateLabel = new QLabel(PRBS_form);
        dataRateLabel->setObjectName(QString::fromUtf8("dataRateLabel"));
        dataRateLabel->setGeometry(QRect(10, 40, 71, 16));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        dataRateLabel->setFont(font);
        dataRateInput = new QLineEdit(PRBS_form);
        dataRateInput->setObjectName(QString::fromUtf8("dataRateInput"));
        dataRateInput->setGeometry(QRect(110, 40, 51, 21));
        DataRatecomboBox = new QComboBox(PRBS_form);
        DataRatecomboBox->addItem(QString());
        DataRatecomboBox->addItem(QString());
        DataRatecomboBox->setObjectName(QString::fromUtf8("DataRatecomboBox"));
        DataRatecomboBox->setGeometry(QRect(180, 40, 51, 22));
        timeIntervalInput = new QLineEdit(PRBS_form);
        timeIntervalInput->setObjectName(QString::fromUtf8("timeIntervalInput"));
        timeIntervalInput->setGeometry(QRect(110, 70, 51, 20));
        timeIntervalComboBox = new QComboBox(PRBS_form);
        timeIntervalComboBox->addItem(QString());
        timeIntervalComboBox->addItem(QString());
        timeIntervalComboBox->setObjectName(QString::fromUtf8("timeIntervalComboBox"));
        timeIntervalComboBox->setGeometry(QRect(180, 70, 51, 22));
        timeIntervalLabel = new QLabel(PRBS_form);
        timeIntervalLabel->setObjectName(QString::fromUtf8("timeIntervalLabel"));
        timeIntervalLabel->setGeometry(QRect(10, 70, 91, 16));
        timeIntervalLabel->setFont(font);
        lengthInput = new QLineEdit(PRBS_form);
        lengthInput->setObjectName(QString::fromUtf8("lengthInput"));
        lengthInput->setGeometry(QRect(110, 100, 51, 20));
        lengthComboBox = new QComboBox(PRBS_form);
        lengthComboBox->addItem(QString());
        lengthComboBox->addItem(QString());
        lengthComboBox->addItem(QString());
        lengthComboBox->addItem(QString());
        lengthComboBox->setObjectName(QString::fromUtf8("lengthComboBox"));
        lengthComboBox->setGeometry(QRect(180, 100, 51, 22));
        lengthLabel = new QLabel(PRBS_form);
        lengthLabel->setObjectName(QString::fromUtf8("lengthLabel"));
        lengthLabel->setGeometry(QRect(10, 100, 71, 16));
        lengthLabel->setFont(font);
        prbsTitle = new QLabel(PRBS_form);
        prbsTitle->setObjectName(QString::fromUtf8("prbsTitle"));
        prbsTitle->setGeometry(QRect(110, 10, 41, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        prbsTitle->setFont(font1);
        prbsRadioButton = new QRadioButton(PRBS_form);
        prbsRadioButton->setObjectName(QString::fromUtf8("prbsRadioButton"));
        prbsRadioButton->setGeometry(QRect(80, 10, 21, 20));
        AmplitudeLabel = new QLabel(PRBS_form);
        AmplitudeLabel->setObjectName(QString::fromUtf8("AmplitudeLabel"));
        AmplitudeLabel->setGeometry(QRect(10, 130, 71, 16));
        AmplitudeLabel->setFont(font);
        amplitudeInput = new QLineEdit(PRBS_form);
        amplitudeInput->setObjectName(QString::fromUtf8("amplitudeInput"));
        amplitudeInput->setGeometry(QRect(110, 130, 51, 20));
        AmplitudeComboBox = new QComboBox(PRBS_form);
        AmplitudeComboBox->addItem(QString());
        AmplitudeComboBox->addItem(QString());
        AmplitudeComboBox->addItem(QString());
        AmplitudeComboBox->setObjectName(QString::fromUtf8("AmplitudeComboBox"));
        AmplitudeComboBox->setGeometry(QRect(180, 130, 51, 22));
        offsetComboBox = new QComboBox(PRBS_form);
        offsetComboBox->addItem(QString());
        offsetComboBox->addItem(QString());
        offsetComboBox->setObjectName(QString::fromUtf8("offsetComboBox"));
        offsetComboBox->setGeometry(QRect(180, 160, 51, 22));
        offsetInput = new QLineEdit(PRBS_form);
        offsetInput->setObjectName(QString::fromUtf8("offsetInput"));
        offsetInput->setGeometry(QRect(110, 160, 51, 20));
        offsetLabel = new QLabel(PRBS_form);
        offsetLabel->setObjectName(QString::fromUtf8("offsetLabel"));
        offsetLabel->setGeometry(QRect(10, 160, 71, 16));
        offsetLabel->setFont(font);

        horizontalLayout_3->addWidget(PRBS_form);

        Sine_form = new QFrame(excitationDialog);
        Sine_form->setObjectName(QString::fromUtf8("Sine_form"));
        Sine_form->setFrameShape(QFrame::StyledPanel);
        Sine_form->setFrameShadow(QFrame::Sunken);
        Sine_form->setLineWidth(4);
        Sine_form->setMidLineWidth(4);
        sineWaveLabel = new QLabel(Sine_form);
        sineWaveLabel->setObjectName(QString::fromUtf8("sineWaveLabel"));
        sineWaveLabel->setGeometry(QRect(80, 10, 101, 21));
        sineWaveLabel->setFont(font1);
        sineWaveRadioButton = new QRadioButton(Sine_form);
        sineWaveRadioButton->setObjectName(QString::fromUtf8("sineWaveRadioButton"));
        sineWaveRadioButton->setGeometry(QRect(50, 10, 21, 20));
        amplitudeSineInput = new QLineEdit(Sine_form);
        amplitudeSineInput->setObjectName(QString::fromUtf8("amplitudeSineInput"));
        amplitudeSineInput->setGeometry(QRect(120, 40, 51, 20));
        offsetSineInput = new QLineEdit(Sine_form);
        offsetSineInput->setObjectName(QString::fromUtf8("offsetSineInput"));
        offsetSineInput->setGeometry(QRect(120, 70, 51, 20));
        offsetSineLabel = new QLabel(Sine_form);
        offsetSineLabel->setObjectName(QString::fromUtf8("offsetSineLabel"));
        offsetSineLabel->setGeometry(QRect(20, 70, 71, 16));
        offsetSineLabel->setFont(font);
        AmplitudeSineLabel = new QLabel(Sine_form);
        AmplitudeSineLabel->setObjectName(QString::fromUtf8("AmplitudeSineLabel"));
        AmplitudeSineLabel->setGeometry(QRect(20, 40, 71, 16));
        AmplitudeSineLabel->setFont(font);
        offsetSineComboBox = new QComboBox(Sine_form);
        offsetSineComboBox->addItem(QString());
        offsetSineComboBox->addItem(QString());
        offsetSineComboBox->setObjectName(QString::fromUtf8("offsetSineComboBox"));
        offsetSineComboBox->setGeometry(QRect(190, 70, 51, 22));
        AmplitudeSineComboBox = new QComboBox(Sine_form);
        AmplitudeSineComboBox->addItem(QString());
        AmplitudeSineComboBox->addItem(QString());
        AmplitudeSineComboBox->setObjectName(QString::fromUtf8("AmplitudeSineComboBox"));
        AmplitudeSineComboBox->setGeometry(QRect(190, 40, 51, 22));
        FrequencyInput = new QLineEdit(Sine_form);
        FrequencyInput->setObjectName(QString::fromUtf8("FrequencyInput"));
        FrequencyInput->setGeometry(QRect(120, 100, 51, 21));
        FrequencyLabel = new QLabel(Sine_form);
        FrequencyLabel->setObjectName(QString::fromUtf8("FrequencyLabel"));
        FrequencyLabel->setGeometry(QRect(20, 100, 71, 16));
        FrequencyLabel->setFont(font);
        FrequencyComboBox = new QComboBox(Sine_form);
        FrequencyComboBox->addItem(QString());
        FrequencyComboBox->addItem(QString());
        FrequencyComboBox->addItem(QString());
        FrequencyComboBox->setObjectName(QString::fromUtf8("FrequencyComboBox"));
        FrequencyComboBox->setGeometry(QRect(190, 100, 51, 22));
        timeISinentervalLabel = new QLabel(Sine_form);
        timeISinentervalLabel->setObjectName(QString::fromUtf8("timeISinentervalLabel"));
        timeISinentervalLabel->setGeometry(QRect(20, 130, 91, 16));
        timeISinentervalLabel->setFont(font);
        lengthSineLabel = new QLabel(Sine_form);
        lengthSineLabel->setObjectName(QString::fromUtf8("lengthSineLabel"));
        lengthSineLabel->setGeometry(QRect(20, 160, 71, 16));
        lengthSineLabel->setFont(font);
        lengthSineComboBox = new QComboBox(Sine_form);
        lengthSineComboBox->addItem(QString());
        lengthSineComboBox->addItem(QString());
        lengthSineComboBox->addItem(QString());
        lengthSineComboBox->addItem(QString());
        lengthSineComboBox->setObjectName(QString::fromUtf8("lengthSineComboBox"));
        lengthSineComboBox->setGeometry(QRect(190, 160, 51, 22));
        timeIntervalSineComboBox = new QComboBox(Sine_form);
        timeIntervalSineComboBox->addItem(QString());
        timeIntervalSineComboBox->addItem(QString());
        timeIntervalSineComboBox->addItem(QString());
        timeIntervalSineComboBox->addItem(QString());
        timeIntervalSineComboBox->setObjectName(QString::fromUtf8("timeIntervalSineComboBox"));
        timeIntervalSineComboBox->setGeometry(QRect(190, 130, 51, 22));
        timeIntervalSineInput = new QLineEdit(Sine_form);
        timeIntervalSineInput->setObjectName(QString::fromUtf8("timeIntervalSineInput"));
        timeIntervalSineInput->setGeometry(QRect(120, 130, 51, 20));
        lengthSineInput = new QLineEdit(Sine_form);
        lengthSineInput->setObjectName(QString::fromUtf8("lengthSineInput"));
        lengthSineInput->setGeometry(QRect(120, 160, 51, 20));

        horizontalLayout_3->addWidget(Sine_form);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(excitationDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        WaveForm = new QFrame(excitationDialog);
        WaveForm->setObjectName(QString::fromUtf8("WaveForm"));
        WaveForm->setFrameShape(QFrame::StyledPanel);
        WaveForm->setFrameShadow(QFrame::Raised);
        displayView = new QGraphicsView(WaveForm);
        displayView->setObjectName(QString::fromUtf8("displayView"));
        displayView->setGeometry(QRect(0, 0, 521, 191));

        gridLayout->addWidget(WaveForm, 2, 0, 1, 1);


        retranslateUi(excitationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), excitationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), excitationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(excitationDialog);
    } // setupUi

    void retranslateUi(QDialog *excitationDialog)
    {
        excitationDialog->setWindowTitle(QApplication::translate("excitationDialog", "Dialog", nullptr));
        dataRateLabel->setText(QApplication::translate("excitationDialog", "Data Rate", nullptr));
        dataRateInput->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        DataRatecomboBox->setItemText(0, QApplication::translate("excitationDialog", "GBPS", nullptr));
        DataRatecomboBox->setItemText(1, QApplication::translate("excitationDialog", "BPS", nullptr));

        timeIntervalInput->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        timeIntervalComboBox->setItemText(0, QApplication::translate("excitationDialog", "ps", nullptr));
        timeIntervalComboBox->setItemText(1, QApplication::translate("excitationDialog", "ns", nullptr));

        timeIntervalLabel->setText(QApplication::translate("excitationDialog", "Sample Interval", nullptr));
        lengthInput->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        lengthComboBox->setItemText(0, QApplication::translate("excitationDialog", "us", nullptr));
        lengthComboBox->setItemText(1, QApplication::translate("excitationDialog", "ns", nullptr));
        lengthComboBox->setItemText(2, QApplication::translate("excitationDialog", "ms", nullptr));
        lengthComboBox->setItemText(3, QApplication::translate("excitationDialog", "s", nullptr));

        lengthLabel->setText(QApplication::translate("excitationDialog", "Length", nullptr));
        prbsTitle->setText(QApplication::translate("excitationDialog", "PRBS", nullptr));
        prbsRadioButton->setText(QString());
        AmplitudeLabel->setText(QApplication::translate("excitationDialog", "Amplitude", nullptr));
        amplitudeInput->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        AmplitudeComboBox->setItemText(0, QApplication::translate("excitationDialog", "V", nullptr));
        AmplitudeComboBox->setItemText(1, QApplication::translate("excitationDialog", "mV", nullptr));
        AmplitudeComboBox->setItemText(2, QApplication::translate("excitationDialog", "uV", nullptr));

        offsetComboBox->setItemText(0, QApplication::translate("excitationDialog", "V", nullptr));
        offsetComboBox->setItemText(1, QApplication::translate("excitationDialog", "mV", nullptr));

        offsetInput->setText(QApplication::translate("excitationDialog", "0.0", nullptr));
        offsetLabel->setText(QApplication::translate("excitationDialog", "Offset", nullptr));
        sineWaveLabel->setText(QApplication::translate("excitationDialog", "Sine Wave", nullptr));
        sineWaveRadioButton->setText(QString());
        amplitudeSineInput->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        offsetSineInput->setText(QApplication::translate("excitationDialog", "0.0", nullptr));
        offsetSineLabel->setText(QApplication::translate("excitationDialog", "Offset", nullptr));
        AmplitudeSineLabel->setText(QApplication::translate("excitationDialog", "Amplitude", nullptr));
        offsetSineComboBox->setItemText(0, QApplication::translate("excitationDialog", "V", nullptr));
        offsetSineComboBox->setItemText(1, QApplication::translate("excitationDialog", "mV", nullptr));

        AmplitudeSineComboBox->setItemText(0, QApplication::translate("excitationDialog", "V", nullptr));
        AmplitudeSineComboBox->setItemText(1, QApplication::translate("excitationDialog", "mV", nullptr));

        FrequencyInput->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        FrequencyLabel->setText(QApplication::translate("excitationDialog", "Frequency", nullptr));
        FrequencyComboBox->setItemText(0, QApplication::translate("excitationDialog", "GHz", nullptr));
        FrequencyComboBox->setItemText(1, QApplication::translate("excitationDialog", "KHz", nullptr));
        FrequencyComboBox->setItemText(2, QApplication::translate("excitationDialog", "Hz", nullptr));

        timeISinentervalLabel->setText(QApplication::translate("excitationDialog", "Sample Interval", nullptr));
        lengthSineLabel->setText(QApplication::translate("excitationDialog", "Length", nullptr));
        lengthSineComboBox->setItemText(0, QApplication::translate("excitationDialog", "us", nullptr));
        lengthSineComboBox->setItemText(1, QApplication::translate("excitationDialog", "ns", nullptr));
        lengthSineComboBox->setItemText(2, QApplication::translate("excitationDialog", "ms", nullptr));
        lengthSineComboBox->setItemText(3, QApplication::translate("excitationDialog", "s", nullptr));

        timeIntervalSineComboBox->setItemText(0, QApplication::translate("excitationDialog", "ps", nullptr));
        timeIntervalSineComboBox->setItemText(1, QApplication::translate("excitationDialog", "ns", nullptr));
        timeIntervalSineComboBox->setItemText(2, QApplication::translate("excitationDialog", "us", nullptr));
        timeIntervalSineComboBox->setItemText(3, QApplication::translate("excitationDialog", "s", nullptr));

        timeIntervalSineInput->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        lengthSineInput->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class excitationDialog: public Ui_excitationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCITATIONDIALOG_H
