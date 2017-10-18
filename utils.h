#ifndef UTILS_H
#define UTILS_H

#include <cv.h>
#include <opencv2/imgproc/imgproc.hpp>

#include <QImage>
#include <QString>

class Utils
{
public:
    Utils();

    static cv::Mat QImage2cvMat(QImage image);
    static QImage cvMat2QImage(const cv::Mat &mat);

    static std::string toStdString(QString qstring) { return qstring.toStdString(); }
    static QString toQString(std::string stdString) { QString qs; return qs.fromStdString(stdString); }
};

#endif // UTILS_H
