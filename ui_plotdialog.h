/********************************************************************************
** Form generated from reading UI file 'plotdilog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTDIALOG_H
#define UI_PLOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_plotDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *plotDialog)
    {
        if (plotDialog->objectName().isEmpty())
            plotDialog->setObjectName(QString::fromUtf8("plotDilog"));
        plotDialog->resize(569, 476);
        gridLayout = new QGridLayout(plotDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(plotDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(plotDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 32, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(plotDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(152, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);


        retranslateUi(plotDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), plotDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), plotDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(plotDialog);
    } // setupUi

    void retranslateUi(QDialog *plotDilog)
    {
        plotDilog->setWindowTitle(QApplication::translate("plotDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("plotDialog", "Plot Settings", nullptr));
        label_2->setText(QApplication::translate("plotDialog", "Under Construction", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plotDialog: public Ui_plotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTDILOG_H
