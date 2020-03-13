#include "plotdialog.h"
#include "ui_plotdialog.h"
#include <QIcon>

plotDialog::plotDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plotDialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("img/preferences.png"));
}

plotDialog::~plotDialog()
{
    delete ui;
}
