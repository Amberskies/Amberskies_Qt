
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
#pragma once

#define DISPLAY_WIDTH 800           // pixels
#define DISPLAY_HEIGHT 400          // pixels

#define FOV 90.0f                   // degrees
#define NEAR_PLANE 0.1f             // meters
#define FAR_PLANE 50.0f             // meters


#include <iostream>

#include <QObject>
#include <QOpenGLWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLContext>
#include <QSurfaceFormat>
#include <QMatrix4x4>
#include <QTimer>
#include <QOpenGLShaderProgram>

#include <Amber3D/Entities/ColorEntity.h>
#include <Amber3D/Entities/TexturedEntity.h>
#include <Amber3D/Entities/Camera.h>

namespace Dev
{
    class Window3D : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
    {
        Q_OBJECT

        QMatrix4x4 m_projection;
        Amber3D::Entities::ColorEntity* m_colorEntity;
        Amber3D::Entities::TexturedEntity* m_texturedEntity;

        QOpenGLShaderProgram* m_currentShader;
        bool m_isTextured;
        QTimer* m_loop;
        Amber3D::Entities::Camera* m_camera;
        QOpenGLContext m_context;
        QSurfaceFormat m_format;
        float m_offset;

    public:
        Window3D(QWidget* parent = nullptr);
        ~Window3D();

        void PrepareColorModel(
            Amber3D::Entities::ColorEntity* currentEntity,
            QOpenGLShaderProgram* shader
        );

        void PrepareTexturedModel(
            Amber3D::Entities::TexturedEntity* currentEntity,
            QOpenGLShaderProgram* shader
        );

        void StartDisplay();

    protected:
        void initializeGL() override;
        void paintGL() override;
        void resizeGL(int w, int h) override;

    private slots:
        void MainLoop();

    private:

    };
}
