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
SOURCES += main.cpp \
#test.cpp \
    map.cpp \
    localmap.cpp \
    globalmap.cpp \
    openmap.cpp \
    navigator.cpp

HEADERS +=  map.h \
# catch.hpp \
    localmap.h \
    globalmap.h \
    openmap.h \
    navigator.h
