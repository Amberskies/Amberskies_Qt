
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

namespace Amber3D
{
    namespace Maths
    {
        static float ClampRotation(float rotation)
        {
            if (rotation >= 360.0f) rotation -= 360.0f;
            if (rotation <= -360.0f) rotation += 360.0f;

            return rotation;
        }
    }
}
