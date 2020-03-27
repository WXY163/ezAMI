#ifndef GENERATEDLLDIALOG_H
#define GENERATEDLLDIALOG_H

#include <QDialog>

namespace Ui {
class generateDllDialog;
}

class generateDllDialog : public QDialog
{
    Q_OBJECT

public:
    explicit generateDllDialog(QWidget *parent = nullptr);
    ~generateDllDialog();

private:
    Ui::generateDllDialog *ui;
};

#endif // GENERATEDLLDIALOG_H
