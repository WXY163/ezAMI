#include "simulator.h"

simulator::simulator()
{
    dynamicLibrary = new QLibrary;
}

simulator::~simulator()
{
    delete dynamicLibrary;
}
