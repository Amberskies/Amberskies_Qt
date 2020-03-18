
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
            : m_currentShader(nullptr)
        {
            // Empty
        }
        
        GfxLoader::~GfxLoader()
        {
            for (
                int index = 0;
                index <= m_vaos.size();
                index ++
            ) 
                m_vaos[index]->destroy();

            DestroyBuffer(
                m_vbos
            );

            DestroyBuffer(
                m_indexBuffers
            );
        }

        void GfxLoader::SetShader(
            API::StaticShader *currentShader)
        {
            m_currentShader = currentShader;
        }

        Models::RawModel* GfxLoader::LoadToVAO(
            uint *indices, int numIndices,
            float *positions, int numPositions)
        {
            QOpenGLVertexArrayObject *vao = CreateVAO();

            StoreIndicesBuffer(
                indices,
                numIndices * sizeof(uint)
            );

            StoreDataToAttribList(
                0,
                positions,
                numPositions * sizeof(float)
            );
            
            vao->release();
            
            Models::RawModel *rawModel = 
                new Models::RawModel(
                    vao,
                    numIndices
            );
            
            return rawModel;
        }

        //////////////////// Private /////////////////////////
        QOpenGLVertexArrayObject* GfxLoader::CreateVAO()
        {
            QOpenGLVertexArrayObject *currentVAO = 
                new QOpenGLVertexArrayObject();
            
            currentVAO->create();
            currentVAO->bind();

            m_vaos.push_back(
                currentVAO
            );

            return currentVAO;
        }

        void GfxLoader::StoreDataToAttribList(
            int attribute,
            float *data,
            int dataSize)
        {
            QOpenGLBuffer *dataBuffer = 
                new QOpenGLBuffer(
                    QOpenGLBuffer::VertexBuffer
            );
            
            dataBuffer->create();
            dataBuffer->bind();
            
            dataBuffer->allocate(
                data,
                dataSize
            );

            m_currentShader->GetProgramID()->enableAttributeArray(
                attribute
            );

            m_currentShader->GetProgramID()->setAttributeBuffer(
                attribute,
                GL_FLOAT,
                0,
                3,
                0
            );

            m_vbos.push_back(
                dataBuffer
            );
        }

        void GfxLoader::StoreIndicesBuffer(
            uint *data, int dataSize)
        {
            QOpenGLBuffer *indexBuffer = 
                new QOpenGLBuffer(
                    QOpenGLBuffer::IndexBuffer
            );

            indexBuffer->create();
            indexBuffer->bind();
            
            indexBuffer->allocate(
                data,
                dataSize
            );

            m_indexBuffers.push_back(
                indexBuffer
            );
        }

        void GfxLoader::DestroyBuffer(
            QVector<QOpenGLBuffer*> buffer)
        {
            for (
                int index = 0;
                index <= buffer.size();
                index ++
            ) 
                buffer[index]->destroy();
        }
    }
}
