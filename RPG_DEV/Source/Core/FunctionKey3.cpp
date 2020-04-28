
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
    , m_loadAmberModel(new Amber3D::API::LoadAmberModel())
    , m_texturedEntity(nullptr)
    , m_colorEntity(nullptr)
    , m_camera(nullptr)
    , m_textureShader(new Amber3D::API::TextureShader())
    , m_colorShader(new Amber3D::API::ColorShader())
    , m_renderer(new Amber3D::OpenGL::Renderer(m_gl))
    
{
    // Empty 
}
FunctionKey3::~FunctionKey3()
{   
    delete m_renderer;
    delete m_colorShader;
    delete m_textureShader;
    delete m_camera;
    delete m_colorEntity;
    delete m_texturedEntity;
    delete m_loadAmberModel;
    delete m_texturedModel;
    delete m_model;
}
void FunctionKey3::F3_Initialize()
{

    m_model = m_loadAmberModel->loadToGfx(
        "Body",
        m_colorShader->GetProgramID(),
        m_textureShader->GetProgramID()
    );

    if (m_loadAmberModel->GetHasTexture())
    {
        

        m_texturedModel = new Amber3D::Models::TexturedModel(
            m_model,
            m_loadAmberModel->GetTexture()
        );

        m_texturedEntity = new Amber3D::Entities::TexturedEntity(
            m_texturedModel,
            QVector3D(0.0f, 0.0f, -3.0f),          // Position
            0.0f,                                   // rotation X
            0.0f,                                   // rotation Y
            0.0f,                                   // rotation X
            1.0f                                    // scale where 1.0f == 100%
        );
    }
    else
    {
        m_colorEntity = new Amber3D::Entities::ColorEntity(
            m_model,
            QVector3D(0.0f, 0.0f, -3.0f),          // Position
            0.0f,                                   // rotation X
            0.0f,                                   // rotation Y
            0.0f,                                   // rotation X
            1.0f                                    // scale where 1.0f == 100%
        );
    }

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

    m_camera->MoveCamera(0.03f); // sets camera move speed

    if (m_texturedEntity->GetTexturedModel()->GetRawModel()->GetHasTexture())
    {
        m_renderer->render(
            m_camera,
            m_texturedEntity,
            m_textureShader->GetProgramID(),
            projection
        );

        // this is a test
        m_texturedEntity->IncreaseRotation(
            0.1f,                               // delta around X-axis
            0.1f,                               // delta around Y-axis
            0.0f
        );                                      // delta around Z-axis -ve = cw +ve = ccw
    }
    else
    {
        //m_renderer->render(
        //    m_camera,
        //    m_colorEntity,
        //    m_colorShader->GetProgramID(),
        //    projection
        //);

        //// this is a test
        //m_colorEntity->IncreaseRotation(
        //    0.1f,                               // delta around X-axis
        //    0.1f,                               // delta around Y-axis
        //    0.0f                               // delta around Z-axis -ve = cw +ve = ccw
        //);
    }
}
