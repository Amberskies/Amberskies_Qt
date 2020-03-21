
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 20th
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
#include "Amber3D/Common.h"
#include "RawModel.h"
#include "Amber3D/Textures/ModelTexture.h"

namespace Amber3D
{
    namespace Models
    {
        class TexturedModel
        {
            RawModel *m_rawModel;
            Textures::ModelTexture *m_modelTexure;

        public:
            TexturedModel(
                RawModel *rawMode,
                Textures::ModelTexture *modelTexture
            );
            
            RawModel* GetRawModel();
            Textures::ModelTexture* GetModelTexture();
        };
    }
}
