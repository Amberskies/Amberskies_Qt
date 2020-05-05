
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 18th
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

#include "ShaderProgram.h"
#include "Amber3D/Entities/Light.h"

namespace Amber3D
{
    namespace API
    {
        class TextureShader : public ShaderProgram 
        {
            int m_modelMatLoc = -1;
            int m_viewMatLoc = -1;
            int m_projectionMatLoc = -1;

            int m_lightPositionLoc = -1;
            int m_lightColorLoc = -1;
            int m_shineDamperLoc = -1;
            int m_reflectivityLoc = -1;
            int m_skyColorLoc = -1;

        public:
            TextureShader();
            virtual ~TextureShader();

            void loadUniformValues(
                QMatrix4x4 modelMatrix,
                QMatrix4x4 viewMatrix,
                QMatrix4x4 projectionMatrix,
                Entities::Light* light,
                float damper,
                float reflectivity,
                QVector3D skyColor
            );

        protected:
            void BindAttributes() override;
            void GetAllUniformLocations();
        };        
    }
}
