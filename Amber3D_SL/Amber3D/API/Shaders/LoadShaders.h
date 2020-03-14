
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2019 Dec 4th
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

#include <QOpenGLShaderProgram>
#include <QString>

namespace Amber3D
{
    namespace API
    {
        enum ShaderName
        {
            Simplified = 0,
            BasicColor
        };

        static QString shader[] =
        {
            "Simplified", // shader 0
            "BasicColor"
        };

        QOpenGLShaderProgram* LoadShaders(ShaderName name);

    }
}
