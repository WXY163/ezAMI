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
    QFrame *PAM4_form;
    QLabel *PAM4Label;
    QRadioButton *PAM4RadioButton;
    QLineEdit *dataRatePAM4Input;
    QLabel *dataRatePAM4Label;
    QComboBox *dataRatePAM4ComboBox;
    QLabel *timeIntervalPAM4Label;
    QLabel *lengthPAM4Label;
    QComboBox *lengthPAM4ComboBox;
    QComboBox *timeIntervalPAM4ComboBox;
    QLineEdit *timeIntervalPAM4Input;
    QLineEdit *lengthPAM4Input;
    QLabel *offsetPAM4Label;
    QComboBox *AmplitudePAM4ComboBox;
    QComboBox *offsetPAM4ComboBox;
    QLineEdit *amplitudePAM4Input;
    QLabel *AmplitudePAM4Label;
    QLineEdit *offsetPAM4Input;
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
        prbsTitle->setGeometry(QRect(110, 10, 91, 16));
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

        PAM4_form = new QFrame(excitationDialog);
        PAM4_form->setObjectName(QString::fromUtf8("PAM4_form"));
        PAM4_form->setFrameShape(QFrame::StyledPanel);
        PAM4_form->setFrameShadow(QFrame::Sunken);
        PAM4_form->setLineWidth(4);
        PAM4_form->setMidLineWidth(4);
        PAM4Label = new QLabel(PAM4_form);
        PAM4Label->setObjectName(QString::fromUtf8("PAM4Label"));
        PAM4Label->setGeometry(QRect(80, 10, 101, 21));
        PAM4Label->setFont(font1);
        PAM4RadioButton = new QRadioButton(PAM4_form);
        PAM4RadioButton->setObjectName(QString::fromUtf8("PAM4RadioButton"));
        PAM4RadioButton->setGeometry(QRect(50, 10, 21, 20));
        dataRatePAM4Input = new QLineEdit(PAM4_form);
        dataRatePAM4Input->setObjectName(QString::fromUtf8("dataRatePAM4Input"));
        dataRatePAM4Input->setGeometry(QRect(120, 40, 51, 21));
        dataRatePAM4Label = new QLabel(PAM4_form);
        dataRatePAM4Label->setObjectName(QString::fromUtf8("dataRatePAM4Label"));
        dataRatePAM4Label->setGeometry(QRect(20, 40, 71, 16));
        dataRatePAM4Label->setFont(font);
        dataRatePAM4ComboBox = new QComboBox(PAM4_form);
        dataRatePAM4ComboBox->addItem(QString());
        dataRatePAM4ComboBox->addItem(QString());
        dataRatePAM4ComboBox->setObjectName(QString::fromUtf8("dataRatePAM4ComboBox"));
        dataRatePAM4ComboBox->setGeometry(QRect(190, 40, 51, 22));
        timeIntervalPAM4Label = new QLabel(PAM4_form);
        timeIntervalPAM4Label->setObjectName(QString::fromUtf8("timeIntervalPAM4Label"));
        timeIntervalPAM4Label->setGeometry(QRect(20, 70, 91, 16));
        timeIntervalPAM4Label->setFont(font);
        lengthPAM4Label = new QLabel(PAM4_form);
        lengthPAM4Label->setObjectName(QString::fromUtf8("lengthPAM4Label"));
        lengthPAM4Label->setGeometry(QRect(20, 100, 71, 16));
        lengthPAM4Label->setFont(font);
        lengthPAM4ComboBox = new QComboBox(PAM4_form);
        lengthPAM4ComboBox->addItem(QString());
        lengthPAM4ComboBox->addItem(QString());
        lengthPAM4ComboBox->addItem(QString());
        lengthPAM4ComboBox->addItem(QString());
        lengthPAM4ComboBox->setObjectName(QString::fromUtf8("lengthPAM4ComboBox"));
        lengthPAM4ComboBox->setGeometry(QRect(190, 100, 51, 22));
        timeIntervalPAM4ComboBox = new QComboBox(PAM4_form);
        timeIntervalPAM4ComboBox->addItem(QString());
        timeIntervalPAM4ComboBox->setObjectName(QString::fromUtf8("timeIntervalPAM4ComboBox"));
        timeIntervalPAM4ComboBox->setGeometry(QRect(190, 70, 51, 22));
        timeIntervalPAM4Input = new QLineEdit(PAM4_form);
        timeIntervalPAM4Input->setObjectName(QString::fromUtf8("timeIntervalPAM4Input"));
        timeIntervalPAM4Input->setGeometry(QRect(120, 70, 51, 20));
        lengthPAM4Input = new QLineEdit(PAM4_form);
        lengthPAM4Input->setObjectName(QString::fromUtf8("lengthPAM4Input"));
        lengthPAM4Input->setGeometry(QRect(120, 100, 51, 20));
        offsetPAM4Label = new QLabel(PAM4_form);
        offsetPAM4Label->setObjectName(QString::fromUtf8("offsetPAM4Label"));
        offsetPAM4Label->setGeometry(QRect(20, 160, 71, 16));
        offsetPAM4Label->setFont(font);
        AmplitudePAM4ComboBox = new QComboBox(PAM4_form);
        AmplitudePAM4ComboBox->addItem(QString());
        AmplitudePAM4ComboBox->addItem(QString());
        AmplitudePAM4ComboBox->setObjectName(QString::fromUtf8("AmplitudePAM4ComboBox"));
        AmplitudePAM4ComboBox->setGeometry(QRect(190, 130, 51, 22));
        offsetPAM4ComboBox = new QComboBox(PAM4_form);
        offsetPAM4ComboBox->addItem(QString());
        offsetPAM4ComboBox->addItem(QString());
        offsetPAM4ComboBox->setObjectName(QString::fromUtf8("offsetPAM4ComboBox"));
        offsetPAM4ComboBox->setGeometry(QRect(190, 160, 51, 22));
        amplitudePAM4Input = new QLineEdit(PAM4_form);
        amplitudePAM4Input->setObjectName(QString::fromUtf8("amplitudePAM4Input"));
        amplitudePAM4Input->setGeometry(QRect(120, 130, 51, 20));
        AmplitudePAM4Label = new QLabel(PAM4_form);
        AmplitudePAM4Label->setObjectName(QString::fromUtf8("AmplitudePAM4Label"));
        AmplitudePAM4Label->setGeometry(QRect(20, 130, 71, 16));
        AmplitudePAM4Label->setFont(font);
        offsetPAM4Input = new QLineEdit(PAM4_form);
        offsetPAM4Input->setObjectName(QString::fromUtf8("offsetPAM4Input"));
        offsetPAM4Input->setGeometry(QRect(120, 160, 51, 20));

        horizontalLayout_3->addWidget(PAM4_form);


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

        timeIntervalInput->setText(QApplication::translate("excitationDialog", "100.0", nullptr));
        timeIntervalComboBox->setItemText(0, QApplication::translate("excitationDialog", "ps", nullptr));

        timeIntervalLabel->setText(QApplication::translate("excitationDialog", "Sample Interval", nullptr));
        lengthInput->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        lengthComboBox->setItemText(0, QApplication::translate("excitationDialog", "us", nullptr));
        lengthComboBox->setItemText(1, QApplication::translate("excitationDialog", "ns", nullptr));
        lengthComboBox->setItemText(2, QApplication::translate("excitationDialog", "ms", nullptr));
        lengthComboBox->setItemText(3, QApplication::translate("excitationDialog", "s", nullptr));

        lengthLabel->setText(QApplication::translate("excitationDialog", "Length", nullptr));
        prbsTitle->setText(QApplication::translate("excitationDialog", "PRBS-2 Level", nullptr));
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
        PAM4Label->setText(QApplication::translate("excitationDialog", "PRBS-4 Level", nullptr));
        PAM4RadioButton->setText(QString());
        dataRatePAM4Input->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        dataRatePAM4Label->setText(QApplication::translate("excitationDialog", "Data Rate", nullptr));
        dataRatePAM4ComboBox->setItemText(0, QApplication::translate("excitationDialog", "GBPS", nullptr));
        dataRatePAM4ComboBox->setItemText(1, QApplication::translate("excitationDialog", "BPS", nullptr));

        timeIntervalPAM4Label->setText(QApplication::translate("excitationDialog", "Sample Interval", nullptr));
        lengthPAM4Label->setText(QApplication::translate("excitationDialog", "Length", nullptr));
        lengthPAM4ComboBox->setItemText(0, QApplication::translate("excitationDialog", "us", nullptr));
        lengthPAM4ComboBox->setItemText(1, QApplication::translate("excitationDialog", "ns", nullptr));
        lengthPAM4ComboBox->setItemText(2, QApplication::translate("excitationDialog", "ms", nullptr));
        lengthPAM4ComboBox->setItemText(3, QApplication::translate("excitationDialog", "s", nullptr));

        timeIntervalPAM4ComboBox->setItemText(0, QApplication::translate("excitationDialog", "ps", nullptr));

        timeIntervalPAM4Input->setText(QApplication::translate("excitationDialog", "100.0", nullptr));
        lengthPAM4Input->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        offsetPAM4Label->setText(QApplication::translate("excitationDialog", "Offset", nullptr));
        AmplitudePAM4ComboBox->setItemText(0, QApplication::translate("excitationDialog", "V", nullptr));
        AmplitudePAM4ComboBox->setItemText(1, QApplication::translate("excitationDialog", "mV", nullptr));

        offsetPAM4ComboBox->setItemText(0, QApplication::translate("excitationDialog", "V", nullptr));
        offsetPAM4ComboBox->setItemText(1, QApplication::translate("excitationDialog", "mV", nullptr));

        amplitudePAM4Input->setText(QApplication::translate("excitationDialog", "1.0", nullptr));
        AmplitudePAM4Label->setText(QApplication::translate("excitationDialog", "Amplitude", nullptr));
        offsetPAM4Input->setText(QApplication::translate("excitationDialog", "0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class excitationDialog: public Ui_excitationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCITATIONDIALOG_H
