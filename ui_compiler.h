/********************************************************************************
** Form generated from reading UI file 'compiler.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPILER_H
#define UI_COMPILER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Compiler_Dialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *gccPathLabel;
    QLineEdit *gccPathLineEdit;
    QToolButton *gccPathToolButton;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *AMIPushButton;
    QPushButton *buildPushButton;
    QPushButton *closePushButton;

    void setupUi(QDialog *Compiler_Dialog)
    {
        if (Compiler_Dialog->objectName().isEmpty())
            Compiler_Dialog->setObjectName(QString::fromUtf8("Compiler_Dialog"));
        Compiler_Dialog->resize(479, 391);
        gridLayout = new QGridLayout(Compiler_Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(16, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBox = new QCheckBox(Compiler_Dialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QFont font;
        font.setPointSize(10);
        checkBox->setFont(font);
        checkBox->setChecked(true);
        checkBox->setTristate(false);

        horizontalLayout->addWidget(checkBox);

        horizontalSpacer_3 = new QSpacerItem(25, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        gccPathLabel = new QLabel(Compiler_Dialog);
        gccPathLabel->setObjectName(QString::fromUtf8("gccPathLabel"));
        QFont font1;
        font1.setPointSize(12);
        gccPathLabel->setFont(font1);

        horizontalLayout->addWidget(gccPathLabel);

        gccPathLineEdit = new QLineEdit(Compiler_Dialog);
        gccPathLineEdit->setObjectName(QString::fromUtf8("gccPathLineEdit"));

        horizontalLayout->addWidget(gccPathLineEdit);

        gccPathToolButton = new QToolButton(Compiler_Dialog);
        gccPathToolButton->setObjectName(QString::fromUtf8("gccPathToolButton"));

        horizontalLayout->addWidget(gccPathToolButton);


        verticalLayout_3->addLayout(horizontalLayout);

        frame = new QFrame(Compiler_Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 1);


        verticalLayout_3->addWidget(frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        AMIPushButton = new QPushButton(Compiler_Dialog);
        AMIPushButton->setObjectName(QString::fromUtf8("AMIPushButton"));

        horizontalLayout_2->addWidget(AMIPushButton);

        buildPushButton = new QPushButton(Compiler_Dialog);
        buildPushButton->setObjectName(QString::fromUtf8("buildPushButton"));

        horizontalLayout_2->addWidget(buildPushButton);

        closePushButton = new QPushButton(Compiler_Dialog);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));

        horizontalLayout_2->addWidget(closePushButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 3, 0, 1, 1);


        retranslateUi(Compiler_Dialog);

        QMetaObject::connectSlotsByName(Compiler_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Compiler_Dialog)
    {
        Compiler_Dialog->setWindowTitle(QApplication::translate("Compiler_Dialog", "Dialog", nullptr));
#ifndef QT_NO_WHATSTHIS
        Compiler_Dialog->setWhatsThis(QApplication::translate("Compiler_Dialog", "<html><head/><body><p>Building Environment</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("Compiler_Dialog", "General GCC", nullptr));
        gccPathLabel->setText(QApplication::translate("Compiler_Dialog", "gcc path", nullptr));
        gccPathToolButton->setText(QApplication::translate("Compiler_Dialog", "...", nullptr));
        AMIPushButton->setText(QApplication::translate("Compiler_Dialog", "AMI", nullptr));
        buildPushButton->setText(QApplication::translate("Compiler_Dialog", "Build", nullptr));
        closePushButton->setText(QApplication::translate("Compiler_Dialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Compiler_Dialog: public Ui_Compiler_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPILER_H
