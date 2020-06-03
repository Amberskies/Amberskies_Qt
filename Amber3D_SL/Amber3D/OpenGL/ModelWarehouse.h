
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
#include <QOpenGLFunctions>
#include <QVector>
#include <QVector3D>
#include <QMatrix4x4>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QOpenGLFunctions_3_3_Core>

#include "Amber3D/API/Shaders/ColorShader.h"
#include "Amber3D/API/Shaders/TextureShader.h"
#include "Amber3D/OpenGL/BatchRender.h"
#include "Amber3D/API/Loaders/LoadAmberModel.h"
#include "Amber3D/Entities/ColorEntity.h"
#include "Amber3D/Entities/TexturedEntity.h"
#include "Amber3D/Entities/Light.h"
#include "Amber3D/Entities/Camera3D.h"
#include "Amber3D/Gui_3D/MousePicker.h"
#include "Amber3D/Gui_3D/MenuSystem.h"


namespace Amber3D
{
    namespace OpenGL
    {
        class ModelWarehouse : public QObject, protected QOpenGLFunctions
        {
            Q_OBJECT


            QOpenGLFunctions* m_gl;
            API::ColorShader* m_colorShader;
            API::TextureShader* m_textureShader;
            BatchRender* m_batchRender;
            API::LoadAmberModel* m_modelLoader;

            Models::RawModel* m_model;
            QVector<Entities::ColorEntity*> m_colorEntities;
            QVector<Entities::TexturedEntity*> m_textureEntities;
            Entities::Light* m_light;
            Entities::Camera3D* m_camera;
            Amber3D::Gui_3D::MousePicker* m_mousePicker;
            Gui_3D::MenuSystem* m_menuSystem;
            QPoint m_windowSize;
            int m_itemClicked;

        public:
            explicit ModelWarehouse(
                QString colorShader,
                QString textureShader,
                QOpenGLFunctions* gl
            );

            ~ModelWarehouse();

            void InitializeModelWarehouse();

            void RenderAll(
                Entities::Camera3D* camera,
                //int windowHeight,
                //QPoint mousePosition,
                QMatrix4x4 projection);

            void SetShaders(
                QString colorShader,
                QString textureShader
            );

            void setWindow(QPoint windowSize)
            {
                m_windowSize = windowSize;
            }

        private:
            bool LoadFiles();
            QVector3D PositionTo1mSquare(QVector3D position);
            
            void CheckMenu(
                int windowHeight,
                QPoint mousePosition,
                QMatrix4x4 projection
            );
        };
    }
}
