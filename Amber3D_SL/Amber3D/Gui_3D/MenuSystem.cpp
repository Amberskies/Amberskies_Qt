
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
        {
            // Empty
        }

		void MenuSystem::SetupMenu1(
            OpenGL::BatchRender* batchRender,
            QVector<Entities::ColorEntity*>& colorEntities,
            QVector<Entities::TexturedEntity*>& textureEntities
        )
		{
            m_batchRender = batchRender;
            m_colorEntities = colorEntities;
            m_textureEntities = textureEntities;

            m_menu[COLOR_MODEL].setMaxItems(
                colorEntities.size()
            );

            m_menu[TEXTURE_MODEL].setMaxItems(
                textureEntities.size()
            );
		}

        void MenuSystem::AddMenu1()
        {
            // add color models
            for (int index = 1; index < m_colorEntities.size(); index++)
            {
                QVector3D location = m_menu->GetItemLocation(index);
                m_colorEntities[index]->SetPosition(location);

                m_batchRender->AddColorEntity(
                    m_colorEntities[index]->GetRawModel(),
                    m_colorEntities[index]
                );
            }
        }

		int MenuSystem::CheckMenu1(QVector3D cursorPos)
		{
            for (int menuItem = 1; menuItem < m_menu->m_maxItems; menuItem++)
            {
                //QVector3D itemLocation = m_menu->GetItemLocation(menuItem);

                // x = 2.0f * index : z = -2.0f
                if (cursorPos.x() >= 2.0f * menuItem &&
                    cursorPos.x() < 2.0f * menuItem + 2.0f)
                {
                    if (cursorPos.z() >= -4.0f &&
                        cursorPos.z() < -0.1f)
                        return menuItem;
                }                   
            }
			return 0;
		}

    }
}
