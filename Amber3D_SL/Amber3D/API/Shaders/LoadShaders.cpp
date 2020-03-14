
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2019 Dec 4th
 *
 *      AmberNet - Qt C++
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
#include "LoadShaders.h"

namespace Amber3D
{
    namespace API
    {
        QOpenGLShaderProgram* LoadShaders(ShaderName name)
        {
            QOpenGLShaderProgram* l_program = new QOpenGLShaderProgram();

            l_program->create();

            l_program->addShaderFromSourceFile(
                        QOpenGLShader::Vertex,
                        "Resources/GLSL/" + shader[name] + ".vsh"
            );

            l_program->addShaderFromSourceFile(
                        QOpenGLShader::Fragment,
                        "Resources/GLSL/" + shader[name] + ".fsh"
            );

            l_program->link();
            l_program->bind();

            return l_program;
        }
    }
}
