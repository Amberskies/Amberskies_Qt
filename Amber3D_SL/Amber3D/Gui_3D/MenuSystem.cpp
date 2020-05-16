
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
#include "MenuSystem.h"




namespace Amber3D
{
    namespace Gui_3D
    {
        MenuSystem::MenuSystem()
            : m_maxColorModels(0)
            , m_maxTextureModels(0)
        {

        }
		void MenuSystem::Setup(int maxColorModels, int maxTextureModels)
		{
            m_menu[COLOR_MODEL].setMaxItems(maxColorModels);
            m_menu[TEXTURE_MODEL].setMaxItems(maxTextureModels);
		}
    }
}
