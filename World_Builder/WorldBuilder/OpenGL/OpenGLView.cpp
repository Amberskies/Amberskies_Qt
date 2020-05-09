
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 May 07th
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
#include "OpenGLView.h"

OpenGLView::OpenGLView(QWidget* parent)
    : QOpenGLWidget(parent)
    , m_modelWarehouse(nullptr)
{
    // ** format used as I have no GFX card in this machine ** //
    m_format.setRedBufferSize(8);
    m_format.setGreenBufferSize(8);
    m_format.setBlueBufferSize(8);
    m_format.setAlphaBufferSize(8);
    m_format.setDepthBufferSize(32);
    m_format.setVersion(3, 3);
    m_format.setProfile(QSurfaceFormat::CoreProfile);
    this->setFormat(m_format);
}

OpenGLView::~OpenGLView()
{
    delete m_modelWarehouse;
}

/////////////// Protected //////////////////

void OpenGLView::initializeGL()
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
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // will only take effect when renderer is not working.
    glEnable(GL_DEPTH_TEST);

    printf("OpenGL : %s\n",
        glGetString(GL_VERSION)
    );

    /* ***** Init Amber **** */

    m_modelWarehouse = new ModelWarehouse(this);
    m_modelWarehouse->InitializeModelWarehouse();
}

void OpenGLView::paintGL()
{
    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );

    m_modelWarehouse->RenderAll(m_projection);
}

void OpenGLView::resizeGL(int width, int height)
{
    float aspectRatio = static_cast<float>(width) / height;

    m_projection.setToIdentity();
    m_projection.perspective(FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);

}
