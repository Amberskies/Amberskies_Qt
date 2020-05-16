
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
#include "Menu1.h"


namespace Amber3D
{
    namespace Gui_3D
    {
        Menu1::Menu1()
            : m_maxItems(0)
            , m_menuLocation(QVector3D(0.0f, 0.5f, -1.0f))
        {
            m_items[NUM_ITEMS] = { 0 };
        }
		void Menu1::setMaxItems(int maxItems)
		{
            m_maxItems = maxItems;

            // this clamp should not be here
            if (maxItems > NUM_ITEMS) maxItems = NUM_ITEMS;

            for (int id = 1; id <= maxItems; id++)
                m_items[id - 1] = id;
		}
    }
}
