#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QHash>
#include <QContextMenuEvent>

#include "svgload.h"
#include "plotting.h"
#include "sceneclick.h"
#include "amidialog.h"
#include "plotdialog.h"
#include "excitationdialog.h"
#include "aboutdialog.h"
#include "generatedlldialog.h"
#include "compiler.h"
#include "simulator.h"
#include "projecttreeitem.h"
#include "projecttreemodel.h"

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
    bool isInRegion(QGraphicsItem* item, QPointF clickPos);

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
    void on_actionAbout_triggered();
    void on_actionClose_triggered();

    void on_amiModelCheckBox_stateChanged(int arg1);

    void on_doubleClicked(QPointF position);

    void on_actionOpen_triggered(void);
    void on_projectTreeView_doubleClicked(const QModelIndex &index);


signals:
    void amiModelChecked(bool);


private:
    Ui::MainWindow *ui;
    plotting *plot;
    amiDialog *amiDlg;
    plotDialog *plotDlg;
    excitationDialog *excitationDlg;
    aboutDialog *aboutDlg;
    generateDllDialog *generateDllDlg;
    compiler *gccCompiler;
    simulator *simulateEngine;

    QToolBar *toolBar;
    SvgLoad *svgexcite;
    SvgLoad *svgAMI;
    SvgLoad *svgPlot;

    QGraphicsLineItem *eaLine;
    QGraphicsLineItem *epLine;
    sceneClick *scene;

    QHash<QString, QString> *excitationInfo;

    projectTreeModel *treeModel;




};

#endif // MAINWINDOW_H
