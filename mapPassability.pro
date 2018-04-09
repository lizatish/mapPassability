QT += core gui opengl

CONFIG += c++11


TARGET = opencv
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += /usr/local/include/opencv
LIBS += -lopencv_core \
 -lopencv_videoio \
 -lopencv_imgcodecs \
 -lopencv_imgproc \
 -lopencv_calib3d \
 -lopencv_video \
 -lopencv_features2d \
 -lopencv_ml \
 -lopencv_highgui \
 -lopencv_objdetect

INCLUDEPATH += /usr/include/GL
LIBS += -lglut

TEMPLATE = app
SOURCES += globalmap.cpp \
main.cpp \
#test.cpp \

HEADERS += globalmap.h \
 catch.hpp \
