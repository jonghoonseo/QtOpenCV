#ifndef CVCANVAS_H
#define CVCANVAS_H

#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>

class CVCanvas : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QImage image READ image WRITE setImage NOTIFY imageChanged)

public:

    explicit CVCanvas(QQuickPaintedItem* parent = nullptr);
    void paint(QPainter *painter);

    QImage image() { return m_image; }
    void setImage(QImage image);

signals:
    void imageChanged();

protected:
    QImage m_image;
};

#endif // CVCANVAS_H
