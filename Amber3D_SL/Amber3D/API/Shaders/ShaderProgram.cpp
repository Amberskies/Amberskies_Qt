
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
#include <QDebug>

namespace Amber3D
{
    namespace API
    {
        ShaderProgram::ShaderProgram(
            QString shaderName)
                : m_programID(nullptr)
        {
            LoadShaders(shaderName);
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

        QOpenGLShaderProgram* ShaderProgram::GetProgramID()
        {
            return m_programID;
        }

        ////////////////// Protected //////////////////

        void ShaderProgram::BindAttrib(
            int attribNum,
            QString name)
        {
            m_programID->bindAttributeLocation(
                name,
                attribNum
            );
        }

        int ShaderProgram::GetUniformLocation(
            QString uniformName)
        {
            return m_programID->uniformLocation(
                uniformName
            );
        }

        //////////////////// Private //////////////////

        void ShaderProgram::LoadShaders(
            QString shaderName)
        {
            m_programID =
                new QOpenGLShaderProgram();

            m_programID->create();

            m_programID->addShaderFromSourceFile(
                QOpenGLShader::Vertex,
                "Resources/GLSL/" + shaderName + ".vert"
            );

            m_programID->addShaderFromSourceFile(
                QOpenGLShader::Fragment,
                "Resources/GLSL/" + shaderName + ".frag"
            );

            BindAttributes();
            
            m_programID->link();
            m_programID->bind();

            GetAllUniformLocations();
        }
    }
}
