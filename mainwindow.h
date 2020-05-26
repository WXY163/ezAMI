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
#include <QDir>

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
#include "newprojectdialog.h"

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
    bool isInRegion(QGraphicsItem* item, const QPointF &clickPos);
    bool saveProjectFile(void);
    bool saveCodeFile(void);

    void setupContextMenu(void);
    void addModelFilesInDirectory(const QDir &dir);
    bool updateModelByChild(const QStringList &fileNames, const QModelIndex &child);
    void parseAmiFunctions(void);

private slots:

    void on_actionAMI_Generation_triggered();
    void on_actionBuild_2_triggered();
    void on_actionRun_2_triggered();
    void on_actionClean_2_triggered();
    void on_actionSave_triggered();
    void on_actionSave_All_triggered();
    void on_actionOpen_triggered(void);
    void on_actionClose_Project_triggered(void);
    void on_actionAMI_triggered();

    void on_amiInit_textChanged();

    void on_amiGetWave_textChanged();

    void on_amiClose_textChanged();

    void on_actionExcitation_triggered();
    void on_actionPlot_triggered();
    void on_actionAbout_triggered();
    void on_actionClose_triggered();

    void on_amiModelCheckBox_stateChanged(int arg1);

    void on_doubleClicked(QPointF position);


    void on_projectTreeView_doubleClicked(const QModelIndex &index);
    void onCustomContextMenu(const QPoint &);
    void on_actionProject_triggered();
    void on_CustomContextMenu_triggered(QAction *action);

    void setProjectInfo(const QHash<QString, QString> &);

    void on_actionLVFFN_triggered();

    void updateProjectTreeFromCompiler();


signals:
    void amiModelChecked(bool);
    void projectArchtoCompiler(projectTreeModel *arch);


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
    newProjectDialog *newProjectDlg;

    QToolBar *toolBar;
    SvgLoad *svgexcite;
    SvgLoad *svgAMI;
    SvgLoad *svgPlot;

    QGraphicsLineItem *eaLine;
    QGraphicsLineItem *epLine;
    sceneClick *scene;

    QHash<QString, QString> *excitationInfo;

    projectTreeModel *projectArch;

    QMenu *contextMenu;
    QAction *contextMenuNewAction;
    QAction *contextMenuAddAction;
    QAction *contextMenuCopyAction;
    QAction *contextMenuPasteAction;
    QAction *contextMenuDeleteAction;

    //projectDir is the whole path for project file
    QString projectDir;
    //project name is the name only without file subfix
    QString projectName;

    QModelIndex treeItemToModify;




};

#endif // MAINWINDOW_H
