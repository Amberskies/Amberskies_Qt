
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Apr 30th
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
#include "Light.h"

namespace Amber3D
{
    namespace Entities
    {
        Light::Light(QVector3D position,
            QVector3D color)
        {
            m_position = position;
            m_color = color;
        }
    }
}
