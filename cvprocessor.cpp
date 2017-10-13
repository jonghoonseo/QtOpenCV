#include "cvprocessor.h"

#include <QDebug>

CVProcessor::CVProcessor(QObject *parent) : QObject(parent)
{
}


void CVProcessor::setFileName(const QString &fileName)
{
    if (fileName == m_fileName)
        return;

    m_fileName = fileName;
    emit fileNameChanged();

    // Load an image
    m_cvimage = cv::imread("/home/jseo/ChannelAdded.png", cv::IMREAD_GRAYSCALE);
    m_qimage = QImage(m_cvimage.data, m_cvimage.cols, m_cvimage.rows, QImage::Format_RGB888);
    m_image = QPixmap::fromImage(m_qimage);
    emit imageChanged();
    emit qimageChanged();
}

void CVProcessor::setImageObject(const QVariant &imageObject)
{
    if (imageObject == m_imageObject)
        return;

    qDebug() << imageObject.typeName();

    m_imageObject = imageObject;
    emit imageObjectChanged();

}
