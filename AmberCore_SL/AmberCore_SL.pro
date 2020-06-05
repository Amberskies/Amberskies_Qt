
# ----------------------------------------------------/
#
# Project created by Frazor Sharp : 2019 Dec 4th
#
#      Amber - Qt C++
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

QT += core gui widgets

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Amber/Comms/Chat.cpp \
    Amber/Comms/ChatBox.cpp \
    Amber/ECS/Ecs.cpp \
    Amber/ECS/EcsComponent.cpp \
    Amber/ECS/EcsSystem.cpp \
    AmberCore_SL.cpp

HEADERS += \
    Amber/Common.h \
    Amber/Comms/Chat.h \
    Amber/Comms/ChatBox.h \
    Amber/ECS/Array.h \
    Amber/ECS/Ecs.h \
    Amber/ECS/EcsComponent.h \
    Amber/ECS/EcsSystem.h \
    Amber/ECS/Map.h \
    Amber/Maths/dice.h \
    AmberCore_SL.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Amber3D_SL/build/release/ -lAmber3D_SL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Amber3D_SL/build/debug/ -lAmber3D_SL
else:unix: LIBS += -L$$PWD/../Amber3D_SL/build/ -lAmber3D_SL

INCLUDEPATH += $$PWD/../Amber3D_SL
DEPENDPATH += $$PWD/../Amber3D_SL

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/release/libAmber3D_SL.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/debug/libAmber3D_SL.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/release/Amber3D_SL.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/debug/Amber3D_SL.lib
else:unix: PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/libAmber3D_SL.a
