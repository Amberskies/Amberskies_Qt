
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Apr 21st
 *
 *      Amber3D 3D Model Converter - Qt C++
 *
 * Contact email  : amberskies@virginmail.com
 * Website        : www.amberskies.org.uk
 * Twitch         : FrazorBladezSharp
 * Youtube        : Amberskies
 * Github         : https://github.com/Amberskies
 *
 * All code is free to use as you please
 * Please be aware of the Open Source Licence
 * given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
 *
 * ---------------------------------------------------*/
#include "Window3D.h"

namespace Dev
{



    Window3D::Window3D(QWidget* parent)
        :   QOpenGLWidget(parent)
        ,   m_colorEntity(nullptr)
        ,   m_texturedEntity(nullptr)
        ,   m_currentShader(nullptr)
        ,   m_isTextured(false)
        ,   m_loop(new QTimer(this))
    {
        m_loop->setTimerType(Qt::PreciseTimer);
        connect(m_loop, SIGNAL(timeout()), this, SLOT(MainLoop()));

        m_camera = new Amber3D::Entities::Camera(
            QVector3D(0.0f, 0.0f, 0.0f),
            0.0f,
            0.0f,
            0.0f                    // move camera back 3 meters
        );

        // ** format used as I have no GFX card in this machine ** //
        m_format.setRedBufferSize(8);
        m_format.setGreenBufferSize(8);
        m_format.setBlueBufferSize(8);
        m_format.setAlphaBufferSize(8);
        m_format.setDepthBufferSize(32);
        m_format.setVersion(3, 3);
        m_format.setProfile(QSurfaceFormat::CoreProfile);
        this->setFormat(m_format);

        m_offset = 0.0f;
    }

    Window3D::~Window3D()
    {
        delete m_camera;
        delete m_loop;
    }

    void Window3D::PrepareColorModel(
        Amber3D::Entities::ColorEntity* currentEntity,
        QOpenGLShaderProgram* shader)
    {
        m_colorEntity = currentEntity;
        m_currentShader = shader;
        m_isTextured = false;
    }

    void Window3D::PrepareTexturedModel(
        Amber3D::Entities::TexturedEntity* currentEntity,
        QOpenGLShaderProgram* shader)
    {
        std::cout << "Model has texture (Code TODO:)" << std::endl;
    }

    void Window3D::StartDisplay()
    {
        glClearColor(0.08f, 0.04f, 0.01f, 1.00f);
        m_loop->start(10);
    }

    //////////////////////////// PROTECTED ////////////////////////////

    void Window3D::initializeGL()
    {
        QOpenGLFunctions_3_3_Core::initializeOpenGLFunctions();
        m_context.create();
        makeCurrent();

        std::cout << "Open GL Functions :" << std::endl;
        std::cout << glGetString(GL_VERSION) << std::endl;

        glClearColor(0.05f, 0.05f, 1.0f, 1.00f);
        glEnable(GL_DEPTH_TEST);
    }

    void Window3D::paintGL()
    {
        this->makeCurrent();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        QMatrix4x4 modelMatrix;
        modelMatrix.setToIdentity();

        QMatrix4x4 viewMatrix = Amber3D::Maths::CreateViewMatrix(
            m_camera
        );


        if (m_isTextured)
        {
            std::cout << "No code to draw Textures yet !" << std::endl;
        }
        else if (m_colorEntity != nullptr)
        {
            m_offset += 0.1f;
            if (m_offset >= 360) m_offset -= 360.0f;

            modelMatrix = Amber3D::Maths::CreateModelMatrix(
                m_colorEntity->GetPosition(),
                m_colorEntity->GetRotationX() + m_offset,
                m_colorEntity->GetRotationY() + m_offset,
                m_colorEntity->GetRotationZ(),
                m_colorEntity->GetScale()
            );

            m_currentShader->bind();
            m_colorEntity->GetRawModel()->GetVao()->bind();

            int locMVPmatrix =
                m_currentShader->uniformLocation(
                    "u_mvp"
                );

            m_currentShader->setUniformValue(
                locMVPmatrix,
                m_projection * viewMatrix * modelMatrix
            );

            glDrawElements(
                GL_TRIANGLES,
                m_colorEntity->GetRawModel()->GetIndexCount(),
                GL_UNSIGNED_INT,
                0
            );

            m_colorEntity->GetRawModel()->GetVao()->release();
            m_currentShader->release();

        }
    }

    void Window3D::resizeGL(int w, int h)
    {
        float aspectRatio = static_cast<float>(w) / h;

        m_projection.setToIdentity();
        m_projection.perspective(FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);
    }

    /////////////////// Private Slots ////////////////////////////////

    void Window3D::MainLoop()
    {
        m_loop->stop();

        this->update();

        m_loop->start(10);
    }
}
