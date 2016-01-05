#ifndef VIDEOIMAGEPROVIDER_H
#define VIDEOIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QPixmap>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <cv.h>
using namespace cv;
using namespace std;

class VideoImageProvider : public QQuickImageProvider
{
public:
    VideoImageProvider();
    ~VideoImageProvider();

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

    QImage MatToQImage(const Mat& mat);
    QImage Mat2QImage(cv::Mat const& src);

private:
    VideoCapture capture_;
};


#endif // VIDEOIMAGEPROVIDER_H
