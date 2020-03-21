
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
#include <QOpenGLFunctions_3_3_Core>
#include "Amber3D/API/Shaders/TextureShader.h"
#include "Amber3D/Models/TexturedModel.h"

namespace Amber3D
{
    namespace OpenGL
    {
        class Renderer
        {
            QOpenGLFunctions_3_3_Core *m_gl;

        public:
            Renderer(
                QOpenGLFunctions_3_3_Core *gl
            );

            void prepare();
            
            void render(Models::TexturedModel *texturedModel,
                        API::TextureShader *shader
            );
        };
    }
}
