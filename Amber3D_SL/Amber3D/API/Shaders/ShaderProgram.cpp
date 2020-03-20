
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

#include "ShaderProgram.h"

namespace Amber3D
{
    namespace API
    {
        ShaderProgram::ShaderProgram(QString shaderName)
            : m_programID(LoadShaders(shaderName))
        {
            // empty
        }
        
        ShaderProgram::~ShaderProgram()
        {
            Stop();
            delete m_programID;
        }

        void ShaderProgram::Start()
        {
            m_programID->bind();
        }

        void ShaderProgram::Stop()
        {
            m_programID->release();
        }

        ////////////////// Protected //////////////////

        void ShaderProgram::BindAttrib(int attribNum, QString name)
        {
            m_programID->bindAttributeLocation(name, attribNum);
        }

        //////////////////// Private //////////////////

        QOpenGLShaderProgram* ShaderProgram::LoadShaders(
            QString shaderName)
        {
            QOpenGLShaderProgram* l_program =
                new QOpenGLShaderProgram();

            l_program->create();

            l_program->addShaderFromSourceFile(
                        QOpenGLShader::Vertex,
                        "Resources/GLSL/" + shaderName + ".vsh"
            );

            l_program->addShaderFromSourceFile(
                        QOpenGLShader::Fragment,
                        "Resources/GLSL/" + shaderName + ".fsh"
            );

            l_program->link();
            l_program->bind();

            return l_program;

        }
    }
}
