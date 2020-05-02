
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
#include "TextureShader.h"

namespace Amber3D
{
    namespace API
    {
        TextureShader::TextureShader()
            : ShaderProgram("PhongTexture")
        {
            GetAllUniformLocations();
        }

        TextureShader::~TextureShader()
        {
            // empty
        }

		void TextureShader::loadUniformValues(QMatrix4x4 modelMatrix,
            QMatrix4x4 viewMatrix,
            QMatrix4x4 projectionMatrix,
            Entities::Light& light,
            float damper,
            float reflectivity,
            QVector3D skyColor)
		{
            GetProgramID()->setUniformValue(
                m_modelMatLoc,
                modelMatrix
            );

            GetProgramID()->setUniformValue(
                m_viewMatLoc,
                viewMatrix
            );

            GetProgramID()->setUniformValue(
                m_projectionMatLoc,
                projectionMatrix
            );

            GetProgramID()->setUniformValue(
                m_lightPositionLoc,
                light.GetPosition()
            );

            GetProgramID()->setUniformValue(
                m_lightColorLoc,
                light.GetColor()
            );

            GetProgramID()->setUniformValue(
                m_shineDamperLoc,
                damper
            );

            GetProgramID()->setUniformValue(
                m_reflectivityLoc,
                reflectivity
            );

            GetProgramID()->setUniformValue(
                m_skyColorLoc,
                skyColor
            );
		}

        
        //////////////// Protected /////////////

        void TextureShader::BindAttributes()
        {
            BindAttrib(
                0,
                "position"
            );

            BindAttrib(
                1,
                "textureCoords"
            );

            BindAttrib(
                2,
                "normal"
            );
        }

        void TextureShader::GetAllUniformLocations()
        {
            m_modelMatLoc =
                GetProgramID()->uniformLocation(
                    "u_Model"
                );

            m_viewMatLoc =
                GetProgramID()->uniformLocation(
                    "u_View"
                );

            m_projectionMatLoc =
                GetProgramID()->uniformLocation(
                    "u_Projection"
                );

            m_lightPositionLoc =
                GetProgramID()->uniformLocation(
                    "u_LightPosition"
                );

            m_lightColorLoc =
                GetProgramID()->uniformLocation(
                    "u_LightColor"
                );

            m_shineDamperLoc =
                GetProgramID()->uniformLocation(
                    "u_ShineDamper"
                );

            m_reflectivityLoc =
                GetProgramID()->uniformLocation(
                    "u_Reflectivity"
                );

            m_skyColorLoc =
                GetProgramID()->uniformLocation(
                    "u_SkyColor"
                );
        }
    }
}
