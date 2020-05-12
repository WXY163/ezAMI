/*
 *     ezAMI: IBIS-AMI model generation tool
 *    Copyright (C) 2020
 *   Author: Xinying Wang (xinying@illinois.edu)
 *           Department of Electrical Computer Engineering
 *           University of Illinois at Urbana-Champaign
 *

 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
