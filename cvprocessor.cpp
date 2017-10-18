#include "cvprocessor.h"

#include <QDebug>

#include <utils.h>

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
    cv::String name = Utils::toStdString(fileName.right(fileName.length() - 7));
    m_cvimage = cv::imread(name, cv::IMREAD_COLOR);
    m_qimage = Utils::cvMat2QImage(m_cvimage);

    emit qimageChanged();
}
