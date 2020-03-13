/*
 *     <ezAMI: IBIS-AMI model generation tool>
 *    Copyright (C) 2020
 *   Author: Xinying Wang (xinying@illinois.edu)
 *           Department of Electrical Computer Engineering
 *           University of Illinois at Urbana-Champaign
 *

 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.

 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.

 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "svgload.h"
#include <QSvgRenderer>

#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsSvgItem>
#include <QPaintEvent>
#include <qmath.h>
#include <QMessageBox>

#ifndef QT_NO_OPENGL
#endif

SvgLoad::SvgLoad(QString fileName)
    : m_renderer(Native)
    , m_svgItem(nullptr)
    , m_backgroundItem(nullptr)
    , m_outlineItem(nullptr)
{

    if(!openFile(fileName))
    {
        QMessageBox msgBox;
        msgBox.setText("Load " + fileName + "failed!");
        msgBox.addButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
}
SvgLoad::~SvgLoad()
{
    delete m_svgItem;
    delete m_backgroundItem;
    delete m_outlineItem;
}
void SvgLoad::drawBackground(QPainter *p, const QRectF &)
{
    p->save();
    p->resetTransform();
    p->drawTiledPixmap(viewport()->rect(), backgroundBrush().texture());
    p->restore();
}

QSize SvgLoad::svgSize() const
{
    return m_svgItem ? m_svgItem->boundingRect().size().toSize() : QSize();
}

bool SvgLoad::openFile(const QString &fileName)
{

    m_svgItem = new QGraphicsSvgItem(fileName);
    if (!m_svgItem->renderer()->isValid())
        return false;


    m_svgItem->setFlags(QGraphicsItem::ItemClipsToShape);
    m_svgItem->setCacheMode(QGraphicsItem::NoCache);
    //m_svgItem->setZValue(0);

    m_backgroundItem = new QGraphicsRectItem(m_svgItem->boundingRect());
    //m_backgroundItem->setBrush(Qt::blue);
    //m_backgroundItem->setBrush(Qt::SolidPattern);

    //m_backgroundItem->setVisible(drawBackground);
   // m_backgroundItem->setZValue(-1);

    m_outlineItem = new QGraphicsRectItem(m_svgItem->boundingRect());
    //QPen outline(Qt::blue, 2, Qt::SolidLine);
    //outline.setCosmetic(true); // set stroke to be constant independent of transforamtion
   // m_outlineItem->setPen(outline);
    //m_outlineItem->setBrush(Qt::NoBrush);
    //m_outlineItem->setVisible(drawOutline);
    //m_outlineItem->setZValue(1);
    return true;
}

void SvgLoad::setRenderer(RendererType type)
{
    m_renderer = type;

    if (m_renderer == OpenGL) {

    } else {
        setViewport(new QWidget);
    }
}

void SvgLoad::setsvgSize(QSize &sz)
{
    m_svgItem->setX(sz.width());
    m_svgItem->setY(sz.height());
    m_outlineItem->setX(sz.width());
    m_outlineItem->setY(sz.height());
    m_backgroundItem->setX(sz.width());
    m_backgroundItem->setY(sz.height());
}

void SvgLoad::setsvgPos(QPoint &pt)
{
    m_svgItem->setPos(pt);
    m_backgroundItem->setPos(pt);
    m_outlineItem->setPos(pt);
}
void SvgLoad::setHighQualityAntialiasing(bool highQualityAntialiasing)
{
#ifndef QT_NO_OPENGL
    setRenderHint(QPainter::HighQualityAntialiasing, highQualityAntialiasing);
#else
    Q_UNUSED(highQualityAntialiasing);
#endif
}

void SvgLoad::setViewBackground(bool enable)
{
    if (!m_backgroundItem)
          return;

    m_backgroundItem->setVisible(enable);
}

void SvgLoad::setViewOutline(bool enable)
{
    if (!m_outlineItem)
        return;

    m_outlineItem->setVisible(enable);
}

qreal SvgLoad::zoomFactor() const
{
    return transform().m11();
}

void SvgLoad::zoomIn()
{
    zoomBy(2);
}

void SvgLoad::zoomOut()
{
    zoomBy(0.5);
}

void SvgLoad::resetZoom()
{
    if (!qFuzzyCompare(zoomFactor(), qreal(1))) {
        resetTransform();
        emit zoomChanged();
    }
}


void SvgLoad::wheelEvent(QWheelEvent *event)
{
    zoomBy(qPow(1.2, event->delta() / 240.0));
}

void SvgLoad::zoomBy(qreal factor)
{
    const qreal currentZoom = zoomFactor();
    if ((factor < 1 && currentZoom < 0.1) || (factor > 1 && currentZoom > 10))
        return;
    scale(factor, factor);
    emit zoomChanged();
}

QSvgRenderer *SvgLoad::renderer() const
{
    if (m_svgItem)
        return m_svgItem->renderer();
    return nullptr;
}

QGraphicsSvgItem *SvgLoad::svgItem()
{
    if (m_svgItem)
        return m_svgItem;
    return nullptr;
}

QGraphicsRectItem *SvgLoad::outlineItem()
{
    if (m_outlineItem)
        return m_outlineItem;
    return nullptr;
}


