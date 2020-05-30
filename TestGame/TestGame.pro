QT += core gui widgets

CONFIG += c11 c++17 console
CONFIG -= app_bundle

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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../AmberCore_SL/build/release/ -lAmberCore_SL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../AmberCore_SL/build/debug/ -lAmberCore_SL

INCLUDEPATH += $$PWD/../AmberCore_SL
DEPENDPATH += $$PWD/../AmberCore_SL

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../AmberCore_SL/build/release/libAmberCore_SL.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../AmberCore_SL/build/debug/libAmberCore_SL.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../AmberCore_SL/build/release/AmberCore_SL.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../AmberCore_SL/build/debug/AmberCore_SL.lib

DISTFILES += \
    Resources/AmberObjects/Body.amb \
    Resources/AmberObjects/BoxRGB.amb \
    Resources/AmberObjects/Dice.amb \
    Resources/AmberObjects/Head.amb \
    Resources/AmberObjects/PlainMesh50x50.amb \
    Resources/GLSL/BasicColor.frag \
    Resources/GLSL/BasicColor.vert \
    Resources/GLSL/BasicTexture.frag \
    Resources/GLSL/BasicTexture.vert \
    Resources/GLSL/Simplified.fsh \
    Resources/GLSL/Simplified.vsh \
    Resources/OBJ/Body.mtl \
    Resources/OBJ/BoxRGB.mtl \
    Resources/OBJ/Dice.mtl \
    Resources/OBJ/Head.mtl \
    Resources/OBJ/PlainMesh50x50.mtl \
    Resources/Shaders/GLSL/BasicShader.fs \
    Resources/Shaders/GLSL/BasicShader.vs \
    Resources/Shaders/GLSL/StaticShader.fs \
    Resources/Shaders/GLSL/StaticShader.vs \
    Resources/Shaders/GLSL/TerrainShader.fs \
    Resources/Shaders/GLSL/TerrainShader.vs \
    Resources/Shaders/ServerColor.frag \
    Resources/Shaders/ServerColor.vert \
    Resources/Shaders/ServerTexture.frag \
    Resources/Shaders/ServerTexture.vert \
    Resources/Shaders/basic.frag \
    Resources/Shaders/basic.vert \
    Resources/Textures/Blue.png \
    Resources/Textures/Gold.png \
    Resources/Textures/Terrain.png
