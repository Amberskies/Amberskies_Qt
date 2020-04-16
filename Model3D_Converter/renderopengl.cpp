#include "renderopengl.h"
#include <QDebug>

RenderOpenGL::RenderOpenGL(QWidget *parent)
    : QOpenGLWidget(parent)
    , m_camera(new Amber3D::Entities::Camera(QVector3D(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, 0.0f))
    , m_entity(nullptr)
    , m_textureShader(nullptr)
    , m_colorShader(nullptr)
    , m_renderer(nullptr)
    , m_is_model_loaded(false)
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

RenderOpenGL::~RenderOpenGL()
{
    delete m_renderer;
    delete m_camera;
}

void RenderOpenGL::SetRendering(Amber3D::Entities::TexturedEntity *entity, Amber3D::API::TextureShader *textureShader, Amber3D::API::ColorShader *colorShader)
{
    m_entity        = entity;
    m_textureShader = textureShader;
    m_colorShader   = colorShader;
    m_is_model_loaded = true;
}

void RenderOpenGL::initializeGL()
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

    glClearColor(0.12f, 0.05f, 1.0f, 1.00f);
    glEnable(GL_DEPTH_TEST);

    qDebug() << "OpenGL : %s\n" <<
                glGetString(GL_VERSION);

    m_renderer = new Amber3D::OpenGL::Renderer(this);
}

void RenderOpenGL::paintGL()
{
    m_renderer->prepare();
    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );
    qDebug() << "Renderer Goes Here !.";

    if (m_is_model_loaded)
    {
        if (m_entity->GetTexturedModel()->GetRawModel()->GetHasTexture())
            m_renderer->render(
                        m_camera,
                        m_entity,
                        m_textureShader->GetProgramID(),
                        m_projection
                        );
//        else
//            m_renderer->render(
//                        m_camera,
//                        m_entity,
//                        m_colorShader->GetProgramID(),
//                        m_projection
//                        );
    }

}

void RenderOpenGL::resizeGL(int width, int height)
{
    float aspectRatio = static_cast<float>(width) / height;

    m_projection.setToIdentity();
    m_projection.perspective(FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);
}
