#include "sceneclick.h"

sceneClick::sceneClick()
{

}



void sceneClick::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        emit doubleClick(event->scenePos());
    }
}
