
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Apr 2nd
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

#include <Amber3D/API/Loaders/GfxLoader.h>


#include <QDebug>
//////////// files we are working on //////////////////

//////////// File : StoreOBJ //*************************
#include <QString>
#include <QVector>
#include <iostream>
#include <QOpenGLVertexArrayObject>

#include "objDataStructure.h"
//#include "API/createModel.h"



namespace Model
{
    class StoreOBJ
    {

        ///////////// OBJ /////////////////////////////
        QVector<MaterialFileName*> m_materialFileName;
        QVector<Vertex*> m_vertexData;
        QVector<TextureCoordinate*> m_textureData;
        QVector<VertexNormals*> m_vertexNormals;
        QVector<UseMaterial*> m_useMaterial;
        QVector<FaceElement*> m_faceElement;
        //////////// MTL /////////////////////////////
        QVector<DiffuseTextureMap*> m_diffTextureMap;
        QVector<MaterialName*> m_materialName;
        QVector<DiffuseColor*> m_diffuseColor;
        QVector<Transparency*> m_transparency;

        int m_currentColor;

    public:
        StoreOBJ();
        ~StoreOBJ();

        void storeData(const QString &line);
        Amber3D::Models::RawModel *sendDataToAPI(Amber3D::API::GfxLoader *createModel);
        void cleanStorage();

    private:
        void storeFace(QStringList data);
    };
}
namespace Model
{
    StoreOBJ::StoreOBJ() :
        m_currentColor(-1)
    {
        qDebug("StoreOBJ Created");
    }

    StoreOBJ::~StoreOBJ()
    {
        qDebug("StoreOBJ : destroyed.");
    }

    void StoreOBJ::storeData(const QString &line)
    {
        QStringList data = line.split(" ");
        int slashes = line.count("/");
        if (slashes == 8)
        {
            std::cerr << "[Error] StoreData() : faces are Quads please use Triangles." << std::endl;
            exit(99);
        }

        /////////////////////////// OBJ File /////////////////////////////

        if (line.startsWith("# ")) return;
        if (line.startsWith("mt")) m_materialFileName.push_back(new MaterialFileName(data.at(1)));
        if (line.startsWith("v ")) m_vertexData.push_back(new  Vertex(data.at(1).toFloat(),
                    data.at(2).toFloat(), data.at(3).toFloat()));

        if (line.startsWith("vt")) m_textureData.push_back(new TextureCoordinate(data.at(1).toFloat(),
                    data.at(2).toFloat(), 0.0f));

        if (line.startsWith("vn")) m_vertexNormals.push_back(new VertexNormals(
                    data.at(1).toFloat(), data.at(2).toFloat(), data.at(3).toFloat()));

        if (line.startsWith("us"))
        {
            m_useMaterial.push_back(new UseMaterial(data.at(1)));
            m_currentColor++;
        }
        if (line.startsWith("f ")) storeFace(data);

        /////////////////////////// MTL file ///////////////////////////

        if (line.startsWith("map_Kd")) m_diffTextureMap.push_back(new DiffuseTextureMap(data.at(1)));
        if (line.startsWith("ne")) m_materialName.push_back(new MaterialName(data.at(1)));
        if (line.startsWith("Kd")) m_diffuseColor.push_back(new DiffuseColor(
                    data.at(1).toFloat(), data.at(2).toFloat(), data.at(3).toFloat()));
        if (line.startsWith("d ")) m_transparency.push_back(new Transparency(data.at(1).toFloat()));
    }

