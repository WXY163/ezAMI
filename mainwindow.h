#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "svgload.h"

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
    void drawExcitPlot();
    void drawExcitAmiPlot();

private slots:
    void on_simulateButton_clicked();
    void on_generateAmiButton_clicked();

    void on_compileButton_clicked();

    void on_saveButton_clicked();

    void on_amiInit_textChanged();

    void on_amiGetWave_textChanged();

    void on_amiClose_textChanged();

    void on_actionExcitation_triggered();
    void on_actionAMI_triggered();
    void on_actionPlot_triggered();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    plotting *plot;
    QToolBar *toolBar;
    QGraphicsScene *scene;
    SvgLoad *svgexcite;
    SvgLoad *svgAMI;
    SvgLoad *svgPlot;
    QGraphicsLineItem *eaLine;
    QGraphicsLineItem *epLine;
    void** memoryHanddle;

};

#endif // MAINWINDOW_H
