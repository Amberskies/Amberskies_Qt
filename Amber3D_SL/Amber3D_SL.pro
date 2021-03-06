
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

QT += core widgets gui

TEMPLATE = lib
CONFIG += staticlib
CONFIG += c11 c++17

TARGET = Amber3D_SL
############################################################
CONFIG += debug
#CONFIG += release
############################################################


#####################################################

SOURCES += \
    Amber3D/Entities/light.cpp \
    Amber3D/OpenGL/DrawColor.cpp \
    Amber3D/OpenGL/DrawTexture.cpp \
    Amber3D_SL.cpp \
    Amber3D/API/Loaders/GfxLoader.cpp \
    Amber3D/API/Loaders/LoadAmberModel.cpp \
    Amber3D/API/Shaders/ColorShader.cpp \
    Amber3D/API/Shaders/ShaderProgram.cpp \
    Amber3D/API/Shaders/TextureShader.cpp \
    Amber3D/Entities/Camera.cpp \
    Amber3D/Entities/ColorEntity.cpp \
    Amber3D/Entities/TexturedEntity.cpp \
    Amber3D/Extras/Input.cpp \
    Amber3D/Models/RawModel.cpp \
    Amber3D/Models/TexturedModel.cpp \
    Amber3D/OpenGL/BatchRender.cpp \
    Amber3D/Textures/ModelTexture.cpp

HEADERS += \
    Amber3D/Common.h \
    Amber3D/Entities/Light.h \
    Amber3D/OpenGL/DrawColor.h \
    Amber3D/OpenGL/DrawTexture.h \
    Amber3D_SL.h \
    Amber3D/API/Loaders/GfxLoader.h \
    Amber3D/API/Loaders/LoadAmberModel.h \
    Amber3D/API/Shaders/ColorShader.h \
    Amber3D/API/Shaders/ShaderProgram.h \
    Amber3D/API/Shaders/TextureShader.h \
    Amber3D/Entities/Camera.h \
    Amber3D/Entities/ColorEntity.h \
    Amber3D/Entities/TexturedEntity.h \
    Amber3D/Extras/Input.h \
    Amber3D/Maths/ClampRotation.h \
    Amber3D/Maths/CreateModelMatrix.h \
    Amber3D/Maths/CreateViewMatrix.h \
    Amber3D/Models/RawModel.h \
    Amber3D/Models/TexturedModel.h \
    Amber3D/OpenGL/BatchRender.h \
    Amber3D/Textures/ModelTexture.h
    
###################################################

# Default rules for deployment.
#unix {
#    target.path = $$[QT_INSTALL_PLUGINS]/generic
#}
#!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Amber3D/Resources/Shaders/BasicColor.fsh \
    Amber3D/Resources/Shaders/BasicColor.vsh \
    Amber3D/Resources/Shaders/Simplified.fsh \
    Amber3D/Resources/Shaders/Simplified.vsh
