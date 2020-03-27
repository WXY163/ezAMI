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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AMI_Dialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AMI_Dialog)
    {
        if (AMI_Dialog->objectName().isEmpty())
            AMI_Dialog->setObjectName(QString::fromUtf8("AMI_Dialog"));
        AMI_Dialog->resize(400, 300);
        gridLayout = new QGridLayout(AMI_Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(AMI_Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(AMI_Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(AMI_Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        toolButton = new QToolButton(AMI_Dialog);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(AMI_Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(AMI_Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AMI_Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AMI_Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AMI_Dialog);
    } // setupUi

    void retranslateUi(QDialog *AMI_Dialog)
    {
        AMI_Dialog->setWindowTitle(QApplication::translate("AMI_Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("AMI_Dialog", "Link DLL to AMI model", nullptr));
        label_2->setText(QApplication::translate("AMI_Dialog", "DLL path", nullptr));
        toolButton->setText(QApplication::translate("AMI_Dialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AMI_Dialog: public Ui_AMI_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMIDIALOG_H
