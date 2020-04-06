
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
#pragma once
#include "Amber3D/Common.h"
#include <QOpenGLVertexArrayObject>

namespace Amber3D
{
    namespace Models
    {
        class RawModel
        {
            QOpenGLVertexArrayObject *m_vao;
            GLuint m_indexCount;
            bool m_hasTexture;

        public:
            RawModel(
                QOpenGLVertexArrayObject *vao,
                GLuint indexCount,
                bool hasTexture
            );

            QOpenGLVertexArrayObject* GetVao();
            GLuint GetIndexCount();
            bool GetHasTexture();
            NULL_COPY_AND_ASSIGN(RawModel)
        };
    }
}
