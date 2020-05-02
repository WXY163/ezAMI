#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>

namespace Ui {
class newProjectDialog;
}

class newProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newProjectDialog(QWidget *parent = nullptr);
    ~newProjectDialog();

private:
    Ui::newProjectDialog *ui;
};

#endif // NEWPROJECTDIALOG_H
