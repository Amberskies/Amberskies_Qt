
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
#pragma once

#include <QVector3D>

namespace Amber3D
{
    namespace Entities
    {
        class Light
        {
            QVector3D m_position;
            QVector3D m_color;

        public:
            explicit Light(QVector3D position,
                QVector3D color
            );

            void SetPosition(QVector3D position) { m_position = position; }
            void SetColor(QVector3D color) { m_color = color; }

            QVector3D GetPosition() { return m_position; }
            QVector3D GetColor() { return m_color; }
        };
    }
}
