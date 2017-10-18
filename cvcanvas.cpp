#include "cvcanvas.h"

#include <QDebug>

CVCanvas::CVCanvas(QQuickPaintedItem* parent)
    : QQuickPaintedItem(parent)
{

}


void CVCanvas::paint(QPainter* painter)
{
    painter->drawImage(this->boundingRect(), m_image);
}

void CVCanvas::setImage(QImage image)
{
    if (m_image != image)
        m_image = image;

    update();
}
