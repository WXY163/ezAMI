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
#define AMI_INIT
#define AMI_CLOSE


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
    {
        delete [] wave;
        wave = nullptr;
    }

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
    wave = nullptr;
}

void simulator::run()
{
    if (QLibrary::isLibrary(dllPath)) {
          dynamicLibrary = new QLibrary(dllPath);
          dynamicLibrary->load();
          if (!dynamicLibrary->isLoaded()) {
               QMessageBox::warning(this, tr("dll loading error"), dynamicLibrary->errorString(), "ok");
               return;
          }

          double *impulse_matrix = nullptr;
          long row_size = 0;
          long aggressors = 0;
          double sample_interval = 1.0;
          double bit_time =1.0;
          char **AMI_parameters_in = nullptr;
          char **AMI_parameters_out = nullptr;
          void **AMI_memory_handle = new void*;
          char **msg = new char*;
          long result = 0;

#ifdef AMI_INIT

             typedef long (*initFunctionPrototype)(double *impulse_matrix,
                                               long row_size,
                                               long aggressors,
                                               double sample_interval,
                                               double bit_time,
                                               char **AMI_parameters_in,
                                               char **AMI_parameters_out,
                                               void **AMI_memory_handle,
                                               char **msg);


             initFunctionPrototype AMI_Init = (initFunctionPrototype)dynamicLibrary->resolve("AMI_Init");
            // if null means the symbol was not loaded

            if (AMI_Init){

                result = AMI_Init(impulse_matrix, row_size,aggressors, sample_interval, bit_time, AMI_parameters_in, AMI_parameters_out, AMI_memory_handle, msg);

            }
            else
            {
                 QMessageBox::critical(this, tr("AMI_Init call error"), tr("cannot resolve AMI_Init function"), "ok");
                 dynamicLibrary->unload();
                 return;

            }
            if(result)
            {
                result = 0;
            }
            else
            {
                QMessageBox::critical(this, tr("AMI_Init returns zero"), tr("Error in AMI_Init"), "ok");
                dynamicLibrary->unload();
                return;
            }


#endif

            void *AMI_memory = *AMI_memory_handle;

#ifdef AMI_GETWAVE
            typedef long (*getWaveFunctionPrototype) (double *wave,
                                               long wave_size,
                                               long aggressors,
                                               double *clock_times,
                                               char **AMI_parameters_out,
                                               void *AMI_memory);
            getWaveFunctionPrototype AMI_GetWave = (getWaveFunctionPrototype) dynamicLibrary->resolve("AMI_GetWave");
            if(AMI_GetWave)
            {
                prepareWave();
                result = AMI_GetWave(wave, wave_size, aggressors, clock_times, AMI_parameters_out,AMI_memory);

            }
            else
            {
                QMessageBox::critical(this, tr("AMI_GetWave call error"), tr("cannot resolve AMI_GetWave function"), "ok");
                dynamicLibrary->unload();
                return;
            }

            if(result)
            {
                prepareOuput();
                emit outputReady(outputWave);
                result = 0;
            }
            else
            {
                QMessageBox::critical(this, tr("AMI_GetWave returns zero"), tr("AMI_GetWave function has error"), "ok");
                dynamicLibrary->unload();
                return;
            }

#endif


#ifdef AMI_CLOSE
             typedef long (*closeFunctionPrototype)( void *AMI_memory_handle);
                closeFunctionPrototype AMI_Close = (closeFunctionPrototype)dynamicLibrary->resolve("AMI_Close");
                if(AMI_Close)
                {
                    result = AMI_Close(AMI_memory);

                }
                else {
                    QMessageBox::critical(this, tr("AMI_Closs call error"), tr("cannot resolve AMI_Close function"), "ok");
                    dynamicLibrary->unload();
                    return;
                }
                if(result)
                {
                    result = 0;
                     dynamicLibrary->unload();
                }
                else
                {
                    QMessageBox::critical(this, tr("AMI_Close returns zero"), tr("AMI_Close function has error"), "ok");
                    dynamicLibrary->unload();
                    return;
                }
    #endif

          delete msg;
          delete AMI_memory_handle;
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
