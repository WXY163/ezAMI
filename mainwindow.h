#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include "plotting.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_simulateButton_clicked();
    void on_generateAmiButton_clicked();

    void on_compileButton_clicked();

private:
    Ui::MainWindow *ui;
    plotting *plot;
    QToolBar *toolBar;
    void** memoryHanddle;

};

#endif // MAINWINDOW_H
