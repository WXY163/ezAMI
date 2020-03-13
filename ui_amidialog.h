/********************************************************************************
** Form generated from reading UI file 'amidialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMIDIALOG_H
#define UI_AMIDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AMI_Dialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *AMI_Dialog)
    {
        if (AMI_Dialog->objectName().isEmpty())
            AMI_Dialog->setObjectName(QString::fromUtf8("AMI_Dialog"));
        AMI_Dialog->resize(400, 300);
        gridLayout = new QGridLayout(AMI_Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(AMI_Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        label = new QLabel(AMI_Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(AMI_Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AMI_Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AMI_Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AMI_Dialog);
    } // setupUi

    void retranslateUi(QDialog *AMI_Dialog)
    {
        AMI_Dialog->setWindowTitle(QApplication::translate("AMI_Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("AMI_Dialog", "Under Construction", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AMI_Dialog: public Ui_AMI_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMIDIALOG_H
