#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"
#include <QFileDialog>
#include <QDir>

newProjectDialog::newProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newProjectDialog)
{
    ui->setupUi(this);
}

newProjectDialog::~newProjectDialog()
{
    delete ui;
}

void newProjectDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if((QPushButton*)button == ui->buttonBox->button(QDialogButtonBox::Ok))
    {
        QString projectName = ui->nameLineEdit->text().toLatin1();
        if (projectName.isEmpty())
        {
            QMessageBox::critical(this,tr("Empty project name!"), tr("Please input project name!"), "Ok");
            return;
        }
        projectHash.insert("Name", projectName);
        QString projectPath = ui->pathLineEdit->text();
        if (projectName.isEmpty())
        {
            QMessageBox::critical(this,tr("Empty project path!"), tr("Please input project path!"), "Ok");
            return;
        }
        projectHash.insert("Path", projectPath);
        emit projectInfo(projectHash);
    }
    if((QPushButton*)button == ui->buttonBox->button(QDialogButtonBox::Cancel))
    {
        this->close();
    }
}

void newProjectDialog::on_toolButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"),
                                                 QDir::currentPath(),
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    ui->pathLineEdit->setText(dir);
}
