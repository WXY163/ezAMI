#ifndef PLOTTING_H
#define PLOTTING_H


#include <QDialog>
#include <QtWidgets>
#include <QtCore>
#include <QVector>
#include <QTimer>


namespace Ui {
class Dialog;
}

class plotting : public QDialog
{
    Q_OBJECT

public:
    explicit plotting(QWidget *parent = nullptr);
    ~plotting();
    void setupCor();
    void updateCoor(QString displayType);
    void updatePlotPoints();
    void closeEvent(QCloseEvent *event);


private:
    Ui::Dialog *ui;

    QGraphicsScene *scene;

    QGraphicsLineItem *line;
    QGraphicsRectItem *rect;
    QGraphicsEllipseItem *ellips;
    QGraphicsTextItem *text;
    QVector<QGraphicsLineItem*> *markerLineY;
    QVector<QGraphicsLineItem*> *markerLineX;
    QVector<QGraphicsLineItem*> graph;

    QVector<QGraphicsTextItem*> YaxisText;
    QVector<QGraphicsTextItem*> XaxisText10min;

    QVector<QPointF> *plotPoints;
    QVector<QGraphicsLineItem *> *plotSegments;

    QVector<QPointF> *simulatedPlotPoints;
    QVector<QGraphicsLineItem *> *simulatedPlotSegments;


    QVector<qreal> *waveForm;
    QVector<qreal> *simulatedWave;

    QString str;
    QString type;
    int samplePerBit = 0;
    long numberBit = 0;
    qreal amplitude = 1.0;
    qreal offset = 0.0;





   private slots:
    void XaxisSetup(uchar);
    void on_buttonBox_clicked(QAbstractButton *button);
    void coordinateSetup(QHash<QString, QString> excitationInfo);
    void addSimulatedWave(QVector<qreal> *simulated);



signals:
    void plotBtn_clicked();
    void stopBtn_clicked();
    void dialogClosed();
    void waveFormReady(QVector<qreal> *);


};
#endif // PLOTTING_H
