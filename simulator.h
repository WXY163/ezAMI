#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <QString>
#include <QLibrary>
#include <QVector>
#include <QDialog>

class simulator:public QDialog
{
    Q_OBJECT
public:
    explicit simulator(QWidget *parent = nullptr);
    ~simulator();
    void prepareWave(void);
    void run(void);
    void prepareOuput(void);

private slots:
    void setDllPath(QString path);
    void receiveInputWave(QVector<qreal> *inWave);

signals:
    void outputReady(QVector<qreal> *);


private:
    QString dllPath;
    QLibrary *dynamicLibrary;

    QVector<qreal> *inputWave;
    QVector<qreal> *outputWave;


    double *impulse_matrix = nullptr;
    long row_size = 1;
    long aggressors = 1;
    double sample_interval = 1.0e-9;
    double bit_time = 1e-9;
    char **AMI_parameters_in = nullptr;
    char **AMI_parameters_out = nullptr;
    void *AMI_memory_handle = nullptr;
    char *msg = nullptr;

    double *wave = nullptr;
    long wave_size = 1;
    double *clock_times = nullptr;

};

#endif // SIMULATOR_H
