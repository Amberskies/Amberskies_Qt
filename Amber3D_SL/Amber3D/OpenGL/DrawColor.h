
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 May 05th
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
#include <vector>
#include <QOpenGLFunctions_3_3_Core>
#include <QMatrix4x4>

#include "Amber3D/API/Shaders/ColorShader.h"
#include "Amber3D/Models/RawModel.h"
#include "Amber3D/Entities/ColorEntity.h"
#include "Amber3D/Entities/Camera.h"
#include "Amber3D/Entities/Light.h"

namespace Amber3D
{
    namespace OpenGL
    {
        class DrawColor
        {
            const unsigned int NUM_ATTRIBS = 3;
            API::ColorShader* m_colorShader;
            QOpenGLFunctions_3_3_Core* m_gl;
            Entities::Light* m_light;
            QMatrix4x4 m_perspective;


        public:
            DrawColor(API::ColorShader *colorShader,
                      QOpenGLFunctions_3_3_Core *gl);

            void Prepare(QMatrix4x4 &perspective,
                         Entities::Light* light);

            void Render(std::map<Models::RawModel*, std::vector<Entities::ColorEntity*>> &colorModels,
                        Entities::Camera *camera);

            void SetColorShader(API::ColorShader *colorShader) { m_colorShader = colorShader; }

        private:
            void PrepareInstance(Entities::ColorEntity *entity, Entities::Camera *camera);
            void PrepareColoredModel(Models::RawModel *model);
            void CleanUp(Models::RawModel* model);
        };
    }
}
