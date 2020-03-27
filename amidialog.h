#ifndef AMIDIALOG_H
#define AMIDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QtCore>
#include <QVector>
#include "ui_amidialog.h"

namespace Ui {
class AMI_Dialog;
}


class amiDialog:public QDialog
{
    Q_OBJECT
public:
    explicit amiDialog(QWidget *parent = nullptr);
    ~amiDialog();
private slots:
    void on_browseButton_clicked();
    void setText();

signals:
    void filePath();

private:
    Ui::AMI_Dialog *ui;
};

#endif // AMIDIALOG_H
