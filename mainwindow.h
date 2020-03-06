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

    void on_saveButton_clicked();

    void on_amiInit_textChanged();

    void on_amiGetWave_textChanged();

    void on_amiClose_textChanged();

private:
    Ui::MainWindow *ui;
    plotting *plot;
    QToolBar *toolBar;
    void** memoryHanddle;

};

#endif // MAINWINDOW_H
