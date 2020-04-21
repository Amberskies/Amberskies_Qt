
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
#include <Amber3D/Maths/CreateViewMatrix.h>

namespace Dev
{



    Window3D::Window3D(QWidget* parent)
        :   QOpenGLWidget(parent)
        ,   m_colorModel(nullptr)
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
            5.0f                    // move camera back 3 meters
        );
    }

    Window3D::~Window3D()
    {
        delete m_camera;
        delete m_loop;
    }

    void Window3D::PrepareColorModel(Amber3D::Models::RawModel* currentModel, QOpenGLShaderProgram* shader)
    {
        m_colorModel = currentModel;
        m_currentShader = shader;
        m_isTextured = false;
    }

    void Window3D::StartDisplay()
    {
        glClearColor(0.08f, 0.04f, 0.01f, 1.00f);
        m_loop->start(10);
    }

    //////////////////////////// PROTECTED ////////////////////////////

    void Window3D::initializeGL()
    {
        initializeOpenGLFunctions();
        std::cout << "Open GL Functions :" << std::endl;
        std::cout << glGetString(GL_VERSION) << std::endl;

        glClearColor(0.05f, 0.05f, 1.0f, 1.00f);
        glEnable(GL_DEPTH_TEST);
    }

    void Window3D::paintGL()
    {
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
        else if (m_colorModel != nullptr)
        {
            m_currentShader->bind();
            m_colorModel->GetVao()->bind();

            int locMVPmatrix =
                m_currentShader->uniformLocation(
                    "u_mvp"
                );

            m_currentShader->setUniformValue(
                locMVPmatrix,
                m_projection * viewMatrix * modelMatrix
            );

            this->glDrawElements(
                GL_TRIANGLES,
                m_colorModel->GetIndexCount(),
                GL_UNSIGNED_INT,
                0
            );

            m_colorModel->GetVao()->release();
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

        paintGL();
        this->update();

        m_loop->start(10);
    }
}
