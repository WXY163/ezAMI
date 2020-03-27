#ifndef EXCITATIONDIALOG_H
#define EXCITATIONDIALOG_H

#include <QDialog>
#include <QHash>
#include <QVector>
#include <QPen>
#include <QGraphicsScene>

namespace Ui {
class excitationDialog;
}

class excitationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit excitationDialog(QWidget *parent = nullptr);
    ~excitationDialog();
    void updateHash(void);
    void getSamples(void);
    void setupCoordinate(void);
    void drawWave(void);


    QHash<QString, qreal> *userPRBSValue;
    QHash<QString, QString> *userPRBSUnit;
    QHash<QString, qreal> *userSineValue;
    QHash<QString, QString> *userSineUnit;


private slots:
    void on_buttonBox_accepted();


    void on_dataRateInput_textEdited();

    void on_amplitudeInput_textEdited();

    void on_offsetInput_textEdited();

private:
    Ui::excitationDialog *ui;
    QGraphicsScene *excitateScene;
    QGraphicsLineItem *xaxis;
    QGraphicsLineItem *yaxis;

    QVector<QGraphicsLineItem *> *prbs;


    QVector<qreal> *samples;
    int numberBit = 0;
    int samplePerUnitLength =0;

    qreal amplitude = 1.0;
    qreal offset = 0.0;

};

#endif // EXCITATIONDIALOG_H
