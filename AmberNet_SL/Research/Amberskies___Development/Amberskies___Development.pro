
# ----------------------------------------------------#
#
# Project created by Frazor Sharp : 2019 Nov 14th
#
#      Amber 3D - Qt C++
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
# ----------------------------------------------------#

QT -= gui
QT += core network

CONFIG += c++17 console
CONFIG -= app_bundle

#DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \
        NetDev/AmberTcpServer.cpp \
        NetDev/TcpMessenger.cpp \
        NetDev/TcpUsers.cpp \
        main.cpp

HEADERS += \
    NetDev/AmberTcpServer.h \
    NetDev/TcpMessenger.h \
    NetDev/TcpUsers.h


