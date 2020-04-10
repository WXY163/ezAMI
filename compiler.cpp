#include "compiler.h"

compiler::compiler()
{
    process = new QProcess();
}
compiler::~compiler()
{
    delete process;
}

void compiler::setSourcePath(QString dir)
{
    directory = dir;
}

QString compiler::getSourcePath()
{
    return directory;
}

void compiler::compile()
{

}

void compiler::generateDll()
{

}
