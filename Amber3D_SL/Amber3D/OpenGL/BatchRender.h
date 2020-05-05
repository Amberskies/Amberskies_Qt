
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

#include "DrawColor.h"
#include "DrawTexture.h"
#include "Amber3D/API/Shaders/ColorShader.h"
#include "Amber3D/API/Shaders/TextureShader.h"

#include "Amber3D/Models/RawModel.h"
#include "Amber3D/Entities/ColorEntity.h"
#include "Amber3D/Models/TexturedModel.h"
#include "Amber3D/Entities/TexturedEntity.h"
#include "Amber3D/Entities/Camera.h"
#include "Amber3D/Entities/Light.h"



namespace Amber3D
{
    namespace OpenGL
    {

        class BatchRender
        {
            API::ColorShader* m_colorShader;
            API::TextureShader* m_textureShader;
            QOpenGLFunctions_3_3_Core* m_gl;
            DrawColor* m_drawColor;
            DrawTexture* m_drawTexture;

            std::map<Models::RawModel*, std::vector<Entities::ColorEntity*>> m_colorModels;
            std::map<Models::TexturedModel*, std::vector<Entities::TexturedEntity*>> m_texturedModels;
            // maps have been left unitialized on purpose.

        public:
            BatchRender(API::ColorShader* colorShader,
                        API::TextureShader* textureShader,
                        QOpenGLFunctions_3_3_Core* gl);

            void Render(Entities::Light* light,
                        Entities::Camera* camera,
                        QMatrix4x4& perspective);

            void AddColorEntity(Models::RawModel* model, 
                                Entities::ColorEntity* colorEntity);

            void AddTexturedEntity(Models::TexturedModel* model,
                                   Entities::TexturedEntity* texturedEntity);

            void SetColorShader(API::ColorShader* colorShader) { m_colorShader = colorShader; }
            void SetTextureShader(API::TextureShader* textureShader) { m_textureShader = textureShader; }
        };
    }
}

