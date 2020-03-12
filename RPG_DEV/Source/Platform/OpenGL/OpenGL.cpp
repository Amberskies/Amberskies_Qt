
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 12th
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


#include "OpenGL.h"

OpenGL::OpenGL(QWidget *parent) : QOpenGLWidget(parent),
    m_function(0)
{
    // ** format used as I have no GFX card in this machine ** //
    m_format.setRedBufferSize(8);
    m_format.setGreenBufferSize(8);
    m_format.setBlueBufferSize(8);
    m_format.setAlphaBufferSize(8);
    m_format.setDepthBufferSize(64);
    m_format.setVersion(3, 3);
    m_format.setProfile(QSurfaceFormat::CoreProfile);
    this->setFormat(m_format);
}

OpenGL::~OpenGL()
{
    // empty
}

// **************** Protected *****************

void OpenGL::initializeGL()
{
        /* ***** Init OpenGL ***** */
    this->initializeOpenGLFunctions();
    m_context.create();
    makeCurrent();

    if (!this->isInitialized())
    {
        printf("Unable to Initialize OpenGL 3.3 Core.\n");
        exit(99);
    }
    glClearColor(1.00f, 0.05f, 0.01f, 1.00f);

    printf("OpenGL : %s\n",
           glGetString(GL_VERSION)
    );

}

void OpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //update();
}

void OpenGL::resizeGL(int width, int height)
{
    // empty
}

// ********************************************