
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 14th
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
#include "FunctionKey3.h"
#include <QDebug>

FunctionKey3::FunctionKey3(QOpenGLFunctions_3_3_Core *gl)
    : m_gl(gl)
    , m_model(nullptr)
    , m_texturedModel(nullptr)
    , m_texture1(nullptr)
    , m_entity(nullptr)
    , m_camera(nullptr)
    , m_textureShader(new Amber3D::API::TextureShader())
    , m_colorShader(new Amber3D::API::ColorShader())
    , m_loader(new Amber3D::API::GfxLoader())
    , m_renderer(new Amber3D::OpenGL::Renderer(m_gl))
    
{
    // Empty 
}
FunctionKey3::~FunctionKey3()
{   
    delete m_renderer;
    delete m_loader;
    delete m_colorShader;
    delete m_textureShader;
    delete m_camera;
    delete m_entity;
    delete m_texture1;
    delete m_texturedModel;
    delete m_model;
}
void FunctionKey3::F3_Initialize()
{
    //uint indices [] =
    //{
    //    0, 1, 3,
    //    3, 1, 2 
    //};

    //float vertices [] =
    //{
    //    // Left Bottom Triangle
    //    -0.5f,  0.5f, 0.0f, // 0
    //    -0.5f, -0.5f, 0.0f, // 1
    //     0.5f, -0.5f, 0.0f, // 2
    //     0.5f,  0.5f, 0.0f, // 3
    //};

    //float colors [] =
    //{
    //    0
    //    // 1.0f, 0.0f, 0.0f,
    //    // 0.0f, 1.0f, 0.0f,
    //    // 0.0f, 0.0f, 1.0f,
    //    // 1.0f, 1.0f, 1.0f,
    //};

    //float textureCoords [] =
    //{
    //    //0
    //    0.0f, 0.0f,     // 0
    //    0.0f, 1.0f,     // 1
    //    1.0f, 1.0f,     // 2
    //    1.0f, 0.0f      // 3
    //};

    /////////////////// Load a Converted 3D Model from HD ///////////////////////////
    // eg 1 = textured model
    // requirements :
    // to place data into arrays
    QString model_to_load = "Body";
    int numIndices = 1;

    QString filePath = "Resources/AmberModels/" + model_to_load + ".amb";
    QString line;

    QFile file_in(filePath);

    bool file_is_open = file_in.open(QIODevice::ReadOnly | QIODevice::Text);
    if (file_is_open == false)  qDebug("[Error] : unable to open 3D model file.");

    QTextStream in(&file_in);
   
    bool hasTextures = false;
    bool hasNormals = false;
    QString texture_filename;

    do
    {
        // read each line until end of file
        line = in.readLine().trimmed();
        // compare with possible lines as give in objDataStructure.h
        QStringList data = line.split(" ");

        /////////////////////////// AMB File /////////////////////////////

        if(line.startsWith("hasTexture:")) hasTextures = data.at(1).toUInt();
        if (line.startsWith("textureFilename:")) texture_filename = data.at(1);
        if (line.startsWith("numIndices:")) numIndices = data.at(1).toInt();
        if (line.startsWith("hasNormals:")) hasNormals = data.at(1).toUInt();


    }while (line.startsWith("# Array Start :") == false);

    // array indices;
    uint* indices = new uint[numIndices];
    for (uint i = 0; i < numIndices; i++) indices[i] = i;

    // array vertices;
    int numVertices = numIndices * 3;
    float* vertices = new float[numVertices];
    int count = 0;
    do
    {
        // read each line until end of file
        line = in.readLine().trimmed();
        // compare with possible lines as give in objDataStructure.h
        QStringList data = line.split(" ");

        /////////////////////////// AMB Verticies /////////////////////////////

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
        do
        {
            // read each line until end of file
            line = in.readLine().trimmed();
            // compare with possible lines as give in objDataStructure.h
            QStringList data = line.split(" ");

            /////////////////////////// AMB Normals /////////////////////////////

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
        do
        {
            // read each line until end of file
            line = in.readLine().trimmed();
            // compare with possible lines as give in objDataStructure.h
            QStringList data = line.split(" ");

            /////////////////////////// AMB TexCoords /////////////////////////////

            if (line.startsWith("#")) continue;
            textureCoords[count++] = data.at(0).toFloat();
            textureCoords[count++] = data.at(1).toFloat();
        } while (count < numTexCoords);

    }
    else
    {
        textureCoords[0] = 0.0f;
        numTexCoords = 1;

        do
        {
            // read each line until end of file
            line = in.readLine().trimmed();
            // compare with possible lines as give in objDataStructure.h
            QStringList data = line.split(" ");

            /////////////////////////// AMB Colors /////////////////////////////

            if (line.startsWith("#")) continue;
            colors[count++] = data.at(0).toFloat();
            colors[count++] = data.at(1).toFloat();
            colors[count++] = data.at(2).toFloat();

        } while (count < numColors);
    }


    /////////////////////////////////////////////////////////////////////////////////

    m_loader->SetShader(
        m_colorShader->GetProgramID(),
        m_textureShader->GetProgramID()
    );

    m_model = 
        m_loader->LoadToVAO(
            indices, numIndices,
            vertices, numVertices,
            colors, numColors,
            textureCoords, numTexCoords
    );
    
    //if (m_model->GetHasTexture())
        // we cant use the if statement until we
        // give our model a default texture 
        // even it this only contains 1 pixel
        
        m_texture1 = new Amber3D::Textures::ModelTexture(
            m_loader->loadTexture(
                texture_filename
            )
        );

    m_texturedModel = new Amber3D::Models::TexturedModel(
        m_model,
        m_texture1
    );
    
    m_entity = new Amber3D::Entities::TexturedEntity(
        m_texturedModel,
        QVector3D(0.0f, 0.0f, -3.0f),          // Position
        0.0f,                                   // rotation X
        0.0f,                                   // rotation Y
        0.0f,                                   // rotation X
        1.0f                                    // scale where 1.0f == 100%
    );

    m_camera = new Amber3D::Entities::Camera(
        QVector3D(0.0f, 0.0f, 0.0f),
        0.0f,                                   // pitch (x-axis)
        0.0f,                                   // yaw   (y-axis)      
        0.0f                                    // roll  (z-axis)
    );

    qDebug("F3 initialized");
}

void FunctionKey3::Go(QMatrix4x4 projection)
{
    m_renderer->prepare();
    
    // Game Logic

    m_camera->MoveCamera(0.03f); // sets camera move speed

    if (m_entity->GetTexturedModel()->GetRawModel()->GetHasTexture())
        m_renderer->render(
        m_camera,
        m_entity,
        m_textureShader->GetProgramID(),
        projection
    );    
    else 
        m_renderer->render(
        m_camera,
        m_entity,
        m_colorShader->GetProgramID(),
        projection
    );
    
    // this is a test
    m_entity->IncreaseRotation(
        0.0f,                               // delta around X-axis
        0.0f,                               // delta around Y-axis
        -0.1f                               // delta around Z-axis -ve = cw +ve = ccw
    );
}
