
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
#include <QVector>

#include "Amber3D/OpenGL/BatchRender.h"
#include "Amber3D/Entities/ColorEntity.h"
#include "Amber3D/Entities/TexturedEntity.h"


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

            OpenGL::BatchRender* m_batchRender;
            QVector<Entities::ColorEntity*> m_colorEntities;
            QVector<Entities::TexturedEntity*> m_textureEntities;

            MenuSystem();


            void SetupMenu1(
                OpenGL::BatchRender* batchRender,
                QVector<Entities::ColorEntity*>& colorEntities,
                QVector<Entities::TexturedEntity*>& textureEntities
            );

            void AddMenu1();

            int CheckMenu1(QVector3D cursorPos);
        };
    }
}
