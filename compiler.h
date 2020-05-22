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

namespace Ui {
    class Compiler_Dialog;
}

class compiler : public QDialog
{
    Q_OBJECT
public:
    explicit compiler(QWidget* parent = nullptr);
    ~compiler();
    QString getSourcePath(void);

    void compile(void);
    void generateDll(void);


private slots:
    void on_gccPathToolButton_clicked();


    void on_generalGccCheckBox_clicked(bool checked);

    void on_buildPushButton_clicked();

    void on_closePushButton_clicked();

    void on_AMIPushButton_clicked();

    void updateProjectArch (projectTreeModel *arch);
private:
    Ui::Compiler_Dialog *ui;

    QString projectDirectory;
    QString AMIDirectory;

    QStringList sourceFiles;
    QStringList objFiles;
    QString cppComplier;
    QStringList argus;

    projectTreeModel *projectArch = nullptr;



    QProcess *process;

};

#endif // COMPILER_H
