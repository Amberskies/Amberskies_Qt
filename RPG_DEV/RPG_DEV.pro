
# ----------------------------------------------------/
#
# Project created by Frazor Sharp : 2020 Mar 12th
#
#      Amber 3D - Qt C++ Version Test 0.2
#
# Contact email  : amberskies@virginmail.com
# Website        : www.amberskies.org.uk
# Twitch         : FrazorBladezSharp
# Youtube        : Amberskies
#
# All code is free to use as you please
# Please be aware of the Open Source Licence
# given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
#
# ---------------------------------------------------*/

QT       += core gui opengl widgets


CONFIG += c11 c++17
#######################
CONFIG += debug
#CONFIG += release
#######################
SOURCES += \
    main.cpp \
    Test/TestWindow3D.cpp \
    Source/Platform/OpenGL/OpenGL.cpp



HEADERS += \
    Test/TestWindow3D.h \
    Source/Platform/OpenGL/OpenGL.h

FORMS += \
    Test/TestWindow3D.ui

unix:!macx: LIBS += -L$$PWD/../Amber3D_SL/build/ -lAmber3D_SL

INCLUDEPATH += $$PWD/../Amber3D_SL/Amber3D
DEPENDPATH += $$PWD/../Amber3D_SL/Amber3D

unix:!macx: PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/libAmber3D_SL.a
