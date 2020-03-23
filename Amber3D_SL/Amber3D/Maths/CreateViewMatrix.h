
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 23rd
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
#include "Amber3D/Entities/Camera.h"

namespace Amber3D
{
    namespace Maths
    {
        static QMatrix4x4 CreateViewMatrix(
            Entities::Camera *camera)
        {
            QMatrix4x4 viewMatrix;
            viewMatrix.setToIdentity();

            viewMatrix.rotate(
                camera->GetPitch(),
                1.0f,
                0.0f,
                0.0f
            );

            viewMatrix.rotate(
                camera->GetYaw(),
                0.0f,
                1.0f,
                0.0f
            );

            viewMatrix.rotate(
                camera->GetRoll(),
                0.0f,
                0.0f,
                1.0f
            );

            viewMatrix.translate(
                
                camera->GetPosition() * -1.0f
            );

            return viewMatrix;
        }
    }
}
