#ifndef EXCITATIONDIALOG_H
#define EXCITATIONDIALOG_H

#include <QDialog>

namespace Ui {
class excitationDialog;
}

class excitationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit excitationDialog(QWidget *parent = nullptr);
    ~excitationDialog();

private:
    Ui::excitationDialog *ui;
};

#endif // EXCITATIONDIALOG_H
