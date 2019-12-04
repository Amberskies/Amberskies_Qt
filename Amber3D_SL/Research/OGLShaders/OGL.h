#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLContext>
#include <QSurfaceFormat>
#include <QOpenGLShaderProgram>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include <QMatrix4x4>


class OGL : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

public:
    explicit OGL(QWidget *parent = nullptr);
    ~OGL() override;

    void resetCount();
    double getCount() { return m_counter; }

signals:

public slots:

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    QSurfaceFormat m_format;
    QOpenGLContext m_context;
    QOpenGLShaderProgram *m_shaderProgram;

    int m_position, m_color, m_mvp;
    float m_rotation;
    QMatrix4x4 m_model, m_view, m_perspective, m_fullMatrix;
    QOpenGLVertexArrayObject *m_testObject;
    QOpenGLBuffer *m_positionBuffer, *m_colorBuffer;
    QOpenGLBuffer *m_indexBuffer;

    double m_counter;
};

