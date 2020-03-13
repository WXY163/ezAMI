#ifndef PLOTDILOG_H
#define PLOTDILOG_H

#include <QDialog>

namespace Ui {
class plotDialog;
}

class plotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit plotDialog(QWidget *parent = nullptr);
    ~plotDialog();

private:
    Ui::plotDialog *ui;
};

#endif // PLOTDILOG_H
