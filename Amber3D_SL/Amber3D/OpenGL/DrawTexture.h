
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
#include <QOpenGLFunctions>
#include <QMatrix4x4>

#include "Amber3D/API/Shaders/TextureShader.h"
#include "Amber3D/Models/TexturedModel.h"
#include "Amber3D/Entities/TexturedEntity.h"
#include "Amber3D/Entities/Camera.h"
#include "Amber3D/Entities/Light.h"

namespace Amber3D
{
    namespace OpenGL
    {

        class DrawTexture
        {
            const unsigned int NUM_ATTRIBS = 3;
            API::TextureShader* m_textureShader;
            QOpenGLFunctions* m_gl;
            Entities::Light* m_light;
            QMatrix4x4 m_perspective;

        public:
            DrawTexture(API::TextureShader* textureShader,
                        QOpenGLFunctions* gl);

            void Prepare(QMatrix4x4& perspective,
                Entities::Light* light);

            void Render(std::map<Models::TexturedModel*, std::vector<Entities::TexturedEntity*>>& texturedModels,
                Entities::Camera* camera);

            void SetTextureShader(API::TextureShader* textureShader) { m_textureShader = textureShader; }

        private:
            void PrepareInstance(Entities::TexturedEntity* entity, Entities::Camera* camera);
            void PrepareTexturedModel(Models::TexturedModel* model);
            void CleanUp(Models::TexturedModel* model);


        };
    }
}

