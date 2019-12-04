#include "Shaders.h"
#include "OGL.h"


OGL::OGL(QWidget *parent) : QOpenGLWidget(parent),
    m_shaderProgram(nullptr),

    m_position(-1),
    m_color(-1),
    m_mvp(-1),
    m_rotation(0), // rotation in degrees ?

    m_testObject(new QOpenGLVertexArrayObject),

    m_positionBuffer(new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer)),
    m_colorBuffer(new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer)),
    m_indexBuffer(new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer))
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

OGL::~OGL()
{
    m_indexBuffer->destroy();
    m_colorBuffer->destroy();
    m_positionBuffer->destroy();

    m_testObject->destroy();

    delete m_shaderProgram;
}

void OGL::resetCount()
{
    m_counter = 0.0;
}

/* ***** Protected ***** */

void OGL::initializeGL()
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
    glClearColor(0.20f, 0.05f, 0.01f, 1.00f);

    printf("OpenGL : %s\n",
           glGetString(GL_VERSION)
    );

    /* ***** Init Shader Variables ***** */
    m_shaderProgram = Shaders::CreateShader(Shaders::BasicColor);
    m_position = m_shaderProgram->attributeLocation("position");
    m_color = m_shaderProgram->attributeLocation("color");

    m_mvp = m_shaderProgram->uniformLocation("u_mvp");


    /* ***** Init Data for model ***** */
    GLfloat verts[] =
    {                           // index
         0.5f,  0.5f, 0.0f,     // 0
        -0.5f,  0.5f, 0.0f,     // 1
        -0.5f, -0.5f, 0.0f,     // 2
         0.5f, -0.5f, 0.0f      // 3
    };

    GLfloat colors[] =
    {                           // index
        1.0f, 1.0f, 1.0f, 1.0f, // 0
        1.0f, 0.0f, 0.0f, 1.0f, // 1
        0.0f, 1.0f, 0.0f, 1.0f, // 2
        0.0f, 0.0f, 1.0f, 1.0f, // 3
    };

    GLuint index[] =
    {
        0, 1, 2,
        2, 3, 0
    };

    // ** Vertex Array Object ** //
    m_testObject->create();
    m_testObject->bind();

    // ** Vertex Buffer Objects ** //
    // Position
    m_positionBuffer->create();
    m_positionBuffer->bind();
    m_positionBuffer->allocate(verts, sizeof(verts));
    m_shaderProgram->enableAttributeArray(m_position);
    m_shaderProgram->setAttributeBuffer(m_position, GL_FLOAT, 0, 3);
    // Color
    m_colorBuffer->create();
    m_colorBuffer->bind();
    m_colorBuffer->allocate(colors, sizeof(colors));
    m_shaderProgram->enableAttributeArray(m_color);
    m_shaderProgram->setAttributeBuffer(m_color, GL_FLOAT, 0, 4);

    // ** Index Buffer Object ** //
    m_indexBuffer->create();
    m_indexBuffer->bind();
    m_indexBuffer->allocate(index, sizeof(index));

    // ** cleanup and release the buffer memmory ** //
    m_testObject->release();
    m_indexBuffer->release();
    m_colorBuffer->release();
    m_positionBuffer->release();
    m_shaderProgram->release();


}

void OGL::paintGL()
{
    /* ***** Init matricies ***** */
    m_model.setToIdentity();
    m_view.setToIdentity();
    m_fullMatrix.setToIdentity();
    // starting Model Position
    m_model.translate(0.0f, 0.5f, -2.0f);

    /* ***** Prepare Draw ***** */
    m_rotation += 0.01f;
    if (m_rotation >= 360.0f) m_rotation -= 360.0f;
    m_model.rotate(m_rotation, 0.0f, 0.0f, 1.0f);

    m_fullMatrix = m_perspective * m_view * m_model;

    glClear(GL_COLOR_BUFFER_BIT);

    m_shaderProgram->bind();
    m_testObject->bind();
    m_shaderProgram->setUniformValue(m_mvp, m_fullMatrix);

    /* ***** OpenGL Draw ***** */
    //double time1 in ms / 1000
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    //double time2 in ms / 1000
    m_counter ++; // this will only give FPS - we need timers.
    // m_counter += time2 - time1;

    /* ***** Cleanup ***** */
    m_testObject->release();
    m_shaderProgram->release();

    /* ***** Que up the next draw call ***** */
    update();
}

void OGL::resizeGL(int width, int height)
{
    /* ***** Prepare Variables ***** */
    m_perspective.setToIdentity();
    float w = static_cast<float>(width);
    float h = static_cast<float>(height);
    float aspectRatio = w / h;

    // * ***** Set the Perspective Matrix ***** */
    m_perspective.perspective(65.0f, aspectRatio, 0.1f, 10.0f);
}
