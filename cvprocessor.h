#ifndef CVPROCESSOR_H
#define CVPROCESSOR_H

#include <QObject>
#include <QString>
#include <QPixmap>
#include <QImage>

#include <QVariant>

#include "opencv2/opencv.hpp"

class CVProcessor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QPixmap image READ image NOTIFY imageChanged)
    Q_PROPERTY(QImage qimage READ qimage NOTIFY qimageChanged)

    Q_PROPERTY(QVariant imageObject READ imageObject WRITE setImageObject NOTIFY imageObjectChanged)

public:
    explicit CVProcessor(QObject *parent = 0);

    QString fileName() { return m_fileName; }
    void setFileName(const QString &fileName);

    QPixmap image() { return m_image; }
    QImage qimage() { return m_qimage; }

    QVariant imageObject() { return m_imageObject; }
    void setImageObject(const QVariant &imageObject);

signals:
    void fileNameChanged();
    void imageChanged();
    void qimageChanged();
    void imageObjectChanged();

public slots:

private:
    QString m_fileName;
    QPixmap m_image;
    QVariant m_imageObject;
    QImage m_qimage;

    cv::Mat m_cvimage;
};

#endif // CVPROCESSOR_H
