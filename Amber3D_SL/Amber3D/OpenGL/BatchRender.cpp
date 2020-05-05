
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
#include "BatchRender.h"

namespace Amber3D
{
    namespace OpenGL
    {
		BatchRender::BatchRender(API::ColorShader* colorShader, 
                                 API::TextureShader* textureShader,
                                 QOpenGLFunctions_3_3_Core* gl)
            : m_colorShader(colorShader)
            , m_textureShader(textureShader)
            , m_gl(gl)
            , m_drawColor(new DrawColor(m_colorShader, m_gl))
            , m_drawTexture(new DrawTexture(m_textureShader, m_gl))
		{
            m_gl->glClearColor(
                0.01f,
                0.02f,
                0.05f,
                1.0f
            );
		}

        void BatchRender::Render(Entities::Light* light,
                                 Entities::Camera* camera,
                                 QMatrix4x4& perspective)
        {
            m_drawColor->Prepare(perspective, light);
            m_drawColor->SetColorShader(m_colorShader);
            m_drawColor->Render(m_colorModels, camera);

            m_colorModels.clear();

            m_drawTexture->Prepare(perspective, light);
            m_drawTexture->SetTextureShader(m_textureShader);
            m_drawTexture->Render(m_texturedModels, camera);

            m_texturedModels.clear();
        }

        void BatchRender::AddColorEntity(Models::RawModel* model,
                                         Entities::ColorEntity* colorEntity)
        {
            std::map<Models::RawModel*, std::vector<Entities::ColorEntity*>>::iterator batch;
            Models::RawModel * key = model;
            batch = m_colorModels.find(key);

            if (batch != m_colorModels.end()) batch->second.push_back(colorEntity);
            else
            {
                std::vector< Entities::ColorEntity*> newBatch;
                newBatch.push_back(colorEntity);
                m_colorModels.insert(std::pair< Models::RawModel*, std::vector< Entities::ColorEntity*>>(key, newBatch));
            }
        }

        void BatchRender::AddTexturedEntity(Models::TexturedModel* model, 
                                            Entities::TexturedEntity* texturedEntity)
        {
            std::map<Models::TexturedModel*, std::vector<Entities::TexturedEntity*>>::iterator batch;
            Models::TexturedModel* key = model;
            batch = m_texturedModels.find(key);

            if (batch != m_texturedModels.end()) batch->second.push_back(texturedEntity);
            else
            {
                std::vector< Entities::TexturedEntity*> newBatch;
                newBatch.push_back(texturedEntity);
                m_texturedModels.insert(std::pair< Models::TexturedModel*, std::vector< Entities::TexturedEntity*>>(key, newBatch));
            }

        }

	}
}
