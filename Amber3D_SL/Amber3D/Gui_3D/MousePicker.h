
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
#pragma once

#include <map>

#include <QObject>
#include <QMatrix4x4>
#include <QVector3D>
#include <QVector4D>
#include <QPoint>

#include <Amber3D/Entities/Camera.h>
#include <Amber3D/Entities/ColorEntity.h>
#include <Amber3D/Entities/TexturedEntity.h>

namespace Amber3D
{
    namespace Gui_3D
    {
        class MousePicker : public QObject
        {
            Q_OBJECT

            const float RAY_RANGE = 300.0f;
            const float RECURSION_COUNT = 150;

            QVector3D m_currentRay;
            QVector3D m_currentModelPoint;

            // models to check against
            QVector<Entities::ColorEntity*> m_colorEntities;
            QVector<Entities::TexturedEntity*> m_textureEntities;


        public:
            MousePicker();

            void update(
                    int width,
                    int height,
                Entities::Camera* camera,
                QMatrix4x4 projection
            );

            QVector3D getCurrentRay() 
            {
                return m_currentRay; 
            }

            QVector3D GetCurrentModelPoint() 
            {
                return m_currentModelPoint; 
            }

            void SetColorEntities(
                QVector<Entities::ColorEntity*> colorEntities)
            {
                m_colorEntities = colorEntities;
            }

            void SetTextureEntities(
                QVector<Entities::TexturedEntity*> textureEntities)
            {
                m_textureEntities = textureEntities;
            }

        private:
            QPoint GetNormalizedWindowCoord(
                float windowWidth,
                float windowHeight
            );

            QVector4D ConvertToViewSpace(
                QMatrix4x4 projection,
                QVector4D mousePos
            );

            QVector3D ConvertToModelSpace(
                QVector4D projectionSpace,
                Entities::Camera* camera
            );

            QVector3D CalcMouseRay(
                    int width,
                    int height,
                Entities::Camera* camera,
                QMatrix4x4 projection
            );

            // next check the models against the ray for an intersection.

        };
    }
}

