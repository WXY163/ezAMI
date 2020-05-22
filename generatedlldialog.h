#ifndef GENERATEDLLDIALOG_H
#define GENERATEDLLDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class generateDllDialog;
}

class generateDllDialog : public QDialog
{
    Q_OBJECT

public:
    explicit generateDllDialog(QWidget *parent = nullptr);
    ~generateDllDialog();
private slots:

    void dllGenerateStatus(const QString &stdOut, const QString &stdErr);


    void on_GeneratePushButton_clicked();

    void on_ClosePushButton_clicked();

signals:
    void generateDll();


private:
    Ui::generateDllDialog *ui;
    QString stdOutput;
    QString stdError;
};

#endif // GENERATEDLLDIALOG_H
