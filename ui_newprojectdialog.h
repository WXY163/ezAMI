/********************************************************************************
** Form generated from reading UI file 'newprojectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTDIALOG_H
#define UI_NEWPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_newProjectDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pathLabel;
    QLineEdit *pathLineEdit;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;

    void setupUi(QDialog *newProjectDialog)
    {
        if (newProjectDialog->objectName().isEmpty())
            newProjectDialog->setObjectName(QString::fromUtf8("newProjectDialog"));
        newProjectDialog->resize(400, 300);
        gridLayout = new QGridLayout(newProjectDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(newProjectDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 7, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pathLabel = new QLabel(newProjectDialog);
        pathLabel->setObjectName(QString::fromUtf8("pathLabel"));
        QFont font;
        font.setPointSize(12);
        pathLabel->setFont(font);

        horizontalLayout_2->addWidget(pathLabel);

        pathLineEdit = new QLineEdit(newProjectDialog);
        pathLineEdit->setObjectName(QString::fromUtf8("pathLineEdit"));

        horizontalLayout_2->addWidget(pathLineEdit);

        toolButton = new QToolButton(newProjectDialog);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout_2->addWidget(toolButton);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(newProjectDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);


        gridLayout->addLayout(horizontalLayout_3, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nameLabel = new QLabel(newProjectDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setFont(font);

        horizontalLayout->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(newProjectDialog);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        horizontalLayout->addWidget(nameLineEdit);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 3);


        retranslateUi(newProjectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), newProjectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newProjectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(newProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *newProjectDialog)
    {
        newProjectDialog->setWindowTitle(QApplication::translate("newProjectDialog", "Dialog", nullptr));
        pathLabel->setText(QApplication::translate("newProjectDialog", "Project Path", nullptr));
        toolButton->setText(QApplication::translate("newProjectDialog", "...", nullptr));
        label->setText(QApplication::translate("newProjectDialog", "Create Project", nullptr));
        nameLabel->setText(QApplication::translate("newProjectDialog", "Project Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newProjectDialog: public Ui_newProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTDIALOG_H
