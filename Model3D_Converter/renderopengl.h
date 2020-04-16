#ifndef RENDEROPENGL_H
#define RENDEROPENGL_H

#define FOV 90.0f
#define NEAR_PLANE 0.1f
#define FAR_PLANE 50.0f

#include <QObject>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLContext>
#include <QSurfaceFormat>
#include <QMatrix4x4>
#include <QVector3D>

#include <Amber3D/Entities/Camera.h>
#include <Amber3D/OpenGL/Renderer.h>
#include <Amber3D/Entities/TexturedEntity.h>
#include <Amber3D/API/Shaders/ColorShader.h>
#include <Amber3D/API/Shaders/TextureShader.h>

class RenderOpenGL : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

    QSurfaceFormat m_format;
    QOpenGLContext m_context;
    QMatrix4x4 m_projection;

    Amber3D::Entities::Camera *m_camera;
    Amber3D::Entities::TexturedEntity* m_entity;
    Amber3D::API::TextureShader* m_textureShader;
    Amber3D::API::ColorShader* m_colorShader;
    Amber3D::OpenGL::Renderer *m_renderer;

    bool m_is_model_loaded;

public:
    explicit RenderOpenGL(QWidget *parent = nullptr);
    ~RenderOpenGL();

    void SetRendering(
            Amber3D::Entities::TexturedEntity* entity,
            Amber3D::API::TextureShader* textureShader,
            Amber3D::API::ColorShader* colorShader);

signals:

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;


};

#endif // RENDEROPENGL_H
