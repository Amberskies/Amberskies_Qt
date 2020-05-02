
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
#include "Amber3D/Maths/CreateModelMatrix.h"
#include "Amber3D/Maths/CreateViewMatrix.h"

namespace Amber3D
{
    namespace OpenGL
    {        
        Renderer::Renderer(QOpenGLFunctions_3_3_Core *gl)
            : m_gl(gl)
            , m_light(new Entities::Light(QVector3D(0.0f, 0.0f, 10.0f), QVector3D(0.8f,0.8f,0.8f)))
        {
            // empty
        }
        
        void Renderer::prepare()
        {
            m_gl->glClearColor(
                0.01f,
                0.02f,
                0.05f,
                1.0f
            );
        }

        void Renderer::render(
            Entities::Camera *camera,
            Entities::TexturedEntity *texturedEntity,
            API::TextureShader *shader,
            QMatrix4x4 projectionMatrix)
        {
            Models::TexturedModel *texturedModel = 
                texturedEntity->GetTexturedModel();

            Models::RawModel *model = 
                texturedModel->GetRawModel();

            shader->GetProgramID()->bind();
            model->GetVao()->bind();

            QMatrix4x4 modelMatrix;
            modelMatrix.setToIdentity();

            modelMatrix = Maths::CreateModelMatrix(
                texturedEntity->GetPosition(),
                texturedEntity->GetRotationX(),
                texturedEntity->GetRotationY(),
                texturedEntity->GetRotationZ(),
                texturedEntity->GetScale()
            );

            QMatrix4x4 viewMatrix;
            viewMatrix.setToIdentity();

            viewMatrix = Maths::CreateViewMatrix(
                camera
            );

            // shader->loadMVPmatrix(
            //     projectionMatrix * viewMatrix * modelMatrix
            // );
            //int locMVPmatrix =
            //shader->uniformLocation(
              //  "u_mvp"
            //);
            
            //shader->setUniformValue(
              //  locMVPmatrix,
                //projectionMatrix * viewMatrix * modelMatrix
            //);
            shader->loadUniformValues(
                modelMatrix,
                viewMatrix,
                projectionMatrix,
                *m_light,
                255.0f, // power of 2 roughness of surface 1 - 255
                0.001f, // 1.0f = 100% how much is reflected
                QVector3D(0.01f, 0.02f, 0.05f)
            );

            texturedModel->GetModelTexture()->GetTexture()->bind();
            
            m_gl->glDrawElements(
                GL_TRIANGLES,
                model->GetIndexCount(),
                GL_UNSIGNED_INT,
                0
            );

            model->GetVao()->release();
            shader->GetProgramID()->release();
        }
    }
}
