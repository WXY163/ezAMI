
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
