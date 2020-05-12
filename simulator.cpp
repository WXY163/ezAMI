/*
 *     ezAMI: IBIS-AMI model generation tool
 *    Copyright (C) 2020
 *   Author: Xinying Wang (xinying@illinois.edu)
 *           Department of Electrical Computer Engineering
 *           University of Illinois at Urbana-Champaign
 *

 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "simulator.h"
#include <QMessageBox>
#include <QTranslator>


#define AMI_GETWAVE


simulator::simulator(QWidget *parent): QDialog (parent)
{
    this->setParent(parent);
    dynamicLibrary = new QLibrary;
    outputWave = new QVector<qreal>();

}

simulator::~simulator()
{
    delete dynamicLibrary;
    delete outputWave;
}

void simulator::prepareWave()
{
    if(!inputWave)
    {
       QMessageBox::critical(this, tr("No Input Wave!"), tr("Generate excitiation first!"), "ok");
       return;
    }
    wave_size = inputWave->size();
    if(wave)
        delete [] wave;

    wave = new double[wave_size];
    for (auto i = 0; i < wave_size; i++)
    {
        wave[i] = inputWave->value(i);
    }
}

void simulator::prepareOuput()
{
    if(!outputWave->isEmpty())
    {
        outputWave->clear();
    }
    for(auto i = 0; i < wave_size; i++)
    {
        outputWave->append(wave[i]);

    }
    delete [] wave;
}

void simulator::run()
{
    if (QLibrary::isLibrary(dllPath)) {
          dynamicLibrary = new QLibrary(dllPath);
          dynamicLibrary->load();
          if (!dynamicLibrary->isLoaded()) {
                QMessageBox::warning(this, tr("dll loading error"), dynamicLibrary->errorString(), "ok");
          }
          else {
#ifdef AMI_GETWAVE
            typedef long (*FunctionPrototype) (double *wave,
                                               long wave_size,
                                               long aggressors,
                                               double *clock_times,
                                               char **AMI_parameters_out,
                                               void *AMI_memory);
            FunctionPrototype AMI_GetWave = (FunctionPrototype) dynamicLibrary->resolve("AMI_GetWave");
            if(AMI_GetWave)
            {
                prepareWave();
                long result = AMI_GetWave(wave, wave_size, aggressors, clock_times, AMI_parameters_out,AMI_memory_handle);
                if(!result)
                {
                    prepareOuput();
                    emit outputReady(outputWave);
                }
                else
                {
                    QMessageBox::critical(this, tr("AMI_GetWave return error"), tr("AMI_GetWave return is not zero"), "ok");
                }

            }
            else {
                QMessageBox::critical(this, tr("AMI_GetWave call error"), tr("cannot resolve AMI_GetWave function"), "ok");
            }
            dynamicLibrary->unload();
#endif
          }
    }
}

void simulator::setDllPath(QString path)
{
    dllPath = path;
}

void simulator::receiveInputWave(QVector<qreal> *inWave)
{
    inputWave = inWave;
}
