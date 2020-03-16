
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

        RawModel::RawModel(QOpenGLVertexArrayObject *vao, int vertexCount)
            : m_vao(vao)
            , m_vertexCount(vertexCount)
        {
            // Empty
        }

        RawModel::~RawModel()
        {
            // Empty
        }

        QOpenGLVertexArrayObject* RawModel::GetVao()
        {
            return m_vao;
        }

        int RawModel::GetVertexCount()
        {
            return m_vertexCount;
        }
    }
}
