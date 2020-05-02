
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Apr 16th
 *
 *      Amber3D 3D Model Converter - Qt C++
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


#include <QString>
#define MODEL3D_TO_LOAD "Body"    // name of our .obj file;

#include <iostream>

///////////////// Main ///////////////////////////////
#include <QApplication>
#include <QString>
#include <QVector>
#include <QFile>
#include <QVector3D>

#include <Amber3D/Models/RawModel.h>        // gives the base to create an entity
#include <Amber3D/Entities/ColorEntity.h>   // stores position etc.
#include <Amber3D/Textures/ModelTexture.h>  // stores textures for openGL
#include <Amber3D/Models/TexturedModel.h>   // handles textured models
#include <Amber3D/Entities/TexturedEntity.h>// stores positions etc

#include <Amber3D/API/Loaders/GfxLoader.h>
#include <Amber3D/API/Shaders/ColorShader.h>
#include <Amber3D/API/Shaders/TextureShader.h>

#include "objDataStructure.h"
#include "Window3D.h"
#include "Model3D_Save.h"

int main(int argc, char *argv[])
{    
    QApplication app(argc, argv);

    Dev::Window3D window;
    window.show();

    // open the .obj file
    QString fileName = MODEL3D_TO_LOAD;
    QString filePath = "Resources/OBJ/" + fileName + ".obj";
    QString line;

    QFile file_in(filePath);

    bool file_is_open = file_in.open(QIODevice::ReadOnly | QIODevice::Text);
    if (file_is_open == false)  return -1;

    QTextStream in(&file_in);

    ///////////// OBJ /////////////////////////////
    QVector<Model::MaterialFileName*> materialFileName;
    QVector<Model::Vertex*> vertexData;
    QVector<Model::TextureCoordinate*> textureData;
    QVector<Model::VertexNormals*> vertexNormals;
    QVector<Model::UseMaterial*> useMaterial;
    QVector<Model::FaceElement*> faceElement;

    int currentColor = -1;
    do
    {
        // read each line until end of file
        line = in.readLine().trimmed();
        // compare with possible lines as give in objDataStructure.h
        QStringList data = line.split(" ");

        /////////////////////////// OBJ File /////////////////////////////

        if (line.startsWith("# ")) continue;

        if (line.startsWith("mt")) materialFileName.push_back(
            new Model::MaterialFileName(data.at(1))
        );

        if (line.startsWith("v ")) vertexData.push_back(
            new  Model::Vertex(
                data.at(1).toFloat(),
                data.at(2).toFloat(), 
                data.at(3).toFloat()
            )
        );

        if (line.startsWith("vt")) textureData.push_back(
            new Model::TextureCoordinate(
                data.at(1).toFloat(),
                data.at(2).toFloat(), 
                0.0f
            )
        );

        if (line.startsWith("vn")) vertexNormals.push_back(
            new Model::VertexNormals(
                data.at(1).toFloat(), 
                data.at(2).toFloat(), 
                data.at(3).toFloat()
            )
        );

        if (line.startsWith("us"))
        {
            useMaterial.push_back(
                new Model::UseMaterial(
                    data.at(1)
                )
            );

            if (data.at(1) != "Material" &&
                data.at(1) != "None") currentColor++;
        }

        if (line.startsWith("f "))
        {
            QString dataSplit;
            QStringList slashSplit;
            int vertexIndex[4] = { 0 };
            int textureIndex[4] = { 0 };
            int normalIndex[4] = { 0 };
            bool hasTexture = false;
            bool hasNormals = false;

            if (currentColor == -1) hasTexture = true;
            if (vertexNormals.size() > 0) hasNormals = true;

            for (int count =1; count < data.size(); count++)
            {
                dataSplit = data.at(count);
                slashSplit = dataSplit.split("/");

                vertexIndex[count] = (slashSplit[0].toInt()) - 1;
                textureIndex[count] = (slashSplit[1].toInt()) - 1;
                normalIndex[count] = (slashSplit[2].toInt()) - 1;
            }

            faceElement.push_back(new Model::FaceElement(
                    vertexIndex[1], textureIndex[1], normalIndex[1],
                    vertexIndex[2], textureIndex[2], normalIndex[2],
                    vertexIndex[3], textureIndex[3], normalIndex[3],
                    currentColor, hasTexture, hasNormals
                )
            );
        }
    } while (line.isNull() == false);

    file_in.close();

    // Give a read out to console to show how much data has been read.
    std::cout << "\nMaterial File Name                = " << materialFileName[0]->m_fileName.toStdString() << std::endl;
    std::cout << "Total Number of Verticies           = " << vertexData.size() << std::endl;
    std::cout << "Total Number of Texture Coordinates = " << textureData.size() << std::endl;
    std::cout << "Total Number of Normals             = " << vertexNormals.size() << std::endl;
    std::cout << "Total Number of Colors              = " << currentColor << std::endl;
    std::cout << "Total Number of Materials           = " << useMaterial.size() << std::endl;
    std::cout << "Toatal Number of Faces              = " << faceElement.size() << std::endl;

    // we now have to load the corresponding MTL file (Material Library).

    /////////////////////////// MTL file ///////////////////////////

    filePath = "Resources/OBJ/" + materialFileName[0]->m_fileName;
    std::cout << "\nMaterial File Path = " << filePath.toStdString() << std::endl;

    QFile mtl_file_in(filePath);

    file_is_open = mtl_file_in.open(QIODevice::ReadOnly | QIODevice::Text);
    if (file_is_open == false)  return -1;

    QTextStream mtl_in(&mtl_file_in);

    //////////// MTL Vectors/////////////////////////////
    QVector<Model::DiffuseTextureMap*> diffTextureMap;
    QVector<Model::MaterialName*> materialName;
    QVector<Model::DiffuseColor*> diffuseColor;
    QVector<Model::Transparency*> transparency;


    do
    {
        // read each line until end of file
        line = mtl_in.readLine().trimmed();

        // compare with possible lines as give in objDataStructure.h
        QStringList data = line.split(" ");

    ///////////////////// MTL /////////////////////////////
    // store each line - ready to construct the model data.

    if (line.startsWith("map_Kd")) diffTextureMap.push_back(
        new Model::DiffuseTextureMap(
            data.at(1)
        )
    );
    
    if (line.startsWith("ne")) materialName.push_back(
        new Model::MaterialName(
            data.at(1)
        )
    );

    if (line.startsWith("Kd")) diffuseColor.push_back(
        new Model::DiffuseColor(
            data.at(1).toFloat(),
            data.at(2).toFloat(),
            data.at(3).toFloat()
        )
    );

    if (line.startsWith("d ")) transparency.push_back(
        new Model::Transparency(
            data.at(1).toFloat()
        )
    );


    } while (line.isNull() == false);
    
    mtl_file_in.close();

    // Give a console readout if how much data has been read in
    std::cout << " Num of Texture Maps   = " << diffTextureMap.size() << std::endl;
    std::cout << " Num of Material Names = " << materialName.size() << std::endl;
    std::cout << " Num of Colors         = " << diffuseColor.size() << std::endl;
    std::cout << " Num of Color Alpha's  = " << transparency.size() << std::endl;


    // construct model data
        // first convert all data to openGL
        // NB Material Names from the mtl file are read in reverse order
        // looks like we may need a search to assign the correct material
    QVector<Model::DiffuseColor*> reversedColor;

    for (int index = currentColor; index >= 0; index-- )
    {
		reversedColor.push_back(
			new Model::DiffuseColor(
				diffuseColor[index]->m_red,
				diffuseColor[index]->m_green,
				diffuseColor[index]->m_blue
			)
		);
    }

    // so what does OpenGL require
        // it requires arrays NOT vectors
        // we have an Amber3D function that will load our ARRAYS to the gfx card.
    QVector<uint> indices;
    QVector<float> positions;
    QVector<float> normals;
    QVector<float> texCoords;
    QVector<float> colors;
    bool hasNormals = false;

    unsigned int verticesPerFace = 3;

    for (int count = 0; count < faceElement.size(); count++) // for eg our box = 12
    {
//      Information on how we stored all the index numbers from the .obj file
//        faceElement.push_back(new Model::FaceElement(
//                vertexIndex[1st], textureIndex[1st], normalIndex[1st],
//                vertexIndex[2nd], textureIndex[2nd], normalIndex[2nd],
//                vertexIndex[3rd], textureIndex[3rd], normalIndex[3rd],
//                currentColor, hasTexture, hasNormals));

        for (unsigned int iVertex = 0; iVertex < verticesPerFace; iVertex++)
        {
            indices.push_back(static_cast<unsigned int>(count) * verticesPerFace + iVertex);

            positions.push_back( vertexData[faceElement[count]->m_vertexIndex[iVertex]]->m_x);
            positions.push_back( vertexData[faceElement[count]->m_vertexIndex[iVertex]]->m_y);
            positions.push_back( vertexData[faceElement[count]->m_vertexIndex[iVertex]]->m_z);

            if (faceElement[count]->m_hasNormals)
            {
                hasNormals = true;
                normals.push_back(vertexNormals[faceElement[count]->m_normalIndex[iVertex]]->m_x);
                normals.push_back(vertexNormals[faceElement[count]->m_normalIndex[iVertex]]->m_y);
                normals.push_back(vertexNormals[faceElement[count]->m_normalIndex[iVertex]]->m_z);
            }

            if (faceElement[count]->m_hasTextures)
            {
                texCoords.push_back(textureData[faceElement[count]->m_textureIndex[iVertex]]->m_u);
                texCoords.push_back(textureData[faceElement[count]->m_textureIndex[iVertex]]->m_v);
            }
            else
            {
                colors.push_back(reversedColor[faceElement[count]->m_currentColor]->m_red);
                colors.push_back(reversedColor[faceElement[count]->m_currentColor]->m_green);
                colors.push_back(reversedColor[faceElement[count]->m_currentColor]->m_blue);
            }
        }
    }

    // think about cleaning the original vectors up and releasing the memory
    // delete OBJ vectors
    for (int index = 0; index < materialFileName.size(); index++) delete materialFileName[index];
    for (int index = 0; index < vertexData.size(); index++) delete vertexData[index];
    for (int index = 0; index < textureData.size(); index++) delete textureData[index];
    for (int index = 0; index < vertexNormals.size(); index++) delete vertexNormals[index];
    for (int index = 0; index < useMaterial.size(); index++) delete useMaterial[index];
    for (int index = 0; index < faceElement.size(); index++) delete faceElement[index];
    // delete MTL vectors :
    // diffuse texture Map still required so we can load up the texture.
    // for (int index = 0; index < diffTextureMap.size(); index++) delete diffTextureMap[index];
    for (int index = 0; index < materialName.size(); index++) delete materialName[index];
    for (int index = 0; index < diffuseColor.size(); index++) delete diffuseColor[index];
    for (int index = 0; index < transparency.size(); index++) delete transparency[index];

    // we create an object from Amber3D::API::GfxLoader()
    Amber3D::API::GfxLoader *loader = new Amber3D::API::GfxLoader();

    // Create Shaders.
    Amber3D::API::ColorShader *colorShader = new Amber3D::API::ColorShader();
    Amber3D::API::TextureShader *textureShader = new Amber3D::API::TextureShader();

    // we set the 2 shaders color and texture
    loader->SetShader(
        colorShader->GetProgramID(),
        textureShader->GetProgramID()
    );

    // we send our arrays to the GfxLoader::LoadToVAO.
    int numIndices = indices.size();
    int numPositions =  positions.size();
    int numNormals = normals.size();

    // remember we can not have an Array with zero .size()
    // as a hack we add an item of data to the unused array.
    if (colors.size() <= 0) colors.push_back(0.0f);
    int numColors =  colors.size();
    if (texCoords.size() <= 0) texCoords.push_back(0.0f);
    int numTexCoords =  texCoords.size();

    std::cout << "\nNum Indices   = " << numIndices << std::endl;   // these are converted inside
    std::cout << "Num Positions = " << numPositions << std::endl;   // GfxLoader to the correct
    std::cout << "Num Colors    = " << numColors << std::endl;      // buffer sizes for OpenGL.
    std::cout << "Num texCoords = " << numTexCoords << std::endl;
    std::cout << "Num Normals   = " << numNormals << std::endl;

    // store the OpenGL handles given back to us by the GFX Card,
    // given as rawModel.
    Amber3D::Models::RawModel *rawModel = loader->LoadToVAO(
                &indices[0], numIndices,
                &positions[0], numPositions, // normals will be added soon
                &normals[0], numNormals,
                &colors[0], numColors,
                &texCoords[0], numTexCoords
    );

    // Write to console what the raw Model contains.
    std::cout << "\n VAO      = " << rawModel->GetVao()->objectId() << std::endl;
    std::cout << " Indices  = " << rawModel->GetIndexCount() << std::endl;
    std::cout << " Textures = " << rawModel->GetHasTexture() << std::endl;  // 0 if false
    std::cout << " true     = " << true << std::endl;                       // 1 if true

    // remove temp data and clean memory
    // now we have the raw model do we still need the models Array data ?

    // we will only need the Vertex Attribute Object and the number of indicies
    // it also holds a bool hasTextures.

    // also think about if the model has a texture or not.
    // add texture if needed.

    if (rawModel->GetHasTexture())
    {
        // load texture and store for use by any model
        // texture file name is held in diffTextureMap
        Amber3D::Textures::ModelTexture* texture =
            new Amber3D::Textures::ModelTexture(
                loader->loadTexture(
                    diffTextureMap[0]->m_diffuseTextureMap
                )
        );

        // draw textured object using Amber3D::Models::TexturedModel
        Amber3D::Models::TexturedModel* texturedModel =
            new Amber3D::Models::TexturedModel(
                rawModel,
                texture
            );

        Amber3D::Entities::TexturedEntity* texturedEntity =
            new Amber3D::Entities::TexturedEntity(
            texturedModel,
            QVector3D(0.0f, 0.0f, -5.0f),
            0.0f,
            0.0f,
            0.0f,
            1.0f
        );

        window.PrepareTexturedModel(
            texturedEntity,
            textureShader->GetProgramID()
        );
    }
    else
    {
        // draw the rawModel as a colored object.
        std::cout << "Model is colour no texture detected." << std::endl;

        // prepare model for rendering.
        // raw model - create the entity
        Amber3D::Entities::ColorEntity* colorEntity =
            new Amber3D::Entities::ColorEntity(
                rawModel,
                QVector3D(0.0f, 0.0f, -5.0f),
                0.0f,
                0.0f,
                0.0f,
                1.0f
            );

        window.PrepareColorModel(
            colorEntity,
            colorShader->GetProgramID()
        );

        // this is a hack as there is no texture file
        diffTextureMap.push_back(
            new Model::DiffuseTextureMap(
                "0"
            )
        );
    }

    // We can save this data back to disk or ssd in this new format
    Dev::SaveModel3D* saveModel = new Dev::SaveModel3D();
    saveModel->SaveConvertedData(
        fileName,
        rawModel->GetHasTexture(),
        diffTextureMap[0]->m_diffuseTextureMap,
        rawModel->GetIndexCount(),
        hasNormals,
        &positions[0], numPositions,
        &normals[0], numNormals,
        &colors[0], numColors,
        &texCoords[0], numTexCoords
    );

    // we could try cleaning up the arrays to lower memory used.

    // test "BoxRGB" uses 48.4 MB with no vector clean ups. too small a diff after clean up
    // gives a max of 60 MB on startup.
    // test "Head" uses 48.7 MB with no vector clean ups.
    // gives a max of 61 MB on startup.
    // test "Body" uses 50.0 MB with no vector clean ups. 49.9 MB with clean up.
    // gives a max of 62 MB on startup.

    // start our window event QTimer running.
    window.StartDisplay();
    
    // the Qt QAppliction will run the program loop and deal with events
    // because of this we use a QTimer to update the main Window 3D.
    return app.exec();

    // Note : we do not delete any pointes here.
}   // this is when the main function restores all memory used back to OS
    // so all the pointers will be destroyed by the system.