/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QAction *actionAbout;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionExcitation;
    QAction *actionPlot;
    QAction *actionAMI;
    QAction *actionBuild;
    QAction *actionDebug;
    QWidget *MainInterface;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QGraphicsView *diagramWindow;
    QTextBrowser *statusWindow;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *codeArea;
    QWidget *ami_init;
    QGridLayout *gridLayout_3;
    QTextEdit *amiInit;
    QWidget *ami_getwave;
    QGridLayout *gridLayout_2;
    QTextEdit *amiGetWave;
    QWidget *ami_close;
    QGridLayout *gridLayout_4;
    QTextEdit *amiClose;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *compileButton;
    QPushButton *simulateButton;
    QPushButton *generateAmiButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuTool;
    QMenu *menuIntert;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1029, 649);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionExcitation = new QAction(MainWindow);
        actionExcitation->setObjectName(QString::fromUtf8("actionExcitation"));
        actionPlot = new QAction(MainWindow);
        actionPlot->setObjectName(QString::fromUtf8("actionPlot"));
        actionAMI = new QAction(MainWindow);
        actionAMI->setObjectName(QString::fromUtf8("actionAMI"));
        actionBuild = new QAction(MainWindow);
        actionBuild->setObjectName(QString::fromUtf8("actionBuild"));
        actionDebug = new QAction(MainWindow);
        actionDebug->setObjectName(QString::fromUtf8("actionDebug"));
        MainInterface = new QWidget(MainWindow);
        MainInterface->setObjectName(QString::fromUtf8("MainInterface"));
        gridLayout = new QGridLayout(MainInterface);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox = new QCheckBox(MainInterface);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        diagramWindow = new QGraphicsView(MainInterface);
        diagramWindow->setObjectName(QString::fromUtf8("diagramWindow"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(diagramWindow->sizePolicy().hasHeightForWidth());
        diagramWindow->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(diagramWindow);

        statusWindow = new QTextBrowser(MainInterface);
        statusWindow->setObjectName(QString::fromUtf8("statusWindow"));

        verticalLayout->addWidget(statusWindow);

        verticalSpacer = new QSpacerItem(10, 32, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        codeArea = new QTabWidget(MainInterface);
        codeArea->setObjectName(QString::fromUtf8("codeArea"));
        ami_init = new QWidget();
        ami_init->setObjectName(QString::fromUtf8("ami_init"));
        gridLayout_3 = new QGridLayout(ami_init);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        amiInit = new QTextEdit(ami_init);
        amiInit->setObjectName(QString::fromUtf8("amiInit"));

        gridLayout_3->addWidget(amiInit, 0, 0, 1, 1);

        codeArea->addTab(ami_init, QString());
        ami_getwave = new QWidget();
        ami_getwave->setObjectName(QString::fromUtf8("ami_getwave"));
        gridLayout_2 = new QGridLayout(ami_getwave);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        amiGetWave = new QTextEdit(ami_getwave);
        amiGetWave->setObjectName(QString::fromUtf8("amiGetWave"));

        gridLayout_2->addWidget(amiGetWave, 0, 0, 1, 1);

        codeArea->addTab(ami_getwave, QString());
        ami_close = new QWidget();
        ami_close->setObjectName(QString::fromUtf8("ami_close"));
        gridLayout_4 = new QGridLayout(ami_close);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        amiClose = new QTextEdit(ami_close);
        amiClose->setObjectName(QString::fromUtf8("amiClose"));

        gridLayout_4->addWidget(amiClose, 0, 0, 1, 1);

        codeArea->addTab(ami_close, QString());

        verticalLayout_2->addWidget(codeArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        saveButton = new QPushButton(MainInterface);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout_2->addWidget(saveButton);

        compileButton = new QPushButton(MainInterface);
        compileButton->setObjectName(QString::fromUtf8("compileButton"));

        horizontalLayout_2->addWidget(compileButton);

        simulateButton = new QPushButton(MainInterface);
        simulateButton->setObjectName(QString::fromUtf8("simulateButton"));

        horizontalLayout_2->addWidget(simulateButton);

        generateAmiButton = new QPushButton(MainInterface);
        generateAmiButton->setObjectName(QString::fromUtf8("generateAmiButton"));

        horizontalLayout_2->addWidget(generateAmiButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        MainWindow->setCentralWidget(MainInterface);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1029, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QString::fromUtf8("menuTool"));
        menuIntert = new QMenu(menuTool);
        menuIntert->setObjectName(QString::fromUtf8("menuIntert"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        menuHelp->addAction(actionAbout);
        menuTool->addAction(menuIntert->menuAction());
        menuTool->addAction(actionBuild);
        menuTool->addAction(actionDebug);
        menuIntert->addAction(actionExcitation);
        menuIntert->addAction(actionPlot);
        menuIntert->addAction(actionAMI);

        retranslateUi(MainWindow);

        codeArea->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
        actionExcitation->setText(QApplication::translate("MainWindow", "Excitation", nullptr));
#ifndef QT_NO_STATUSTIP
        actionExcitation->setStatusTip(QApplication::translate("MainWindow", "For excitation generation", nullptr));
#endif // QT_NO_STATUSTIP
        actionPlot->setText(QApplication::translate("MainWindow", "Plotting", nullptr));
        actionAMI->setText(QApplication::translate("MainWindow", "AMI", nullptr));
        actionBuild->setText(QApplication::translate("MainWindow", "Build", nullptr));
        actionDebug->setText(QApplication::translate("MainWindow", "Debug", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "AMIModel", nullptr));
        statusWindow->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Simulation and compilation status</p></body></html>", nullptr));
        amiInit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &lt;string&gt;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &lt;fstream&gt;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &lt;sstream&gt;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &lt;algorithm&gt;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &lt;cstdlib&gt;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &quot;ami.h&quot;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; color:#0000ff;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; color:#00aa00;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; ma"
                        "rgin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#00aa00;\">long</span><span style=\" font-size:12pt;\"> AMI_Init(</span><span style=\" font-size:12pt; color:#00aa00;\">double</span><span style=\" font-size:12pt;\"> *impulse_matrix, </span><span style=\" font-size:12pt; color:#00aa00;\">long</span><span style=\" font-size:12pt;\"> row_size, </span><span style=\" font-size:12pt; color:#00aa00;\">long</span><span style=\" font-size:12pt;\"> aggressors, </span><span style=\" font-size:12pt; color:#00aa00;\">double</span><span style=\" font-size:12pt;\"> sample_interval, </span><span style=\" font-size:12pt; color:#00aa00;\">double</span><span style=\" font-size:12pt;\"> bit_time, </span><span style=\" font-size:12pt; color:#00aa00;\">char</span><span style=\" font-size:12pt;\"> **AMI_parameters_in, </span><span style=\" font-size:12pt; color:#00aa00;\">char</span><span style=\" font-size:12pt;\"> **AMI_parameters_out, </span><span style=\" font-size:12pt; color:#00aa00;\""
                        ">void</span><span style=\" font-size:12pt;\"> **AMI_memory_handle, </span><span style=\" font-size:12pt; color:#00aa00;\">char</span><span style=\" font-size:12pt;\"> **msg){</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">	return 0;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">}</span></p></body></html>", nullptr));
        codeArea->setTabText(codeArea->indexOf(ami_init), QApplication::translate("MainWindow", "AMI_Init", nullptr));
        amiGetWave->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &lt;string&gt;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &lt;fstream&gt;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &lt;sstream&gt;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &lt;algorithm&gt;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &lt;cstdlib&gt;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0000ff;\">#include &quot;ami.h&quot;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#00aa00;\">long</span><span style=\" font-size:12pt;\"> AMI_GetWave(</span><span style=\" font-size:12pt; color:#00"
                        "aa00;\">double</span><span style=\" font-size:12pt;\"> *wave, </span><span style=\" font-size:12pt; color:#00aa00;\">long</span><span style=\" font-size:12pt;\"> wave_size, long aggressors, </span><span style=\" font-size:12pt; color:#00aa00;\">double</span><span style=\" font-size:12pt;\"> *clock_times, </span><span style=\" font-size:12pt; color:#00aa00;\">char</span><span style=\" font-size:12pt;\"> **AMI_parameters_out, </span><span style=\" font-size:12pt; color:#00aa00;\">void</span><span style=\" font-size:12pt;\"> *AMI_memory) </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">{</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">	return 0;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px"
                        ";\"><span style=\" font-size:12pt;\">}</span></p></body></html>", nullptr));
        codeArea->setTabText(codeArea->indexOf(ami_getwave), QApplication::translate("MainWindow", "AMI_GetWave", nullptr));
        amiClose->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#00aa00;\">long</span><span style=\" font-size:12pt;\"> AMI_Close(</span><span style=\" font-size:12pt; color:#00aa00;\">void</span><span style=\" font-size:12pt;\"> *AMI_memory) {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">	</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">	re"
                        "turn 0;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">}</span></p></body></html>", nullptr));
        codeArea->setTabText(codeArea->indexOf(ami_close), QApplication::translate("MainWindow", "AMI_Close", nullptr));
        saveButton->setText(QApplication::translate("MainWindow", "Save", nullptr));
        compileButton->setText(QApplication::translate("MainWindow", "Compile", nullptr));
        simulateButton->setText(QApplication::translate("MainWindow", "Simulate", nullptr));
        generateAmiButton->setText(QApplication::translate("MainWindow", "Generate DLL", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuTool->setTitle(QApplication::translate("MainWindow", "Tool", nullptr));
        menuIntert->setTitle(QApplication::translate("MainWindow", "Intert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
