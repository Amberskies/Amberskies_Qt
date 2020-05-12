
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
#include "Amber3D/Extras/Input.h"

namespace Amber3D
{
    namespace OpenGL
    {
        Window3D::Window3D(QWindow* parent)
            : QOpenGLWindow(QOpenGLWindow::UpdateBehavior::NoPartialUpdate, parent)
            , m_modelWarehouse(nullptr)
        {
            m_projection.setToIdentity();
            setWidth(900);
            setHeight(500);
        }

        Window3D::~Window3D()
        {
            delete m_modelWarehouse;
        }

        void Window3D::UpdateWindow3D()
        {
            Input::update();
            paintGL();
            
        }

        /////////////////// Protected ///////////////////

        void Window3D::initializeGL()
        {
            QOpenGLFunctions_3_3_Core::initializeOpenGLFunctions();

            printf("OpenGL : %s\n",
                glGetString(GL_VERSION)
            );

            glClearColor(
                0.12f,      // red
                0.05f,      // green
                0.01f,      // blue
                1.00f       // alpha
            );

            glEnable(
                GL_DEPTH_TEST   // gfx card buffer
            );

            m_modelWarehouse = new ModelWarehouse(this);
            m_modelWarehouse->InitializeModelWarehouse();
        }

        void Window3D::paintGL()
        {
            glClear(GL_COLOR_BUFFER_BIT |
                    GL_DEPTH_BUFFER_BIT
                    );
            m_modelWarehouse->RenderAll(m_projection);
        }

        void Window3D::resizeGL(int width, int height)
        {
            float aspectRatio = static_cast<float>(width) / height;

            m_projection.setToIdentity();
            m_projection.perspective(FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);

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

    }
}
