#ifndef CVPROCESSOR_H
#define CVPROCESSOR_H

#include <QObject>
#include <QString>
#include <QImage>

#include "opencv2/opencv.hpp"

class CVProcessor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QImage qimage READ qimage NOTIFY qimageChanged)

public:
    explicit CVProcessor(QObject *parent = 0);

    QString fileName() { return m_fileName; }
    void setFileName(const QString &fileName);

    QImage qimage() { return m_qimage; }

signals:
    void fileNameChanged();
    void qimageChanged();

public slots:

private:
    QString m_fileName;
    QImage m_qimage;

    cv::Mat m_cvimage;
};

#endif // CVPROCESSOR_H
