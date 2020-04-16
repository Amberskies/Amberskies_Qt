
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



#define MODEL3D_TO_LOAD "BoxRGB"    // name of our .obj file
#define DISPLAY_WIDTH 800           // pixels
#define DISPLAY_HEIGHT 400          // pixels

#define FOV 90.0f                   // degrees
#define NEAR_PLANE 0.1f             // meters
#define FAR_PLANE 50.0f             // meters


///////////////// Window 3D //////////////////////////
#include <iostream>


#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>

namespace Dev
{
    class Window3D : public QOpenGLWidget, protected QOpenGLFunctions
    {
        //Q_OBJECT

        QMatrix4x4 m_projection;

    public:
        Window3D(QWidget *parent = nullptr)
            : QOpenGLWidget(parent)
        {

        }

    protected:
        void initializeGL() override
        {
            initializeOpenGLFunctions();
            std::cout << "Open GL Functions :" << std::endl;
            std::cout << glGetString(GL_VERSION) << std::endl;

            glClearColor(0.05f, 0.05f, 1.0f, 1.00f);
            glEnable(GL_DEPTH_TEST);

        }

        void paintGL() override
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        }

        void resizeGL(int w, int h) override
        {
            float aspectRatio = static_cast<float>(w) / h;

            m_projection.setToIdentity();
            m_projection.perspective(FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);
        }

    private:

    };

//////////////////////////////////////////////////////
}

///////////////// Main ///////////////////////////////
#include <QApplication>
#include <QString>
#include <QVector>
#include <QFile>

#include "objDataStructure.h"

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
    //////////// MTL /////////////////////////////
    QVector<Model::DiffuseTextureMap*> diffTextureMap;
    QVector<Model::MaterialName*> materialName;
    QVector<Model::DiffuseColor*> diffuseColor;
    QVector<Model::Transparency*> transparency;
    int currentColor = -1;
    do
    {
        // read each line until end of file
        line = in.readLine().trimmed();
        // compare with possible lines as give in objDataStructure.h
        QStringList data = line.split(" ");
        /////////////////////////// OBJ File /////////////////////////////

        if (line.startsWith("# ")) continue;
        if (line.startsWith("mt")) materialFileName.push_back(new Model::MaterialFileName(data.at(1)));
        if (line.startsWith("v ")) vertexData.push_back(new  Model::Vertex(data.at(1).toFloat(),
                    data.at(2).toFloat(), data.at(3).toFloat()));

        if (line.startsWith("vt"))
            textureData.push_back(new Model::TextureCoordinate(data.at(1).toFloat(),
                    data.at(2).toFloat(), 0.0f));

        if (line.startsWith("vn")) vertexNormals.push_back(new Model::VertexNormals(
                    data.at(1).toFloat(), data.at(2).toFloat(), data.at(3).toFloat()));

        if (line.startsWith("us"))
        {
            useMaterial.push_back(new Model::UseMaterial(data.at(1)));
            if (data.at(1) != "None") currentColor++;
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
                    currentColor, hasTexture, hasNormals));
        }


    } while (line.isNull() == false);

    std::cout << "\nMaterial File Name = " << materialFileName[0]->m_fileName.toStdString() << std::endl;
    std::cout << "Total Number of Verticies           = " << vertexData.size() << std::endl;
    std::cout << "Total Number of Texture Coordinates = " << textureData.size() << std::endl;
    std::cout << "Total Number of Normals             = " << vertexNormals.size() << std::endl;
    std::cout << "Total Number of Colors              = " << currentColor << std::endl;
    std::cout << "Total Number of Materials           = " << useMaterial.size() << std::endl;
    std::cout << "Toatal Number of Faces              = " << faceElement.size() << std::endl;

        /////////////////////////// MTL file ///////////////////////////

//        if (line.startsWith("map_Kd")) m_diffTextureMap.push_back(new DiffuseTextureMap(data.at(1)));
//        if (line.startsWith("ne")) m_materialName.push_back(new MaterialName(data.at(1)));
//        if (line.startsWith("Kd")) m_diffuseColor.push_back(new DiffuseColor(
//                    data.at(1).toFloat(), data.at(2).toFloat(), data.at(3).toFloat()));
//        if (line.startsWith("d ")) m_transparency.push_back(new Transparency(data.at(1).toFloat()));

        // store each line - ready to construct the model data.





    // construct model data

    // store data to the GFX card

    // remove tem data and clean memory

    // store the OpenGL handles given back to us by the GFX Card.
    // we will only need the Vertex Attribute Object and the number of indicies
    // also think about if the model has a texture or not.


    return app.exec();
}
