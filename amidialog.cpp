#include "amidialog.h"


amiDialog::amiDialog(QWidget *parent):QDialog (parent)
{
    Ui::AMI_Dialog *ui = new Ui::AMI_Dialog;
    ui->setupUi(this);
    this->setWindowIcon(QIcon("img/preferences.png"));
}

amiDialog::~amiDialog()
{
    delete ui;
}
