#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"

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
