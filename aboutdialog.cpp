#include "aboutdialog.h"
#include "ui_aboutdialog.h"

aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);
    ui->ezAMIicon->setPixmap(QPixmap("img/logo.svg"));
}

aboutDialog::~aboutDialog()
{
    delete ui;
}
