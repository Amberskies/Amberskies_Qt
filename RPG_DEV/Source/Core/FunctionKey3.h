
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 14th
 *
 *      Amber 3D - Qt C++ Version Test 0.2
 *
 * Contact email  : amberskies@virginmail.com
 * Website        : www.amberskies.org.uk
 * Twitch         : FrazorBladezSharp
 * Youtube        : Amberskies
 *
 * All code is free to use as you please
 * Please be aware of the Open Source Licence
 * given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
 *
 * ---------------------------------------------------*/
#pragma once
#include "Source/Common.h"
#include <Amber3D/Common.h>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>
#include <QMatrix4x4>
#include <Amber3D/API/Loaders/GfxLoader.h>
#include <Amber3D/API/Shaders/TextureShader.h>
#include <Amber3D/Models/RawModel.h>
#include <Amber3D/Models/TexturedModel.h>
#include <Amber3D/OpenGL/Renderer.h>
#include <Amber3D/Textures/ModelTexture.h>
#include <Amber3D/Entities/TexturedEntity.h>
#include <Amber3D/Entities/Camera.h>


class FunctionKey3
{
    QOpenGLFunctions_3_3_Core *m_gl;
    Amber3D::Models::RawModel *m_model;
    Amber3D::Models::TexturedModel *m_texturedModel;
    Amber3D::Textures::ModelTexture *m_texture1;
    Amber3D::Entities::TexturedEntity *m_texturedEntity;
    
    Amber3D::Entities::Camera *m_camera;

    Amber3D::API::TextureShader *m_textureShader;
    Amber3D::API::GfxLoader *m_loader;
    Amber3D::OpenGL::Renderer *m_renderer;
    

    public:
        FunctionKey3(
            QOpenGLFunctions_3_3_Core *gl);

        ~FunctionKey3();

        void F3_Initialize();
        
        void Go(
            QMatrix4x4 projection);
};
