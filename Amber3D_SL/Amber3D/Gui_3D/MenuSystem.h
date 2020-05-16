
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

#include "Menu1.h"

#include <QVector3D>

namespace Amber3D
{
    namespace Gui_3D
    {
        struct ModelSelection
        {
            int modelID = 0;
            bool isTextured = false;
            bool modelSelected = false;

            float rotationX = 0.0f;
            float rotationY = 0.0f;
            float rotationZ = 0.0f;
        };

        enum ModelType
        {
            COLOR_MODEL = 0,
            TEXTURE_MODEL
        };

        struct MenuSystem
        {
            Menu1 m_menu[2];
            int m_maxColorModels;
            int m_maxTextureModels;

            MenuSystem();


            void Setup(int maxColorModels, int maxTextureModels);
        };
    }
}
