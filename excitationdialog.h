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
    void pam2Draw(void);
    void pam4Draw(void);


    QHash<QString, qreal> *userPRBSValue;
    QHash<QString, QString> *userPRBSUnit;
    QHash<QString, qreal> *userPAM4Value;
    QHash<QString, QString> *userPAM4Unit;


private slots:
    void on_buttonBox_accepted();


    void on_dataRateInput_textEdited();

    void on_amplitudeInput_textEdited();

    void on_offsetInput_textEdited();

    void on_prbsRadioButton_clicked(bool checked);

    void on_PAM4RadioButton_clicked(bool checked);

    void on_dataRatePAM4Input_textEdited();

    void on_offsetPAM4Input_textEdited();

    void on_amplitudePAM4Input_textEdited();

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
