
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Apr 28th
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

#include <QString>
#include <QFile>

#include <QOpenGLShaderProgram>

#include "GfxLoader.h"
#include "Amber3D/Models/RawModel.h"
#include "Amber3D/API/Shaders/TextureShader.h"
#include "Amber3D/API/Shaders/ColorShader.h"
#include "Amber3D/Textures/ModelTexture.h"

namespace Amber3D
{
    namespace API
    {
        class LoadAmberModel
        {
            GfxLoader* m_loader;
            Textures::ModelTexture* m_texture;
            bool m_hasTextures;

        public:
            LoadAmberModel();
            ~LoadAmberModel();

            Models::RawModel* loadToGfx(
                QString model_to_load,
                QOpenGLShaderProgram* colorShader,
                QOpenGLShaderProgram* textureShader
            );

            Textures::ModelTexture* GetTexture() { return m_texture;  }
            bool GetHasTexture() { return m_hasTextures; }
        };
    }
}
