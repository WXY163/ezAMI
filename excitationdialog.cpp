#include "excitationdialog.h"
#include "ui_excitationdialog.h"
#include <QIcon>

excitationDialog::excitationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::excitationDialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("img/preferences.png"));
}

excitationDialog::~excitationDialog()
{
    delete ui;
}
