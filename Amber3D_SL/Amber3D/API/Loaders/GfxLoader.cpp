
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

#include "GfxLoader.h"

namespace Amber3D
{
    namespace API
    {
        GfxLoader::GfxLoader()
            : m_vaos(new QVector<QOpenGLVertexArrayObject*>)
            , m_currentShader(nullptr)
        {
            // Empty
        }
        
        GfxLoader::~GfxLoader()
        {
            
        }

        void GfxLoader::SetShader(QOpenGLShaderProgram *currentShader)
        {
            m_currentShader = currentShader;
        }

        Models::RawModel* GfxLoader::LoadToVAO(float *positions, int numPositions)
        {
            QOpenGLVertexArrayObject *vao = CreateVAO();

            StoreDataToAttribList(0, positions, numPositions * sizeof(float));

            vao->release();
            
            Models::RawModel *rawModel = new Models::RawModel(vao, (numPositions / 3));
            return rawModel;
        }

        //////////////////// Private /////////////////////////
        QOpenGLVertexArrayObject* GfxLoader::CreateVAO()
        {
            QOpenGLVertexArrayObject *currentVAO = new QOpenGLVertexArrayObject();
            currentVAO->create();
            currentVAO->bind();

            m_vaos->push_back(currentVAO);
            return currentVAO;
        }

        void GfxLoader::StoreDataToAttribList(int attribute, float *data, int dataSize)
        {
            QOpenGLBuffer *dataBuffer = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
            
            dataBuffer->create();
            dataBuffer->bind();
            dataBuffer->allocate(data, dataSize);

            m_currentShader->enableAttributeArray(attribute);
            m_currentShader->setAttributeBuffer(attribute, GL_FLOAT, 0, 3, 0);
        }

    }
}
