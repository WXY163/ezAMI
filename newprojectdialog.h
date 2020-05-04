#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QHash>
#include <QMessageBox>

namespace Ui {
class newProjectDialog;
}

class newProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newProjectDialog(QWidget *parent = nullptr);
    ~newProjectDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_toolButton_clicked();

signals:
    void projectInfo(const QHash<QString, QString> &);

private:
    Ui::newProjectDialog *ui;
    QHash<QString, QString> projectHash;
};

#endif // NEWPROJECTDIALOG_H
