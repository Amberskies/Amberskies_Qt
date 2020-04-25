
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
    , m_texturedModel(nullptr)
    , m_texture1(nullptr)
    , m_entity(nullptr)
    , m_camera(nullptr)
    , m_textureShader(new Amber3D::API::TextureShader())
    , m_colorShader(new Amber3D::API::ColorShader())
    , m_loader(new Amber3D::API::GfxLoader())
    , m_renderer(new Amber3D::OpenGL::Renderer(m_gl))
    
{
    // Empty 
}
FunctionKey3::~FunctionKey3()
{   
    delete m_renderer;
    delete m_loader;
    delete m_colorShader;
    delete m_textureShader;
    delete m_camera;
    delete m_entity;
    delete m_texture1;
    delete m_texturedModel;
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
        // 1.0f, 0.0f, 0.0f,
        // 0.0f, 1.0f, 0.0f,
        // 0.0f, 0.0f, 1.0f,
        // 1.0f, 1.0f, 1.0f,
    };

    float textureCoords [] =
    {
        //0
        0.0f, 0.0f,     // 0
        0.0f, 1.0f,     // 1
        1.0f, 1.0f,     // 2
        1.0f, 0.0f      // 3
    };

    m_loader->SetShader(
        m_colorShader->GetProgramID(),
        m_textureShader->GetProgramID()
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
    
    //if (m_model->GetHasTexture())
        // we cant use the if statement until we
        // give our model a default texture 
        // even it this only contains 1 pixel
        
        m_texture1 = new Amber3D::Textures::ModelTexture(
            m_loader->loadTexture(
                "Terrain"
            )
        );

    m_texturedModel = new Amber3D::Models::TexturedModel(
        m_model,
        m_texture1
    );
    
    m_entity = new Amber3D::Entities::TexturedEntity(
        m_texturedModel,
        QVector3D(0.0f, 0.0f, -1.0f),          // Position
        0.0f,                                   // rotation X
        0.0f,                                   // rotation Y
        0.0f,                                   // rotation X
        1.0f                                    // scale where 1.0f == 100%
    );

    m_camera = new Amber3D::Entities::Camera(
        QVector3D(0.0f, 0.0f, 0.0f),
        0.0f,                                   // pitch (x-axis)
        0.0f,                                   // yaw   (y-axis)      
        0.0f                                    // roll  (z-axis)
    );

    qDebug("F3 initialized");
}

void FunctionKey3::Go(QMatrix4x4 projection)
{
    m_renderer->prepare();
    
    // Game Logic

    m_camera->MoveCamera(0.03f);

    if (m_entity->GetTexturedModel()->GetRawModel()->GetHasTexture())
        m_renderer->render(
        m_camera,
        m_entity,
        m_textureShader->GetProgramID(),
        projection
    );    
    else 
        m_renderer->render(
        m_camera,
        m_entity,
        m_colorShader->GetProgramID(),
        projection
    );
    
    // this is a test
    m_entity->IncreaseRotation(
        0.0f,                               // delta around X-axis
        0.0f,                               // delta around Y-axis
        -0.1f                               // delta around Z-axis -ve = cw +ve = ccw
    );
}
