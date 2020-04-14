#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <QString>
#include <QLibrary>
#include <QVector>

class simulator
{
public:
    explicit simulator();
    ~simulator();
    void prepareWave(void);
    void run(void);
    void prepareOuput(void);

private:
    QString dllPath;
    QLibrary *dynamicLibrary;

    QVector<qreal> *inputWave;
    QVector<qreal> *ouputWave;


    double *impulse_matrix;
    long row_size;
    long aggressors;
    double sample_interval;
    double bit_time;
    char **AMI_parameters_in;
    char **AMI_parameters_out;
    void *AMI_memory_handle;
    char *msg;

    double *wave;
    long wave_size;
    double *clock_times;


};

#endif // SIMULATOR_H