    Amber3D::Models::RawModel *StoreOBJ::sendDataToAPI(Amber3D::API::GfxLoader *createModel)
    {
        QVector<unsigned int> indexArray;
        QVector<float> positionsArray;
        QVector<float> colorArray;
        QVector<float> texArray;
        QVector<QString> texture_openGL;

        unsigned int verticesPerFace = 3;

        for (int count = 0; count < m_faceElement.size(); count++)
        {
            for (unsigned int iVertex = 0; iVertex < verticesPerFace; iVertex++)
            {
                indexArray.push_back(static_cast<unsigned int>(count) * verticesPerFace + iVertex);

                positionsArray.push_back(m_vertexData[m_faceElement[count]->m_vertexIndex[iVertex]]->m_x);
                positionsArray.push_back(m_vertexData[m_faceElement[count]->m_vertexIndex[iVertex]]->m_y);
                positionsArray.push_back(m_vertexData[m_faceElement[count]->m_vertexIndex[iVertex]]->m_z);

                colorArray.push_back(m_diffuseColor[m_faceElement[count]->m_currentColor]->m_red);
                colorArray.push_back(m_diffuseColor[m_faceElement[count]->m_currentColor]->m_green);
                colorArray.push_back(m_diffuseColor[m_faceElement[count]->m_currentColor]->m_blue);
                colorArray.push_back(m_transparency[m_faceElement[count]->m_currentColor]->m_transparency);

                if (m_faceElement[count]->m_hasTextures)
                {
                    texArray.push_back(m_textureData[m_faceElement[count]->m_textureIndex[iVertex]]->m_u);
                    texArray.push_back(m_textureData[m_faceElement[count]->m_textureIndex[iVertex]]->m_v);
                }

            }
        }

        texArray.push_back(1.0f);

        uint is = indexArray.size();
        int ps = positionsArray.size();
        int cs = colorArray.size();
        int ts = texArray.size();

        Amber3D::Models::RawModel *temp =

        createModel->LoadToVAO(             // we may be able to return
            &indexArray[0], is,             // this function call
            &positionsArray[0], ps,         // Directly and
            &colorArray[0], cs,             // clean storage first.
            &texArray[0], ts


        );

        for (int index = 0; index < m_diffTextureMap.size(); index++)
            temp->SetTextureFileName(m_diffTextureMap.at(index)->m_diffuseTextureMap);

        cleanStorage();
        return temp;
    }

    void StoreOBJ::cleanStorage()
    {
        for (int index = 0; index < m_materialFileName.size(); index++) delete m_materialFileName[index];
        for (int index = 0; index < m_vertexData.size(); index++) delete m_vertexData[index];
        for (int index = 0; index < m_textureData.size(); index++) delete m_textureData[index];
        for (int index = 0; index < m_vertexNormals.size(); index++) delete m_vertexNormals[index];
        for (int index = 0; index < m_useMaterial.size(); index++) delete m_useMaterial[index];
        for (int index = 0; index < m_faceElement.size(); index++) delete m_faceElement[index];
        for (int index = 0; index < m_diffTextureMap.size(); index++) delete m_diffTextureMap[index];
        for (int index = 0; index < m_materialName.size(); index++) delete m_materialName[index];
        for (int index = 0; index < m_diffuseColor.size(); index++) delete m_diffuseColor[index];
        for (int index = 0; index < m_transparency.size(); index++) delete m_transparency[index];

        m_currentColor = -1;
    }

    /////////////////////////// Private ///////////////////////////////

    void StoreOBJ::storeFace(QStringList data)
    {
        if (data.size() >= 5)
        {
            std::cerr << "[Error] : OBJ format is Quads, please re-format to Triangles." << std::endl;
            exit(99);
        }

        QString dataSplit;
        QStringList slashSplit;
        int vertexIndex[4] = { 0 };
        int textureIndex[4] = { 0 };
        int normalIndex[4] = { 0 };
        bool hasTexture = false;
        bool hasNormals = false;

        if (m_currentColor == -1) hasTexture = true;
        if (m_vertexNormals.size() > 0) hasNormals = true;

        for (int count =1; count < data.size(); count++)
        {
            dataSplit = data.at(count);
            slashSplit = dataSplit.split("/");

            vertexIndex[count] = (slashSplit[0].toInt()) - 1;
            textureIndex[count] = (slashSplit[1].toInt()) - 1;
            normalIndex[count] = (slashSplit[2].toInt()) - 1;
        }

        m_faceElement.push_back(new FaceElement(
            vertexIndex[1], textureIndex[1], normalIndex[1],
            vertexIndex[2], textureIndex[2], normalIndex[2],
            vertexIndex[3], textureIndex[3], normalIndex[3],
            m_currentColor, hasTexture, hasNormals));
    }
}

