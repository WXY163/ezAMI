#include "generatedlldialog.h"
#include "ui_generatedlldialog.h"

generateDllDialog::generateDllDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::generateDllDialog)
{
    ui->setupUi(this);
}

generateDllDialog::~generateDllDialog()
{
    delete ui;
}
