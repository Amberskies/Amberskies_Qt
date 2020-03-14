
# ----------------------------------------------------/
#
# Project created by Frazor Sharp : 2019 Dec 4th
#
#      Amber3D - Qt C++
#
# Contact email  : amberskies@virginmail.com
# Website        : www.amberskies.org.uk
# Twitch         : FrazorBladezSharp
# Youtube        : Amberskies
# Github         : https://github.com/Amberskies
#
# All code is free to use as you please
# Please be aware of the Open Source Licence
# given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
#
# ---------------------------------------------------*/

QT -= gui
QT += core widgets opengl

TEMPLATE = lib
CONFIG += staticlib
CONFIG += c11 c++17

TARGET = Amber3D_SL

#####################################################

SOURCES += \
    Amber3D_SL.cpp \
    Amber3D/API/Shaders/LoadShaders.cpp

HEADERS += \
    Amber3D_SL.h \
    Amber3D/API/Shaders/LoadShaders.h

###################################################

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Amber3D/Resources/Shaders/BasicColor.fsh \
    Amber3D/Resources/Shaders/BasicColor.vsh \
    Amber3D/Resources/Shaders/Simplified.fsh \
    Amber3D/Resources/Shaders/Simplified.vsh
