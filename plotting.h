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
    explicit plotting(QWidget *parent = 0);
    ~plotting();
    void setupCor();
    void closeEvent(QCloseEvent *event);


private:
    Ui::Dialog *ui;
    //QString *title;
    //QString xaxis = "Time(min)";
    //QString yaxis = "Voltage(mV)";
    QGraphicsScene *scene;

    QGraphicsLineItem *line;
    QGraphicsRectItem *rect;
    QGraphicsEllipseItem *ellips;
    QGraphicsTextItem *text;
    QVector<QGraphicsLineItem*> *markerLineY;
    QVector<QGraphicsLineItem*> *markerLineX;

    QVector<QGraphicsEllipseItem*> plotDot;
    QVector<QGraphicsTextItem*> YaxisText;
    QVector<QGraphicsTextItem*> XaxisText10min;
    QString str;




   private slots:
    void XaxisSetup(uchar);
    void on_buttonBox_clicked(QAbstractButton *button);
    void coordinateSetup(QHash<QString, QString> excitationInfo);



signals:
    void plotBtn_clicked();
    void stopBtn_clicked();
    void dialogClosed();


};
#endif // PLOTTING_H
