
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Apr 28th
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
#include "LoadAmberModel.h"

namespace Amber3D
{
    namespace API
    {
        LoadAmberModel::LoadAmberModel() 
            : m_loader(new GfxLoader())
            , m_texture(nullptr)
            , m_hasTextures(false)
        {
            // Empty
        }

        LoadAmberModel::~LoadAmberModel()
        {
            delete m_texture;
            delete m_loader;
        }

		Models::RawModel* LoadAmberModel::loadToGfx(
            QString model_to_load,
            QOpenGLShaderProgram* colorShader,
            QOpenGLShaderProgram* textureShader)
		{
            QString filePath = "Resources/AmberModels/" + model_to_load + ".amb";
            QString line;

            QFile file_in(filePath);

            bool file_is_open = file_in.open(QIODevice::ReadOnly | QIODevice::Text);
            if (file_is_open == false)  qDebug("[Error] : unable to open 3D model file.");

            QTextStream in(&file_in);

            int numIndices = 1;
            bool hasTextures = false;
            bool hasNormals = false;
            QString texture_filename;

            /////////////////////////// AMB File /////////////////////////////
            do
            {
                // read each line until end of section
                line = in.readLine().trimmed();
                // compare with possible lines 
                QStringList data = line.split(" ");

                if (line.startsWith("hasTexture:")) hasTextures = data.at(1).toUInt();
                if (line.startsWith("textureFilename:")) texture_filename = data.at(1);
                if (line.startsWith("numIndices:")) numIndices = data.at(1).toInt();
                if (line.startsWith("hasNormals:")) hasNormals = data.at(1).toUInt();


            } while (line.startsWith("# Array Start :") == false);

            m_hasTextures = hasTextures;
            // array indices;
            uint* indices = new uint[numIndices];
            for (uint i = 0; i < numIndices; i++) indices[i] = i;

            // array vertices;
            int numVertices = numIndices * 3;
            float* vertices = new float[numVertices];
            int count = 0;
            /////////////////////////// AMB Verticies /////////////////////////////
            do
            {
                // read each line until end of section
                line = in.readLine().trimmed();
                QStringList data = line.split(" ");

                if (line.startsWith("#")) continue;
                vertices[count++] = data.at(0).toFloat();
                vertices[count++] = data.at(1).toFloat();
                vertices[count++] = data.at(2).toFloat();

            } while (count < numVertices);

            int numNormals = numIndices * 3;
            float* normals = new float[numNormals];
            count = 0;

            if (hasNormals)
            {
                /////////////////////////// AMB Normals /////////////////////////////
                do
                {
                    // read each line until end of section
                    line = in.readLine().trimmed();
                    QStringList data = line.split(" ");

                    

                    if (line.startsWith("#")) continue;
                    normals[count++] = data.at(0).toFloat();
                    normals[count++] = data.at(1).toFloat();
                    normals[count++] = data.at(2).toFloat();

                } while (count < numNormals);
            }
            else
            {
                normals[0] = 0.0f;
                numNormals = 1;
            }

            int numTexCoords = numIndices * 2;
            float* textureCoords = new float[numTexCoords];

            int numColors = numIndices * 3;
            float* colors = new float[numColors];
            count = 0;

            if (hasTextures)
            {
                colors[0] = 0.0f;
                numColors = 1;
                /////////////////////////// AMB TexCoords /////////////////////////////
                do
                {
                    // read each line until end of section
                    line = in.readLine().trimmed();
                    QStringList data = line.split(" ");

                    if (line.startsWith("#")) continue;
                    textureCoords[count++] = data.at(0).toFloat();
                    textureCoords[count++] = data.at(1).toFloat();
                } while (count < numTexCoords);

            }
            else
            {
                textureCoords[0] = 0.0f;
                numTexCoords = 1;
                /////////////////////////// AMB Colors /////////////////////////////
                do
                {
                    // read each line until end of section
                    line = in.readLine().trimmed();
                    QStringList data = line.split(" ");

                    if (line.startsWith("#")) continue;
                    colors[count++] = data.at(0).toFloat();
                    colors[count++] = data.at(1).toFloat();
                    colors[count++] = data.at(2).toFloat();

                } while (count < numColors);
            }
      
            Models::RawModel* rawModel = nullptr;

            m_loader->SetShader(
                colorShader,
                textureShader
            );

            rawModel =
                m_loader->LoadToVAO(
                    indices, numIndices,
                    vertices, numVertices,
                    normals, numNormals,
                    colors, numColors,
                    textureCoords, numTexCoords
                );

            m_texture = new Amber3D::Textures::ModelTexture(
                m_loader->loadTexture(
                    texture_filename
                )
            );

			return rawModel;
		}
    }
}
