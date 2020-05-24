#ifndef COMPILER_H
#define COMPILER_H

#include <QProcess>
#include <QString>
#include <QStringList>
#include <QDialog>
#include <QModelIndex>
#include "ui_compiler.h"
#include "projecttreeitem.h"
#include "projecttreemodel.h"
#include <QSysInfo>

namespace Ui {
    class Compiler_Dialog;
}

class compiler : public QDialog
{
    Q_OBJECT
public:
    explicit compiler(QWidget* parent = nullptr);
    ~compiler();
    QString getSourcePath(void) const;

    void compile(void);
    void generateDll(void);


private slots:

    void amiGeneration();
    void on_buildPushButton_clicked();

    void on_closePushButton_clicked();

    void updateProjectArch (projectTreeModel *arch);

    void on_gccPathToolButton_clicked();

signals:
    void sendBuildInfo(const QString &, const QString &);
    void updateProjectArch();
private:
    Ui::Compiler_Dialog *ui;
    QString msvcPath ="C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.25.28610";
    QString windowsSDKPath = "C:/Program Files (x86)/Windows Kits/10/Include/" + QSysInfo::kernelVersion() + ".0";
    QString windowsSDKLibPath = "C:/Program Files (x86)/Windows Kits/10/Lib/" + QSysInfo::kernelVersion() + ".0";
    QString projectDirectory;
    QString AMIDirectory;
    QStringList sourceFiles;
    QStringList amiObjFiles;
    QStringList excutableObjFiles;
    QString excutableFile = "ami.dll" ;
    QString amiDll = "windows_x64.dll";
    QString cppComplier;
    QStringList argus;

    projectTreeModel *projectArch = nullptr;

    QProcess *process;

    QString stdOut;
    QString stdErr;

};

#endif // COMPILER_H
