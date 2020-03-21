
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
            DestroyBuffer(
                m_vbos
            );

            DestroyBuffer(
                m_indexBuffers
            );

            for (int index = 0;
                index < m_textures.size();
                index++)
            {
                m_textures[index]->destroy();
            }
            
            for (int index = 0;
                index < m_vaos.size();
                index++)
            { 
                m_vaos[index]->destroy();
            }
        }

        void GfxLoader::SetShader(
            API::TextureShader *currentShader)
        {
            m_currentShader = currentShader;
        }

        Models::RawModel* GfxLoader::LoadToVAO(
            uint *indices, int numIndices,
            float *positions, int numPositions,
            float *colors, int numColors,
            float *texCoords, int numTexCoords)
        {
            QOpenGLVertexArrayObject *vao = CreateVAO();

            StoreIndicesBuffer(
                indices,
                numIndices * sizeof(uint)
            );

            StoreDataToAttribList(
                0,                              // attrib location
                3,                              // tuple size
                positions,                      // data
                numPositions * sizeof(float)    // size
            );
            
            if (numTexCoords >= 2)              // attrib location 1 will be 
                StoreDataToAttribList(          // used for either
                    1,                          // color or texture coords
                    2,
                    texCoords,
                    numTexCoords * sizeof(float)
                );
            else
                StoreDataToAttribList(
                    1,
                    3,
                    colors,
                    numColors * sizeof(float)
                );
                      
            vao->release();
            
            Models::RawModel *rawModel = 
                new Models::RawModel(
                    vao,
                    numIndices
            );
            
            return rawModel;
        }

        QOpenGLTexture* GfxLoader::loadTexture(
            QString fileName)
        {
            QOpenGLTexture *texture = new QOpenGLTexture(
                QImage(
                    "Resources/Textures/" + fileName + ".png"
                )
            );
            
            texture->setMinificationFilter(
                QOpenGLTexture::LinearMipMapLinear
            );

            texture->setMagnificationFilter(
                QOpenGLTexture::Linear
            );

            m_textures.push_back(
                texture
            );

            return texture;
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
            int tupleSize,
            float *data,
            int dataSize)                       // NB size in bytes
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
                attribute,                          // location
                GL_FLOAT,                           // type
                0,                                  // offset
                tupleSize,                          // tuple size
                0                                   // stride
            );

            m_vbos.push_back(
                dataBuffer
            );
        }

        void GfxLoader::StoreIndicesBuffer(
            uint *data,
            int dataSize)                           // NB size in bytes
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
            for (int index = 0;
                index < buffer.size();
                index ++)
            { 
                buffer[index]->destroy();
            }
        }
    }
}
