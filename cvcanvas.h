#ifndef CVCANVAS_H
#define CVCANVAS_H

#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>
#include <QVariant>
#include <QPixmap>

class CVCanvas : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QPixmap pixmap READ pixmap WRITE setPixmap NOTIFY pixmapChanged)
    Q_PROPERTY(QImage image READ image WRITE setImage)

public:
    explicit CVCanvas(QQuickPaintedItem* parent = nullptr);
    void paint(QPainter *painter);

    QPixmap pixmap() { return m_pixmap; }
    void setPixmap(QPixmap pixmap);

    QImage image() { return m_image; }
    void setImage(QImage image) { m_image = image; }

signals:
    void pixmapChanged();

public slots:
    void updateImage(const QImage&);

protected:
    QImage m_image;
    QPixmap m_pixmap;
};

#endif // CVCANVAS_H
