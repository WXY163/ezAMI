#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <QString>
#include <QLibrary>

class simulator
{
public:
    explicit simulator();
    ~simulator();

private:
    QString dllPath;
    QLibrary *dynamicLibrary;

};

#endif // SIMULATOR_H
