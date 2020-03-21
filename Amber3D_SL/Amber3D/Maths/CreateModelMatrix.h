
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 21st
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
#include <QMatrix4x4>
#include <QVector3D>

namespace Amber3D
{
    namespace Maths
    {
        static QMatrix4x4 CreateModelMatrix(
            QVector3D translation,
            float rotationX,                    // NB use degrees not rads
            float rotationY,
            float rotationZ,
            float scale)
        {
            QMatrix4x4 modelMatrix;
            modelMatrix.setToIdentity();

            modelMatrix.translate(
                translation
            );

            modelMatrix.rotate(
                rotationX,
                1.0f,
                0.0f,
                0.0f
            );

            modelMatrix.rotate(
                rotationY,
                0.0f,
                1.0f,
                0.0f
            );

            modelMatrix.rotate(
                rotationZ,
                0.0f,
                0.0f,
                1.0f
            );

            modelMatrix.scale(
                scale
            );

            return modelMatrix;
        }
    }
}