
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
#include "ShaderProgram.h"

namespace Amber3D
{
    namespace API
    {
        class StaticShader : public ShaderProgram 
        {
            //const QString m_shaderName = "Simplified";

            public:
                StaticShader(/* args */);
                ~StaticShader();

            protected:
                void BindAttributes() override;

            private:

                
        };        
    }
}