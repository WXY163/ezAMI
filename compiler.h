#ifndef COMPILER_H
#define COMPILER_H

#include <QProcess>
#include <QString>
#include <QStringList>



class compiler
{
    Q_OBJECT
public:
    compiler();
    ~compiler();
    void setSourcePath(QString dir);
    QString getSourcePath(void);

    void compile(void);
    void generateDll(void);


private:
    QString directory;
    QString cppComplier = "gcc";
    QStringList argus;


    QProcess *process;

};

#endif // COMPILER_H
