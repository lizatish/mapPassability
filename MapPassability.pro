QT += core gui opengl

CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += /usr/include/GL
LIBS += -lglut

TEMPLATE = app
SOURCES += map.cpp \
    localmap.cpp \
    globalmap.cpp \
    openmap.cpp \
    navigator.cpp \
    robot.cpp \
    display.cpp \
    main.cpp \
    rosnode.cpp \
    mainwindow.cpp \
    #test.cpp \
    node.cpp \
    astarsearch.cpp


HEADERS +=  map.h \
    catch.hpp \
    localmap.h \
    globalmap.h \
    openmap.h \
    navigator.h \
    robot.h \
    display.h \
    rosnode.h \
     mainwindow.h \
    node.h \
    astarsearch.h

FORMS    += mainwindow.ui

#########################################################
#                          ROS
#########################################################

INCLUDEPATH += /opt/ros/kinetic/include

LIBS += -L/opt/ros/kinetic/lib
LIBS += -lroscpp -lrosconsole
LIBS += -lroscpp_serialization -lrostime
LIBS += -lxmlrpcpp -lcpp_common
LIBS += -lrosconsole -lrosconsole_backend_interface
LIBS += -lconsole_bridge -lrosconsole_log4cxx

#########################################################

