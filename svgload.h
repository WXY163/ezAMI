#ifndef SVGLOAD_H
#define SVGLOAD_H
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
class QGraphicsSvgItem;
class QSvgRenderer;
class QWheelEvent;
class QPaintEvent;
QT_END_NAMESPACE

class SvgLoad : public QGraphicsView
{
    Q_OBJECT

public:
    enum RendererType { Native, OpenGL, Image };

    explicit SvgLoad(QWidget *parent = nullptr, QString fileName = "");
    ~SvgLoad() override;

    bool openFile(const QString &fileName);
    void setRenderer(RendererType type = Native);
    void drawBackground(QPainter *p, const QRectF &rect) override;
    void setsvgSize(QSize &sz);
    void setsvgPos(QPoint &pt);
    QSize svgSize() const;
    QSvgRenderer *renderer() const;

    qreal zoomFactor() const;

public slots:
    void setHighQualityAntialiasing(bool highQualityAntialiasing);
    void setViewBackground(bool enable);
    void setViewOutline(bool enable);
    void zoomIn();
    void zoomOut();
    void resetZoom();

signals:
    void zoomChanged();

protected:
    void wheelEvent(QWheelEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    void zoomBy(qreal factor);

    RendererType m_renderer;
    QGraphicsSvgItem *m_svgItem;
    QGraphicsRectItem *m_backgroundItem;
    QGraphicsRectItem *m_outlineItem;
};



#endif // SVGLOAD_H
