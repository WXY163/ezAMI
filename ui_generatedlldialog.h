/********************************************************************************
** Form generated from reading UI file 'generatedlldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEDLLDIALOG_H
#define UI_GENERATEDLLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_generateDllDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *GeneratePushButton;
    QPushButton *ClosePushButton;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QFrame *frame_3;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QTextBrowser *compileTextBrowser;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QFrame *frame_5;
    QGridLayout *gridLayout_5;
    QLabel *label_7;
    QRadioButton *radioButton_10;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_13;
    QFrame *frame_6;
    QGridLayout *gridLayout_6;
    QLabel *label_9;
    QTextBrowser *usrParaTextBrowser;

    void setupUi(QDialog *generateDllDialog)
    {
        if (generateDllDialog->objectName().isEmpty())
            generateDllDialog->setObjectName(QString::fromUtf8("generateDllDialog"));
        generateDllDialog->resize(736, 517);
        gridLayout = new QGridLayout(generateDllDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        GeneratePushButton = new QPushButton(generateDllDialog);
        GeneratePushButton->setObjectName(QString::fromUtf8("GeneratePushButton"));

        horizontalLayout->addWidget(GeneratePushButton);

        ClosePushButton = new QPushButton(generateDllDialog);
        ClosePushButton->setObjectName(QString::fromUtf8("ClosePushButton"));

        horizontalLayout->addWidget(ClosePushButton);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(generateDllDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(4);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        gridLayout_4->addWidget(label, 0, 1, 1, 1);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QFont font1;
        font1.setPointSize(4);
        frame_3->setFont(font1);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Sunken);
        frame_3->setLineWidth(4);
        gridLayout_2 = new QGridLayout(frame_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setPointSize(12);
        label_3->setFont(font2);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(frame_3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setFont(font2);

        gridLayout_2->addWidget(radioButton_2, 1, 0, 1, 1);

        radioButton = new QRadioButton(frame_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setFont(font2);
        radioButton->setChecked(true);

        gridLayout_2->addWidget(radioButton, 2, 0, 1, 1);


        gridLayout_4->addWidget(frame_3, 1, 0, 1, 1);

        compileTextBrowser = new QTextBrowser(frame);
        compileTextBrowser->setObjectName(QString::fromUtf8("compileTextBrowser"));

        gridLayout_4->addWidget(compileTextBrowser, 1, 1, 1, 1);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(4);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);

        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFont(font1);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Sunken);
        frame_5->setLineWidth(4);
        gridLayout_5 = new QGridLayout(frame_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_7 = new QLabel(frame_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        gridLayout_5->addWidget(label_7, 0, 0, 1, 1);

        radioButton_10 = new QRadioButton(frame_5);
        radioButton_10->setObjectName(QString::fromUtf8("radioButton_10"));
        radioButton_10->setFont(font2);

        gridLayout_5->addWidget(radioButton_10, 1, 0, 1, 1);

        radioButton_9 = new QRadioButton(frame_5);
        radioButton_9->setObjectName(QString::fromUtf8("radioButton_9"));
        radioButton_9->setFont(font2);

        gridLayout_5->addWidget(radioButton_9, 2, 0, 1, 1);

        radioButton_13 = new QRadioButton(frame_5);
        radioButton_13->setObjectName(QString::fromUtf8("radioButton_13"));
        radioButton_13->setFont(font2);

        gridLayout_5->addWidget(radioButton_13, 3, 0, 1, 1);


        gridLayout_3->addWidget(frame_5, 1, 0, 1, 1);

        frame_6 = new QFrame(frame_2);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFont(font1);
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Sunken);
        frame_6->setLineWidth(4);
        gridLayout_6 = new QGridLayout(frame_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_9 = new QLabel(frame_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);

        gridLayout_6->addWidget(label_9, 0, 0, 1, 1);

        usrParaTextBrowser = new QTextBrowser(frame_6);
        usrParaTextBrowser->setObjectName(QString::fromUtf8("usrParaTextBrowser"));

        gridLayout_6->addWidget(usrParaTextBrowser, 1, 0, 1, 1);


        gridLayout_3->addWidget(frame_6, 1, 1, 1, 1);


        gridLayout_4->addWidget(frame_2, 2, 0, 1, 2);


        verticalLayout->addWidget(frame);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(generateDllDialog);

        QMetaObject::connectSlotsByName(generateDllDialog);
    } // setupUi

    void retranslateUi(QDialog *generateDllDialog)
    {
        generateDllDialog->setWindowTitle(QApplication::translate("generateDllDialog", "Dialog", nullptr));
        GeneratePushButton->setText(QApplication::translate("generateDllDialog", "Generate", nullptr));
        ClosePushButton->setText(QApplication::translate("generateDllDialog", "Close", nullptr));
        label->setText(QApplication::translate("generateDllDialog", ".dll settings", nullptr));
        label_3->setText(QApplication::translate("generateDllDialog", "Windows", nullptr));
        radioButton_2->setText(QApplication::translate("generateDllDialog", "x32", nullptr));
        radioButton->setText(QApplication::translate("generateDllDialog", "x64", nullptr));
        label_2->setText(QApplication::translate("generateDllDialog", ".ami Settings", nullptr));
        label_7->setText(QApplication::translate("generateDllDialog", "Default Parameters", nullptr));
        radioButton_10->setText(QApplication::translate("generateDllDialog", "AMI_Init return", nullptr));
        radioButton_9->setText(QApplication::translate("generateDllDialog", "AMI_Wave ", nullptr));
        radioButton_13->setText(QApplication::translate("generateDllDialog", "Bit Length", nullptr));
        label_9->setText(QApplication::translate("generateDllDialog", "User Parameters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class generateDllDialog: public Ui_generateDllDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEDLLDIALOG_H
