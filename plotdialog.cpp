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

#include "plotdialog.h"
#include "ui_plotdialog.h"
#include <QIcon>
#include <QSysInfo>

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

void plotDialog::on_toolButton_clicked()
{
    ui->lineEdit->setText(QSysInfo::kernelVersion());
}