//////////// File : ImportOBJ //*************************
#include <QFile>
//#include <QString>
#include <QTextStream>
#include <Amber3D/API/Loaders/GfxLoader.h>
#include <Amber3D/API/Shaders/ColorShader.h>
#include <Amber3D/API/Shaders/TextureShader.h>
#include <Amber3D/Models/RawModel.h>

//#include "storeOBJ.h"
namespace Model
{
    class ImportOBJ
    {
        StoreOBJ *m_storeOBJ;
        Amber3D::API::GfxLoader *m_loader;
        Amber3D::API::TextureShader *m_textureShader;
        Amber3D::API::ColorShader *m_colorShader;

    public:
        ImportOBJ();
        ~ImportOBJ();

        Amber3D::Models::RawModel* loadOBJ(const QString &filename);
    };
}

namespace Model
{
    ImportOBJ::ImportOBJ() :
        m_storeOBJ(new StoreOBJ())
      , m_loader(new Amber3D::API::GfxLoader())
      , m_textureShader(new Amber3D::API::TextureShader())
      , m_colorShader(new Amber3D::API::ColorShader())
    {
        qDebug("ImportOBJ Created");
    }

    ImportOBJ::~ImportOBJ()
    {
        delete m_loader;
        delete m_storeOBJ;
        qDebug("ImportOBJ : destroyed");
    }

    Amber3D::Models::RawModel* ImportOBJ::loadOBJ(const QString & filename)
    {
        QString line;
        QString filePath[2];

        filePath[0] = "Resources/OBJ/" + filename + ".obj";
        filePath[1] = "Resources/OBJ/" + filename + ".mtl";

        for (int count = 0; count < 2; count++)
        {
            QFile file(filePath[count]);

            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return nullptr;

            QTextStream in(&file);

            do
            {
                line = in.readLine().trimmed();
                m_storeOBJ->storeData(line);

            } while (!line.isNull());

            file.close();
        }

        m_loader->SetShader(
                    m_colorShader->GetProgramID(),
                    m_textureShader->GetProgramID()
        );

        return m_storeOBJ->sendDataToAPI(
                    m_loader
        );
    }
}

/////////////////////////// Main Window Code ///////////////////////////////////
#include "ConverterWindow.h"
#include "ui_ConverterWindow.h"

ConverterWindow::ConverterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ConverterWindow)
    , m_model(nullptr)
    , m_model_is_loaded(false)
{
    ui->setupUi(this);
    m_mainLoopTimer = new QTimer(this);
    connect(m_mainLoopTimer, SIGNAL(timeout()), this, SLOT(MainLoop()));
}

ConverterWindow::~ConverterWindow()
{
    delete m_mainLoopTimer;
    delete m_model;
    delete ui;
    qDebug("Converter Window Destroyed.");
}

void ConverterWindow::StartMainLoop()
{
    m_mainLoopTimer->start(10);
    qDebug() << "Main Loop Started.";
}

//////////////// Private Slots ////////////////
void ConverterWindow::on_Load_OBJ_clicked()
{
    Load3DModel();
}

void ConverterWindow::on_ExitButton_clicked()
{
    this->close();
}

void ConverterWindow::MainLoop()
{
    m_mainLoopTimer->stop();

    if (m_model_is_loaded)
        this->ui->ViewPortGL->update();

    m_mainLoopTimer->start(10);
}

//////////////////// Private ///////////////////

void ConverterWindow::Load3DModel()
{
    Model::ImportOBJ* importer = new Model::ImportOBJ();
    m_model = importer->loadOBJ("BoxRGB");

    if (m_model == nullptr)
    {
        qDebug() << "[ERROR] : ImportOBJ failed to load Model.";
        this->close();
    }
    else
    {
        qDebug() << "Model Loaded.";
        m_model_is_loaded = true;
//        this->ui->ViewPortGL->SetRendering(
//                    entity,
//                    textureShader,
//                    colorShader
//                    );
    }

}

