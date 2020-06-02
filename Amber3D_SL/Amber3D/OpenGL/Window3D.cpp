
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 May 11th
 *
 *      Amber3D - Qt C++
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
#include "Amber3D/Gui_3D/Input.h"
#include <QDebug>

namespace Amber3D
{
    namespace OpenGL
    {
        Window3D::Window3D(QWindow* parent)
            : QOpenGLWindow(QOpenGLWindow::UpdateBehavior::NoPartialUpdate, parent)
            , m_modelWarehouse(nullptr)
        {
            m_projection.setToIdentity();

            // ** format used as I have no GFX card in this machine ** //
            //m_format.setRedBufferSize(8);
            //m_format.setGreenBufferSize(8);
            //m_format.setBlueBufferSize(8);
            //m_format.setAlphaBufferSize(8);
            //m_format.setDepthBufferSize(32);
            //m_format.setVersion(3, 3);
            //m_format.setProfile(QSurfaceFormat::CoreProfile);
            //this->setFormat(m_format);
        }

        Window3D::~Window3D()
        {
            delete m_modelWarehouse;
        }

        void Window3D::UpdateWindow3D()
        {
            Input::update();
           
            if (Input::keyPressed(Qt::Key_Escape)) this->close();
            update();
            
        }

        void Window3D::SetShaders(QString colorShader, QString textureShader)
        {
            m_modelWarehouse->SetShaders(
                colorShader,
                textureShader
            );
        }

        /////////////////// Protected ///////////////////

        void Window3D::initializeGL()
        {
            initializeOpenGLFunctions();
            m_context.create();
            makeCurrent();

            PrintVersionInfo();

            glClearColor(
                0.12f,      // red
                0.05f,      // green
                0.01f,      // blue
                1.00f       // alpha
            );

            glEnable(
                GL_DEPTH_TEST   // gfx card buffer
            );

            m_modelWarehouse = new ModelWarehouse(
                "PhongColor",
                "PhongTexture",
                this
            );

            m_modelWarehouse->InitializeModelWarehouse();
        }

        void Window3D::paintGL()
        {
            glClear(GL_COLOR_BUFFER_BIT |
                    GL_DEPTH_BUFFER_BIT
                    );
            
            //QPoint mousePos = this->mapFromGlobal(
           //     Input::mousePosition()
           // );
            
            m_modelWarehouse->RenderAll(
                //this->height(),
                //mousePos,
                m_projection
            );
        }

        void Window3D::resizeGL(int width, int height)
        {
            float aspectRatio = static_cast<float>(width) / height;

            m_projection.setToIdentity();
            m_projection.perspective(FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);
            m_modelWarehouse->setWindow(QPoint(this->width(),this->height()));

        }

        void Window3D::mousePressEvent(QMouseEvent* event)
        {
            Input::registerMousePress(event->button());
        }

        void Window3D::mouseReleaseEvent(QMouseEvent* event)
        {
            Input::registerMouseRelease(event->button());
        }

        void Window3D::keyPressEvent(QKeyEvent* event)
        {
            if (event->isAutoRepeat())
            {
                event->ignore();
            }
            else
            {
                Input::registerKeyPress(event->key());
            }
        }

        void Window3D::keyReleaseEvent(QKeyEvent* event)
        {
            if (event->isAutoRepeat())
            {
                event->ignore();
            }
            else
            {
                Input::registerKeyRelease(event->key());
            }
        }

        // /////////////////////// Private ////////////////////////////

        void Window3D::PrintVersionInfo()
        {
            QString glType;
            QString glVersion;
            QString glProfile;

            glType = (context()->isOpenGLES()) ? "OpenGL ES" : "OpenGL";
            glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));

#define CASE(c) case QSurfaceFormat::c: glProfile = #c; break

            switch (format().profile())
            {
                CASE(NoProfile);
                CASE(CoreProfile);
                CASE(CompatibilityProfile);
            }
#undef CASE
            qDebug() << qPrintable(glType)
                << qPrintable(glVersion)
                << "("
                << qPrintable(glVersion)
                << ")";
        }
    }
}
