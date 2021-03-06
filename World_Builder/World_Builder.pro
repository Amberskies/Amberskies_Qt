QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

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
    WorldBuilder/OpenGL/ModelWarehouse.cpp \
    WorldBuilder/OpenGL/OpenGLView.cpp \
    main.cpp \
    worldwindow.cpp

HEADERS += \
    WorldBuilder/OpenGL/ModelWarehouse.h \
    WorldBuilder/OpenGL/OpenGLView.h \
    worldwindow.h

FORMS += \
    worldwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/../Amber3D_SL/build/debug/ -lAmber3D_SL

INCLUDEPATH += $$PWD/../Amber3D_SL
DEPENDPATH += $$PWD/../Amber3D_SL

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/debug/Amber3D_SL.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/debug/libAmber3D_SL.a

DISTFILES += \
    Resources/AmberModels/Body.amb \
    Resources/AmberModels/BoxRGB.amb \
    Resources/AmberModels/Default/DefaultMap.txt \
    Resources/AmberModels/Default/DefaultModels.txt \
    Resources/AmberModels/Head.amb \
    Resources/AmberModels/PlainMesh50x50.amb \
    Resources/GLSL/BasicColor.frag \
    Resources/GLSL/BasicColor.vert \
    Resources/GLSL/BasicTexture.frag \
    Resources/GLSL/BasicTexture.vert \
    Resources/GLSL/PhongColor.frag \
    Resources/GLSL/PhongColor.vert \
    Resources/GLSL/PhongTexture.frag \
    Resources/GLSL/PhongTexture.vert \
    Resources/GLSL/Simplified.fsh \
    Resources/GLSL/Simplified.vsh \
    Resources/OBJ/Body.mtl \
    Resources/OBJ/BoxRGB.mtl \
    Resources/OBJ/Head.mtl \
    Resources/OBJ/PlainMesh50x50.mtl \
    Resources/Textures/Blue.png \
    Resources/Textures/Gold.png \
    Resources/Textures/Terrain.png
