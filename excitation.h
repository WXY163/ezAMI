#ifndef EXCITATION_H
#define EXCITATION_H
#include <QtCore>
#include <QString>
#include <QVector>
#include <QList>
#include <QHash>

class excitation
{
public:
    excitation();
    excitation(qreal ti, qreal len) {timeInterval = ti; length = len;}
    ~excitation();
    QVector<qreal> *getSample();
    QVector<qreal> *getTimeSteps();


private:
    qreal timeInterval = 1e-9;
    qreal length = 1e-6;
};


#endif // EXCITATION_H
