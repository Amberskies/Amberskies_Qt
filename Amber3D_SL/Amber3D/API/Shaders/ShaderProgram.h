
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 17th
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

#include <QOpenGLShaderProgram>
#include <QString>


namespace Amber3D
{
    namespace API
    {
        class ShaderProgram
        {
            QOpenGLShaderProgram *m_programID;
            

            public:
                ShaderProgram(QString shaderName);
                virtual ~ShaderProgram();

                void Start();
                void Stop();

                QOpenGLShaderProgram* GetProgramID() { return m_programID; }

            protected:
                virtual void BindAttributes(){}
                void BindAttrib(int attribNum, QString name);

            private:
                QOpenGLShaderProgram* LoadShaders(QString shaderName);

                NULL_COPY_AND_ASSIGN(ShaderProgram)
        };        
    }
}
