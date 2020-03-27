#include "amidialog.h"


amiDialog::amiDialog(QWidget *parent):QDialog (parent)
{
    Ui::AMI_Dialog *ui = new Ui::AMI_Dialog;
    ui->setupUi(this);
    this->setWindowIcon(QIcon("img/preferences.png"));
    this->setWindowTitle("AMI Model");
}

amiDialog::~amiDialog()
{
    //delete ui;
}
