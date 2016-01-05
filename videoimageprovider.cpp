#include "videoimageprovider.h"
#include <QDebug>

#include "iostream"
#include "stdio.h"

#include "highgui.h"
#include "cv.h"
#include <QTimer>
#include <QImage>
#include <QPainter>
#include "opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

VideoImageProvider::VideoImageProvider()
    : QQuickImageProvider(QQuickImageProvider::Pixmap)
{
    capture_ = VideoCapture(0);

}

VideoImageProvider::~VideoImageProvider()
{
    capture_.release();
}

QPixmap VideoImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Mat frame;
    QImage img;
    capture_ >> frame;
    img = Mat2QImage(frame);

    return QPixmap::fromImage(img.mirrored(true, false));
}

QImage VideoImageProvider::MatToQImage(const Mat &mat)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
     if(mat.type()==CV_8UC1)
     {
         // Set the color table (used to translate colour indexes to qRgb values)
         QVector<QRgb> colorTable;
         for (int i=0; i<256; i++)
             colorTable.push_back(qRgb(i,i,i));
         // Copy input Mat
         const uchar *qImageBuffer = (const uchar*)mat.data;
         // Create QImage with same dimensions as input Mat
         QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
         img.setColorTable(colorTable);
         return img;
     }
     // 8-bits unsigned, NO. OF CHANNELS=3
     if(mat.type()==CV_8UC3)
     {
         // Copy input Mat
         const uchar *qImageBuffer = (const uchar*)mat.data;
         // Create QImage with same dimensions as input Mat
         QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
         return img.rgbSwapped();
     }
     else
     {
         qDebug() << "ERROR: Mat could not be converted to QImage.";
         return QImage();
     }
}

QImage VideoImageProvider::Mat2QImage(const Mat &src)
{
    cv::Mat temp; // make the same cv::Mat
    cvtColor(src, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
    QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    dest.bits(); // enforce deep copy, see documentation
    // of QImage::QImage ( const uchar * data, int width, int height, Format format )
    return dest;
}

