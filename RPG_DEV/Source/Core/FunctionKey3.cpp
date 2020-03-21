
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
    , m_model(nullptr)
    , m_texture1(nullptr)
    , m_textureShader(new Amber3D::API::TextureShader())
    , m_loader(new Amber3D::API::GfxLoader())
    , m_renderer(new Amber3D::OpenGL::Renderer(m_gl))
    
{
    // Empty 
}
FunctionKey3::~FunctionKey3()
{   
    delete m_renderer;
    delete m_model;
}
void FunctionKey3::F3_Initialize()
{
    uint indices [] =
    {
        0, 1, 3,
        3, 1, 2 
    };

    float vertices [] =
    {
        // Left Bottom Triangle
        -0.5f,  0.5f, 0.0f, // 0
        -0.5f, -0.5f, 0.0f, // 1
         0.5f, -0.5f, 0.0f, // 2
         0.5f,  0.5f, 0.0f, // 3
    };

    float colors [] =
    {
        0
    };

    float textureCoords [] =
    {
        0.0f, 0.0f,     // 0
        0.0f, 1.0f,     // 1
        1.1f, 1.1f,     // 2
        1.0f, 0.0f      // 3
    };

    m_loader->SetShader(
        m_textureShader
    );

    m_model = 
        m_loader->LoadToVAO(
            indices,
            sizeof(indices) /sizeof(uint),
            vertices,
            sizeof(vertices) / sizeof(float),
            colors,
            sizeof(colors) / sizeof(float),
            textureCoords,
            sizeof(textureCoords) / sizeof(float)
    );
    
    m_texture1 = new Amber3D::Textures::ModelTexture(
        m_loader->loadTexture(
            "thing"
        )
    );

    m_texturedModel = new Amber3D::Models::TexturedModel(
        m_model,
        m_texture1
    );

    qDebug("F3 initialized");
}

void FunctionKey3::Go()
{
    m_renderer->prepare();
    
    // Game Logic
    
    m_renderer->render(
        m_texturedModel,
        m_textureShader
    );
}
