
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
#pragma once

#include <QObject>
#include <QOpenGLFunctions_3_3_Core>
#include <QVector>
#include <QVector3D>
#include <QMatrix4x4>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QOpenGLFunctions_3_3_Core>

#include <Amber3D/API/Shaders/ColorShader.h>
#include <Amber3D/API/Shaders/TextureShader.h>
#include <Amber3D/OpenGL/BatchRender.h>

#include <Amber3D/API/Loaders/LoadAmberModel.h>
#include <Amber3D/Entities/ColorEntity.h>
#include <Amber3D/Entities/TexturedEntity.h>
#include <Amber3D/Entities/Light.h>
#include <Amber3D/Entities/Camera.h>

class ModelWarehouse : public QObject, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
        QOpenGLFunctions_3_3_Core* m_gl;

        Amber3D::API::ColorShader* m_colorShader;
        Amber3D::API::TextureShader* m_textureShader;
        Amber3D::OpenGL::BatchRender* m_batchRender;
        Amber3D::API::LoadAmberModel* m_modelLoader;

        Amber3D::Models::RawModel* m_model;
        QVector<Amber3D::Entities::ColorEntity*> m_colorEntities;
        QVector<Amber3D::Entities::TexturedEntity*> m_textureEntities;
        Amber3D::Entities::Light* m_light;
        Amber3D::Entities::Camera* m_camera;

    public:
        ModelWarehouse(QOpenGLFunctions_3_3_Core* gl);
        ~ModelWarehouse();

        void InitializeModelWarehouse();

        void RenderAll(QMatrix4x4 projection);

    private:
        bool LoadFiles();
};
