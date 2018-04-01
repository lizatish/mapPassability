#############################################################################
# Makefile for building: opencv
# Generated by qmake (3.0) (Qt 5.7.0)
# Project:  ../Map Passability DOTTWORK/mapPassability.pro
# Template: app
# Command: /home/liza/Qt5.7.0/5.7/gcc_64/bin/qmake -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ../Map\ Passability\ DOTTWORK/mapPassability.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_QML_DEBUG -DQT_OPENGL_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I../Map\ Passability\ DOTTWORK -I. -isystem /usr/local/include/opencv -isystem /usr/include/GL -I../../Qt5.7.0/5.7/gcc_64/include -I../../Qt5.7.0/5.7/gcc_64/include/QtOpenGL -I../../Qt5.7.0/5.7/gcc_64/include/QtWidgets -I../../Qt5.7.0/5.7/gcc_64/include/QtGui -I../../Qt5.7.0/5.7/gcc_64/include/QtCore -I. -I../../Qt5.7.0/5.7/gcc_64/mkspecs/linux-g++
QMAKE         = /home/liza/Qt5.7.0/5.7/gcc_64/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = opencv1.0.0
DISTDIR = /home/liza/!QTProjects/mapPassability/.tmp/opencv1.0.0
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/liza/Qt5.7.0/5.7/gcc_64/lib
LIBS          = $(SUBLIBS) -lopencv_core -lopencv_videoio -lopencv_imgcodecs -lopencv_imgproc -lopencv_calib3d -lopencv_video -lopencv_features2d -lopencv_ml -lopencv_highgui -lopencv_objdetect -lglut -L/home/liza/Qt5.7.0/5.7/gcc_64/lib -lQt5OpenGL -L/usr/lib64 -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ../Map\ Passability\ DOTTWORK/main.cpp 
OBJECTS       = main.o
DIST          = ../../Qt5.7.0/5.7/gcc_64/mkspecs/features/spec_pre.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/unix.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/linux.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/sanitize.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/gcc-base.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/g++-base.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/g++-unix.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/qconfig.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dcore.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dextras.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dextras_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dinput.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dlogic.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquick.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickextras.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickinput.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickrender.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3drender.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3drender_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gamepad.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gamepad_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_location.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_location_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_purchasing.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_purchasing_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickcontrols2.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scxml.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scxml_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialbus.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialbus_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_uiplugin.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webengine.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webview.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webview_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qt_functions.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qt_config.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/spec_post.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/default_pre.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/resolve_config.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/default_post.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qml_debug.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/warn_on.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qt.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/resources.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/moc.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/unix/opengl.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/uic.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/unix/thread.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/file_copies.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/testcase_targets.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/exceptions.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/yacc.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/lex.prf \
		../Map Passability DOTTWORK/mapPassability.pro  ../Map\ Passability\ DOTTWORK/main.cpp
QMAKE_TARGET  = opencv
DESTDIR       = 
TARGET        = opencv


first: all
####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ../Map\ Passability\ DOTTWORK/mapPassability.pro ../../Qt5.7.0/5.7/gcc_64/mkspecs/linux-g++/qmake.conf ../../Qt5.7.0/5.7/gcc_64/mkspecs/features/spec_pre.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/unix.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/linux.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/sanitize.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/gcc-base.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/g++-base.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/common/g++-unix.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/qconfig.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dcore.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dextras.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dextras_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dinput.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dlogic.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquick.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickextras.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickinput.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickrender.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3drender.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3drender_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gamepad.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gamepad_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_location.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_location_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_purchasing.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_purchasing_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickcontrols2.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scxml.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scxml_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialbus.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialbus_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_uiplugin.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webengine.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webview.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webview_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qt_functions.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qt_config.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/spec_post.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/default_pre.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/resolve_config.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/default_post.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qml_debug.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/warn_on.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qt.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/resources.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/moc.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/unix/opengl.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/uic.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/unix/thread.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/file_copies.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/testcase_targets.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/exceptions.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/yacc.prf \
		../../Qt5.7.0/5.7/gcc_64/mkspecs/features/lex.prf \
		../Map\ Passability\ DOTTWORK/mapPassability.pro \
		../../Qt5.7.0/5.7/gcc_64/lib/libQt5OpenGL.prl \
		../../Qt5.7.0/5.7/gcc_64/lib/libQt5Widgets.prl \
		../../Qt5.7.0/5.7/gcc_64/lib/libQt5Gui.prl \
		../../Qt5.7.0/5.7/gcc_64/lib/libQt5Core.prl
	$(QMAKE) -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ../Map\ Passability\ DOTTWORK/mapPassability.pro
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/spec_pre.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/common/unix.conf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/common/linux.conf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/common/sanitize.conf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/common/gcc-base.conf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/common/gcc-base-unix.conf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/common/g++-base.conf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/common/g++-unix.conf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/qconfig.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dcore.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dcore_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dextras.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dextras_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dinput.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dinput_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dlogic.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dlogic_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquick.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquick_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickextras.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickextras_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickinput.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickinput_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickrender.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3dquickrender_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3drender.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_3drender_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_concurrent.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_core.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_core_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_dbus.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_designer.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_designer_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gamepad.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gamepad_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gui.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_gui_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_help.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_help_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_location.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_location_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimedia.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_network.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_network_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_nfc.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_opengl.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_packetprotocol_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_positioning.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_printsupport.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_purchasing.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_purchasing_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qml.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qml_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmldebug_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmltest.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quick.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quick_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickcontrols2.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_script.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_script_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scripttools.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scxml.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_scxml_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sensors.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialbus.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialbus_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialport.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sql.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_sql_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_svg.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_svg_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_testlib.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_uiplugin.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_uitools.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webchannel.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webengine.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_websockets.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webview.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_webview_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_widgets.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_x11extras.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xml.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xml_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qt_functions.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qt_config.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/linux-g++/qmake.conf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/spec_post.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/exclusive_builds.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/default_pre.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/resolve_config.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/default_post.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qml_debug.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/warn_on.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/qt.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/resources.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/moc.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/unix/opengl.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/uic.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/unix/thread.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/file_copies.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/testcase_targets.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/exceptions.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/yacc.prf:
../../Qt5.7.0/5.7/gcc_64/mkspecs/features/lex.prf:
../Map\ Passability\ DOTTWORK/mapPassability.pro:
../../Qt5.7.0/5.7/gcc_64/lib/libQt5OpenGL.prl:
../../Qt5.7.0/5.7/gcc_64/lib/libQt5Widgets.prl:
../../Qt5.7.0/5.7/gcc_64/lib/libQt5Gui.prl:
../../Qt5.7.0/5.7/gcc_64/lib/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile ../Map\ Passability\ DOTTWORK/mapPassability.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents ../Map\ Passability\ DOTTWORK/main.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: ../Map\ Passability\ DOTTWORK/main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../Map\ Passability\ DOTTWORK/main.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

