QT += core gui opengl

CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += /usr/include/GL
LIBS += -lglut

TEMPLATE = app
SOURCES += test.cpp \
    map.cpp \
    localmap.cpp \
    globalmap.cpp \
    openmap.cpp \
    navigator.cpp \
    robot.cpp \
    display.cpp \
    #main.cpp \

HEADERS +=  map.h \
    catch.hpp \
    localmap.h \
    globalmap.h \
    openmap.h \
    navigator.h \
    robot.h \
    display.h
