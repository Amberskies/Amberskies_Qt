QT       += core gui widgets


CONFIG += c11 c++17
############################################################
CONFIG += debug

#CONFIG += release
############################################################

SOURCES += \
    main.cpp \
    ConverterWindow.cpp \
    renderopengl.cpp

HEADERS += \
    ConverterWindow.h \
    renderopengl.h

FORMS += \
    ConverterWindow.ui

DISTFILES += \ \
    Resources/AmberData/Body.nor \
    Resources/AmberData/Body.pos \
    Resources/AmberData/Body.tex \
    Resources/AmberData/Body.txn \
    Resources/AmberData/BoxRGB.col \
    Resources/AmberData/BoxRGB.nor \
    Resources/AmberData/BoxRGB.pos \
    Resources/AmberData/BoxRGB.txn \
    Resources/AmberData/Head.nor \
    Resources/AmberData/Head.pos \
    Resources/AmberData/Head.tex \
    Resources/AmberData/Head.txn \
    Resources/GLSL/BasicColor.frag \
    Resources/GLSL/BasicColor.vert \
    Resources/GLSL/BasicTexture.frag \
    Resources/GLSL/BasicTexture.vert \
    Resources/GLSL/Simplified.fsh \
    Resources/GLSL/Simplified.vsh \
    Resources/OBJ/Body.mtl \
    Resources/OBJ/Body.obj \
    Resources/OBJ/BoxRGB.mtl \
    Resources/OBJ/BoxRGB.obj \
    Resources/OBJ/Head.mtl \
    Resources/OBJ/Head.obj \
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



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Amber3D_SL/build/release/ -lAmber3D_SL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Amber3D_SL/build/debug/ -lAmber3D_SL

INCLUDEPATH += $$PWD/../Amber3D_SL
DEPENDPATH += $$PWD/../Amber3D_SL

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/release/libAmber3D_SL.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/debug/libAmber3D_SL.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/release/Amber3D_SL.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/debug/Amber3D_SL.lib
