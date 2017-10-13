#include "cvcanvas.h"

#include <QDebug>

CVCanvas::CVCanvas(QQuickPaintedItem* parent)
    : QQuickPaintedItem(parent)
{
    m_image = QImage("/home/jseo/ChannelAdded.png");
    if(m_image.isNull())
        qWarning() << "error!";
    else
        qWarning() << m_image.size();


}

void CVCanvas::updateImage(const QImage& image)
{
    m_image = image;        // does shallow copy of image data
    update();               // triggers actual update
}

void CVCanvas::paint(QPainter* painter)
{
    if (!m_pixmap.isNull()) {
        painter->drawPixmap(this->boundingRect().toRect(), m_pixmap);
    } else
        painter->drawImage(this->boundingRect(), m_image);
}

void CVCanvas::setPixmap(QPixmap pixmap)
{
}
