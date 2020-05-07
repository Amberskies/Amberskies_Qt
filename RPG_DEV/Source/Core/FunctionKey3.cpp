
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
    , m_Tmodel(nullptr)
    , m_Cmodel(nullptr)
    , m_texturedModel(nullptr)
    , m_loadAmberModel(new Amber3D::API::LoadAmberModel())
    //, m_texturedEntity(nullptr)
    //, m_colorEntity(nullptr)
    , m_camera(nullptr)
    , m_light(nullptr)
    , m_textureShader(new Amber3D::API::TextureShader())
    , m_colorShader(new Amber3D::API::ColorShader())
    , m_batchRender(new Amber3D::OpenGL::BatchRender(m_colorShader, m_textureShader, m_gl))
    
{
    // Empty 
}
FunctionKey3::~FunctionKey3()
{   
    delete m_batchRender;
    delete m_colorShader;
    delete m_textureShader;
    delete m_light;
    delete m_camera;
    //delete m_colorEntity;
    //delete m_texturedEntity;
    delete m_loadAmberModel;
    delete m_texturedModel;
    delete m_Cmodel;
    delete m_Tmodel;
}
void FunctionKey3::F3_Initialize()
{

    m_Tmodel = m_loadAmberModel->loadToGfx(
        "Head",
        m_colorShader->GetProgramID(),
        m_textureShader->GetProgramID()
    );        

	m_texturedModel = new Amber3D::Models::TexturedModel(
		m_Tmodel,
		m_loadAmberModel->GetTexture()
	);

    for (int instance = 0; instance < 10; instance++)
    {
        m_texturedEntity.push_back(new Amber3D::Entities::TexturedEntity(
            m_texturedModel,
            QVector3D(2.0f + (instance * 2), 0.0f + (instance * 2), -3.0f),          // Position
            0.0f,                                   // rotation X
            0.0f,                                   // rotation Y
            0.0f,                                   // rotation X
            1.0f                                    // scale where 1.0f == 100%
            )
        );
    }
    
    m_Cmodel = m_loadAmberModel->loadToGfx(
        "BoxRGB",
        m_colorShader->GetProgramID(),
        m_textureShader->GetProgramID()
    );

    for (int instance = 0; instance < 10; instance++)
    {
        m_colorEntity.push_back(new Amber3D::Entities::ColorEntity(
            m_Cmodel,
            QVector3D(-2.0f - (instance * 2), 0.0f + (instance * 2), -3.0f),          // Position
            0.0f,                                   // rotation X
            0.0f,                                   // rotation Y
            0.0f,                                   // rotation X
            1.0f                                    // scale where 1.0f == 100%
            )
        );
        
    }

    m_camera = new Amber3D::Entities::Camera(
        QVector3D(0.0f, 0.0f, 0.0f),
        0.0f,                                   // pitch (x-axis)
        0.0f,                                   // yaw   (y-axis)      
        0.0f                                    // roll  (z-axis)
    );

    m_light = new Amber3D::Entities::Light(
        QVector3D(0.0f, 0.0f, 10.0f),           // position
        QVector3D(0.8f, 0.8f, 0.8f)             // color
    );

    qDebug("F3 initialized");
}

void FunctionKey3::Go(QMatrix4x4 projection)
{
    
    // Game Logic

    m_camera->MoveCamera(0.03f); // sets camera move speed

    // add entities to our scene

    for (int instance = 0; instance < 10; instance++)
    {
        
        m_batchRender->AddTexturedEntity(
            m_texturedEntity[instance]->GetTexturedModel(),
            m_texturedEntity[instance]
        );
        // this is a test
        m_texturedEntity[instance]->IncreaseRotation(
            0.1f,                               // delta around X-axis
            0.1f,                               // delta around Y-axis
            0.0f
        );                                      // delta around Z-axis -ve = cw +ve = ccw

        m_batchRender->AddColorEntity(
            m_colorEntity[instance]->GetRawModel(),
            m_colorEntity[instance]
        );
        // this is a test
        m_colorEntity[instance]->IncreaseRotation(
            0.1f,                               // delta around X-axis
            0.1f,                               // delta around Y-axis
            0.0f                               // delta around Z-axis -ve = cw +ve = ccw
        );
    }

    // set shaders : optional

    // render all Models

    m_batchRender->Render(
        m_light,
        m_camera,
        projection
    );    
}
