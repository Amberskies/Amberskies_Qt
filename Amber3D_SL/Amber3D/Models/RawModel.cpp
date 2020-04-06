
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 16th
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
#include "RawModel.h"

namespace Amber3D
{
    namespace Models
    {
        RawModel::RawModel(
            QOpenGLVertexArrayObject *vao,
            GLuint indexCount,
            bool hasTexture)
            : m_vao(vao)
            , m_indexCount(indexCount)
            , m_hasTexture(hasTexture)
        {
            m_TextureFileName = {NULL}; // i dont think this is a good initialization.
        }

        QOpenGLVertexArrayObject* RawModel::GetVao()
        {
            return m_vao;
        }

        GLuint RawModel::GetIndexCount()
        {
            return m_indexCount;
        }

        bool RawModel::GetHasTexture()
        {
            return m_hasTexture;
        }

        QString RawModel::GetTextureFileName(int textureNumber)
        {
            return m_TextureFileName.at(textureNumber); 
        }

        void RawModel::SetTextureFileName(QString fileName)
        {
            m_TextureFileName.push_back(fileName);
        }
    }
}
