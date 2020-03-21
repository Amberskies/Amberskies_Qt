
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
#include "ColorShader.h"

namespace Amber3D
{
    namespace API
    {
        ColorShader::ColorShader()
            : ShaderProgram("BasicColor")
        {
            // empty
        }

        ColorShader::~ColorShader()
        {
            // empty
        }

        void ColorShader::loadMVPmatrix(
            QMatrix4x4 mvp)
        {
            GetProgramID()->setUniformValue(
                m_LocMVPmatrix,
                mvp
            );
        }
        
        //////////////// Protected /////////////

        void ColorShader::BindAttributes()
        {
            BindAttrib(
                0,
                "position"
            );

            BindAttrib(
                1,
                "color"
            );
        }

        void ColorShader::GetAllUniformLocations()
        {
            m_LocMVPmatrix =
                GetProgramID()->uniformLocation(
                    "u_mvp"
            );
        }
    }
}
