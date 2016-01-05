TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    videoimageprovider.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    videoimageprovider.h

INCLUDEPATH += C:/OpenCV/necessary_file/include/opencv\
        C:/OpenCV/necessary_file/include/opencv2\
        C:/OpenCV/necessary_file/include

LIBS += -L C:/OpenCV/necessary_file/lib/libopencv_*.a

