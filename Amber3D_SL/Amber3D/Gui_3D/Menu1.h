
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 May 16th
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
    namespace Gui_3D
    {

#define NUM_ITEMS 9

        struct Menu1
        {
            int m_items[NUM_ITEMS];
            int m_maxItems;

            QVector3D m_menuLocation;
        
            Menu1();

            void setMaxItems(int maxItems);
        };
    }
}

