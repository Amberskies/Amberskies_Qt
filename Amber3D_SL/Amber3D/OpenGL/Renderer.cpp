
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 16th
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

#include "Renderer.h"

namespace Amber3D
{
    namespace OpenGL
    {        
        Renderer::Renderer(QOpenGLFunctions_3_3_Core *gl)
            : m_gl(gl)
        {
            // empty
        }
        
        void Renderer::prepare()
        {
            m_gl->glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
        }

        void Renderer::render(Models::TexturedModel *texturedModel,
                              API::StaticShader *shader)
        {
            Models::RawModel *model = texturedModel->GetRawModel();
            shader->Start();
            model->GetVao()->bind();
            texturedModel->GetModelTexture()->GetTexture()->bind();
            
            m_gl->glDrawElements(
                GL_TRIANGLES,
                model->GetIndexCount(),
                GL_UNSIGNED_INT,
                0
            );

            model->GetVao()->release();
            shader->Stop();
            
        }
    }
}
