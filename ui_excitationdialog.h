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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_excitationDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *excitationDialog)
    {
        if (excitationDialog->objectName().isEmpty())
            excitationDialog->setObjectName(QString::fromUtf8("excitationDialog"));
        excitationDialog->resize(418, 384);
        gridLayout = new QGridLayout(excitationDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(excitationDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(19);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(excitationDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);

        label_2 = new QLabel(excitationDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(23);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 2, 1);


        retranslateUi(excitationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), excitationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), excitationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(excitationDialog);
    } // setupUi

    void retranslateUi(QDialog *excitationDialog)
    {
        excitationDialog->setWindowTitle(QApplication::translate("excitationDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("excitationDialog", "Excitation Setting", nullptr));
        label_2->setText(QApplication::translate("excitationDialog", "Under Construction....", nullptr));
    } // retranslateUi

};

namespace Ui {
    class excitationDialog: public Ui_excitationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCITATIONDIALOG_H
