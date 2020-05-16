
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 May 07th
 *
 *      Amber 3D - Qt C++ Version Test 0.2
 *
 * Contact email  : amberskies@virginmail.com
 * Website        : www.amberskies.org.uk
 * Twitch         : FrazorBladezSharp
 * Youtube        : Amberskies
 *
 * All code is free to use as you please
 * Please be aware of the Open Source Licence
 * given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
 *
 * ---------------------------------------------------*/
#include "ModelWarehouse.h"


// Resources/AmberModels/Default
//  Files : DefaultMap.txt          : Where things are in the world
//          DefaultModels.txt       : Models used to create map
//          PlainMesh50x50.amb      : use as test Mesh for now

namespace Amber3D
{
    namespace OpenGL
    {
        ModelWarehouse::ModelWarehouse(QString colorShader,
            QString textureShader,
            QOpenGLFunctions_3_3_Core* gl)
            : m_gl(gl)
            , m_colorShader(new API::ColorShader(colorShader))
            , m_textureShader(new API::TextureShader(textureShader))
            , m_batchRender(new OpenGL::BatchRender(m_colorShader, m_textureShader, m_gl))
            , m_modelLoader(new API::LoadAmberModel())
            , m_model(nullptr)
            , m_light(nullptr)
            , m_camera(nullptr)
            , m_mousePicker(new Gui_3D::MousePicker())
        {
            // Empty
        }

        ModelWarehouse::~ModelWarehouse()
        {
            delete m_mousePicker;
            delete m_camera;
            delete m_light;
            delete m_modelLoader;
            delete m_batchRender;
            delete m_textureShader;
            delete m_colorShader;

            for (int instance = 0; instance < m_colorEntities.size(); instance++)
                delete m_colorEntities[instance];

            for (int instance = 0; instance < m_textureEntities.size(); instance++)
                delete m_textureEntities[instance];
        }

        void ModelWarehouse::InitializeModelWarehouse()
        {
            m_light = new Entities::Light(
                QVector3D(25.0f, 250.0f, 25.0f),
                QVector3D(0.8f, 0.8f, 0.8f)
            );

            m_camera = new Entities::Camera(
                QVector3D(65.0f, 20.0f, 65.0f),
                40.0f,
                -45.0f,
                0.0f
            );

            LoadFiles();

        }

        void ModelWarehouse::RenderAll(
            int windowHeight,
            QPoint mousePosition, 
            QMatrix4x4 projection)
        {
            m_camera->MoveCamera(0.06f); // sets camera move speed

            QVector3D cursorPos = m_mousePicker->update(
                windowHeight,
                mousePosition,
                m_textureEntities[0],
                m_windowSize.x(),
                m_windowSize.y(),
                m_camera,
                projection
            );

            m_colorEntities[0]->SetPosition(cursorPos);
            m_colorEntities[0]->SetScale(0.5f);

            for (int instance = 0; instance < m_colorEntities.size(); instance++)
            {
                m_batchRender->AddColorEntity(
                    m_colorEntities[instance]->GetRawModel(),
                    m_colorEntities[instance]
                );
            }

            for (int instance = 0; instance < m_textureEntities.size(); instance++)
            {
                m_batchRender->AddTexturedEntity(
                    m_textureEntities[instance]->GetTexturedModel(),
                    m_textureEntities[instance]
                );
            }

            m_batchRender->Render(
                m_light,
                m_camera,
                projection
            );

        }

        void ModelWarehouse::SetShaders(QString colorShader, QString textureShader)
        {
            delete m_textureShader;
            delete m_colorShader;

            m_colorShader = new API::ColorShader(colorShader);
            m_textureShader = new API::TextureShader(textureShader);
            m_batchRender->SetColorShader(m_colorShader);
            m_batchRender->SetTextureShader(m_textureShader);
        }

        //////////////////////// Private /////////////////////////////

        bool ModelWarehouse::LoadFiles()
        {
            QString filePath = "Resources/AmberModels/Default/";
            QString line = "#";

            QFile file_in(
                filePath + "DefaultModels.txt"
            );

            bool file_is_open = file_in.open(
                QIODevice::ReadOnly | QIODevice::Text
            );

            if (file_is_open == false)  return false;

            QTextStream in(&file_in);

            while (line.isNull() == false)
            {
                // read each line until end of file
                line = in.readLine().trimmed();
                if (line == "") break;

                // check for comment lines
                if (line.startsWith("#")) continue;

                // load the entity
                Models::RawModel* m_model = m_modelLoader->loadToGfx(
                    line,
                    m_colorShader->GetProgramID(),
                    m_textureShader->GetProgramID()
                );
                
                if (m_model->GetHasTexture())
                {
                    Textures::ModelTexture* texture =
                        m_modelLoader->GetTexture();

                    Models::TexturedModel* texturedModel =
                        new Models::TexturedModel(
                            m_model,
                            texture
                        );

                    m_textureEntities.push_back(
                        new Entities::TexturedEntity(
                            texturedModel,
                            QVector3D(0.0f, 0.0f, 0.0f),
                            0.0f,
                            0.0f,
                            0.0f,
                            1.0f
                        )
                    );
                }
                else
                {
                    m_colorEntities.push_back(
                        new Entities::ColorEntity(
                            m_model,
                            QVector3D(0.0f, 0.0f, 0.0f),
                            0.0f,
                            0.0f,
                            0.0f,
                            1.0f
                        )
                    );
                }

            };
            file_in.close();
            return true;
        }
    }
}
