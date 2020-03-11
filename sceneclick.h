#ifndef SCENECLICK_H
#define SCENECLICK_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

class sceneClick : public QGraphicsScene
{
     Q_OBJECT

public:
    sceneClick();
protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;



signals:
    void doubleClick(QPointF position);
};

#endif // SCENECLICK_H
