
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 May 05th
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
#include "DrawTexture.h"
#include "Amber3D/Maths/CreateModelMatrix.h"


namespace Amber3D
{
    namespace OpenGL
    {
        DrawTexture::DrawTexture(API::TextureShader* textureShader, QOpenGLFunctions* gl)
            : m_textureShader(textureShader)
            , m_gl(gl)
            , m_light(nullptr)
        {
            m_perspective.setToIdentity();
        }

        void DrawTexture::Prepare(QMatrix4x4& perspective, Entities::Light* light)
        {
            // Perspective Matrix
            m_perspective = perspective;
            m_light = light;

        }

        void DrawTexture::Render(std::map<Models::TexturedModel*, std::vector<Entities::TexturedEntity*>>& texturedModels,
                                 Entities::Camera3D* camera)
        {
            std::map<Models::TexturedModel*, std::vector<Entities::TexturedEntity*>>::iterator it;
            
            for (it = texturedModels.begin(); it != texturedModels.end(); ++it)
            {
                Models::TexturedModel* model = it->first;
                std::vector<Entities::TexturedEntity*> batch = it->second;

                PrepareTexturedModel(model);

                for (Entities::TexturedEntity* theEntity : batch)
                {
                    PrepareInstance(theEntity, camera);
                    m_gl->glDrawElements(
                        GL_TRIANGLES,
                        model->GetRawModel()->GetIndexCount(),
                        GL_UNSIGNED_INT,
                        nullptr
                    );
                }

                CleanUp(model);
            }
        }

        /////////////////////// Private ////////////////////////////////
        
        void DrawTexture::PrepareInstance(Entities::TexturedEntity* entity, Entities::Camera3D* camera)
        {
            // Model Matrix
            QMatrix4x4 modelMatrix;
            modelMatrix.setToIdentity();

            modelMatrix = Maths::CreateModelMatrix(
                entity->GetPosition(),
                entity->GetRotationX(),
                entity->GetRotationY(),
                entity->GetRotationZ(),
                entity->GetScale()
            );

            // View Matrix
            QMatrix4x4 viewMatrix;
            viewMatrix.setToIdentity();

            viewMatrix = camera->ToMatrix();

            // send to GFX Card
            m_textureShader->loadUniformValues(
                modelMatrix,
                viewMatrix,
                m_perspective,
                m_light,
                16.0f, // power of 2 smoothness of surface 1 - 255
                0.50f, // 1.0f = 100% how much is reflected
                QVector3D(0.01f, 0.02f, 0.05f) // sky color
            );

        }

        void DrawTexture::PrepareTexturedModel(Models::TexturedModel* model)
        {
            m_textureShader->Start();
            model->GetRawModel()->GetVao()->bind();
            model->GetModelTexture()->GetTexture()->bind();
        }

        void DrawTexture::CleanUp(Models::TexturedModel* model)
        {
            model->GetModelTexture()->GetTexture()->release();
            model->GetRawModel()->GetVao()->release();
            m_textureShader->Stop();
        }
    }
}
