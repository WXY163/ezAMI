#ifndef COMPILER_H
#define COMPILER_H

#include <QProcess>
#include <QString>
#include <QStringList>
#include <QDialog>
#include <QModelIndex>
#include <QTextStream>
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
    void generateAmiFile(void);


private slots:

    void amiGeneration();
    void on_buildPushButton_clicked();

    void on_closePushButton_clicked();

    void updateProjectArch (projectTreeModel *arch);

    void on_gccPathToolButton_clicked();

    void setupPath();

signals:
    void sendBuildInfo(const QString &, const QString &);
    void updateProjectArch();


private:
    Ui::Compiler_Dialog *ui;
    QString msvcPath ="C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/";
    QString vs2019CommunityPath = "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/";
    QString vs2019ProfessionalPath = "C:/Program Files (x86)/Microsoft Visual Studio/2019/Professional/VC/Tools/MSVC/";
    QString vs2017CommunityPath = "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/";
    QString vs2017ProfessionalPath = "C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional/VC/Tools/MSVC/";
    QString windowsSDKPath = "C:/Program Files (x86)/Windows Kits/10/Include/";
    QString windowsSDKLibPath = "C:/Program Files (x86)/Windows Kits/10/Lib/";
    QString projectDirectory;
    QString projectName;
    QString AMIDirectory;
    QStringList sourceFiles;
    QStringList amiObjFiles;
    QStringList excutableObjFiles;
    QString excutableFile = "ami.dll" ;
    QString amiDll = "windows_x64.dll";
    QString amiFileName = "user.ami";
    QString cppComplier;
    QStringList argus;

    projectTreeModel *projectArch = nullptr;

    QProcess *process;

    QString stdOut;
    QString stdErr;

};

#endif // COMPILER_H
