
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

#include <Amber3D/Common.h>

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>

#include <Amber3D/API/Shaders/StaticShader.h>
#include <Amber3D/API/Loaders/GfxLoader.h>
#include <Amber3D/OpenGL/Renderer.h>

class FunctionKey3
{
    QOpenGLFunctions_3_3_Core *m_gl;
    Amber3D::API::StaticShader *m_shader;
    Amber3D::API::GfxLoader *m_loader;
    Amber3D::OpenGL::Renderer *m_renderer;
    Amber3D::Models::RawModel *m_model;

    public:
        FunctionKey3(QOpenGLFunctions_3_3_Core *gl);
        ~FunctionKey3();

        void F3_Initialize();
        void Go();

    private:
        //NULL_COPY_AND_ASSIGN(FunctionKey3)
};