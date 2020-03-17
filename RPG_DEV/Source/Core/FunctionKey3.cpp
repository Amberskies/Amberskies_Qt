
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
#include "FunctionKey3.h"
#include <QDebug>

FunctionKey3::FunctionKey3(QOpenGLFunctions_3_3_Core *gl)
    : m_gl(gl)
    , m_shader(Amber3D::API::LoadShaders(Amber3D::API::Simplified))
    , m_loader(new Amber3D::API::GfxLoader())
    , m_renderer(new Amber3D::OpenGL::Renderer(m_gl))
    , m_model(nullptr)
{
    // Empty 
}
FunctionKey3::~FunctionKey3()
{
    //empty
}
void FunctionKey3::F3_Initialize()
{
    
    float vertices [] =
    {
        // Left Bottom Triangle
        -0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        // Right Top Triangle
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    m_loader->SetShader(m_shader);
    m_model = m_loader->LoadToVAO(vertices, sizeof(vertices) / sizeof(float));
    qDebug("F3 initialized");
}

void FunctionKey3::Go()
{
    m_renderer->prepare();
    // Game Logic
    m_renderer->render(m_model, m_shader);
}