
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
#include "TexturedModel.h"

namespace Amber3D
{
    namespace Models
    {
        
        TexturedModel::TexturedModel(
            RawModel *rawModel,
            Textures::ModelTexture *modelTexture)
            : m_rawModel(rawModel)
            , m_modelTexure(modelTexture)
        {
            // empty
        }
        
        RawModel* TexturedModel::GetRawModel()
        {
            return m_rawModel;
        }

        Textures::ModelTexture* TexturedModel::GetModelTexture()
        {
            return m_modelTexure;
        }
    }
}