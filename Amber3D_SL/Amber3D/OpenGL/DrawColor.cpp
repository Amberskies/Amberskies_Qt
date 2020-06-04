
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
#include "DrawColor.h"
#include "Amber3D/Maths/CreateModelMatrix.h"

namespace Amber3D
{
    namespace OpenGL
    {
        DrawColor::DrawColor(API::ColorShader* colorShader,
                             QOpenGLFunctions* gl)
            : m_colorShader(colorShader)
            , m_gl(gl)
            , m_light(nullptr)
        {
            m_perspective.setToIdentity();
        }

        void DrawColor::Prepare(QMatrix4x4& perspective,
                                Entities::Light* light)
        {
            // Perspective Matrix
            m_perspective = perspective;
            m_light = light;
        }

        void DrawColor::Render(std::map<Models::RawModel*, std::vector<Entities::ColorEntity*>>& colorModels,
                               Entities::Camera3D* camera)
        {
            std::map<Models::RawModel*, std::vector<Entities::ColorEntity*>>::iterator it;
            
            for (it = colorModels.begin(); it != colorModels.end(); ++it)
            {
                Models::RawModel* model = it->first;
                std::vector<Entities::ColorEntity*> batch = it->second;

                PrepareColoredModel(model);

                for (Entities::ColorEntity* theEntity : batch)
                {
                    PrepareInstance(theEntity, camera);
                    m_gl->glDrawElements(
                        GL_TRIANGLES,
                        model->GetIndexCount(),
                        GL_UNSIGNED_INT,
                        nullptr
                    );
                }

                CleanUp(model);
                
            }
        }

        //////////////////// Private ///////////////////////////

        void DrawColor::PrepareInstance(Entities::ColorEntity* entity,
                                        Entities::Camera3D* camera)
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
            m_colorShader->loadUniformValues(
                modelMatrix,
                viewMatrix,
                m_perspective,
                m_light,
                16.0f, // power of 2 smoothness of surface 1 - 255
                0.50f, // 1.0f = 100% how much is reflected
                QVector3D(0.01f, 0.02f, 0.05f) // Sky color
            );
        }

        void DrawColor::PrepareColoredModel(Models::RawModel* model)
        {
            m_colorShader->Start();
            model->GetVao()->bind();
        }

        void DrawColor::CleanUp(Models::RawModel* model)
        {             
            model->GetVao()->release();
            m_colorShader->Stop();
        }
    }
}

