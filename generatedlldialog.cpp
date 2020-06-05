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


void generateDllDialog::dllGenerateStatus(const QString &stdOut, const QString &stdErr)
{
    ui->compileTextBrowser->append(stdErr);
    ui->compileTextBrowser->append(stdOut);
}

void generateDllDialog::on_GeneratePushButton_clicked()
{
    emit generateDll();
}

void generateDllDialog::on_ClosePushButton_clicked()
{
    //check this if there is bug
    this->close();
}

void generateDllDialog::generateAmiFile()
{

}
