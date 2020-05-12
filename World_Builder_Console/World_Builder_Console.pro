QT += core gui

CONFIG += c++17 console
CONFIG -= app_bundle


SOURCES += \
        WorldBuilder.cpp \
        main.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Amber3D_SL/build/release/ -lAmber3D_SL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Amber3D_SL/build/debug/ -lAmber3D_SL

INCLUDEPATH += $$PWD/../Amber3D_SL
DEPENDPATH += $$PWD/../Amber3D_SL

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/release/libAmber3D_SL.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/debug/libAmber3D_SL.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/release/Amber3D_SL.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/debug/Amber3D_SL.lib

HEADERS += \
    WorldBuilder.h

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
