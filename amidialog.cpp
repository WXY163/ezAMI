#include "amidialog.h"
#include <QFileDialog>


amiDialog::amiDialog(QWidget *parent):QDialog (parent), ui(new Ui::AMI_Dialog)
{

    ui->setupUi(this);
    this->setWindowIcon(QIcon("img/preferences.png"));
    this->setWindowTitle("AMI Model");


    //emit filePath();

}

amiDialog::~amiDialog()
{
    delete ui;
}

void amiDialog::on_browseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select DLL"), "F:/Research/ezAMI/AMI/",
            tr("DLLs (*.dll)"));
    ui->lineEdit->setText(fileName);
    emit filePath(fileName);
}

void amiDialog::setText()
{

}

