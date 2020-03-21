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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_excitationDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox_3;
    QLabel *label_3;
    QLabel *label_4;
    QRadioButton *radioButton;
    QFrame *frame_3;
    QLabel *label_5;
    QRadioButton *radioButton_2;
    QFrame *frame_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *excitationDialog)
    {
        if (excitationDialog->objectName().isEmpty())
            excitationDialog->setObjectName(QString::fromUtf8("excitationDialog"));
        excitationDialog->resize(520, 430);
        gridLayout = new QGridLayout(excitationDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(excitationDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame = new QFrame(excitationDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 71, 16));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 50, 51, 21));
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(180, 50, 41, 22));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 80, 51, 20));
        comboBox_2 = new QComboBox(frame);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(180, 80, 41, 22));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 91, 16));
        label_2->setFont(font);
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 110, 51, 20));
        comboBox_3 = new QComboBox(frame);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(180, 110, 41, 22));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 71, 16));
        label_3->setFont(font);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 10, 61, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        radioButton = new QRadioButton(frame);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(60, 10, 21, 20));

        horizontalLayout_3->addWidget(frame);

        frame_3 = new QFrame(excitationDialog);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 10, 101, 21));
        label_5->setFont(font1);
        radioButton_2 = new QRadioButton(frame_3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(50, 10, 21, 20));

        horizontalLayout_3->addWidget(frame_3);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        frame_2 = new QFrame(excitationDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        textEdit = new QTextEdit(frame_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 501, 181));

        gridLayout->addWidget(frame_2, 2, 0, 1, 1);


        retranslateUi(excitationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), excitationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), excitationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(excitationDialog);
    } // setupUi

    void retranslateUi(QDialog *excitationDialog)
    {
        excitationDialog->setWindowTitle(QApplication::translate("excitationDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("excitationDialog", "Data Rate", nullptr));
        label_2->setText(QApplication::translate("excitationDialog", "Time Interval", nullptr));
        label_3->setText(QApplication::translate("excitationDialog", "Length", nullptr));
        label_4->setText(QApplication::translate("excitationDialog", "PRBS", nullptr));
        radioButton->setText(QString());
        label_5->setText(QApplication::translate("excitationDialog", "Sine Wave", nullptr));
        radioButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class excitationDialog: public Ui_excitationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCITATIONDIALOG_H
