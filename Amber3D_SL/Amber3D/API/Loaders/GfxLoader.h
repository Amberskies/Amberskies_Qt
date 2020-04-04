
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
#pragma once
#include "Amber3D/Common.h"
#include <QVector>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include "Amber3D/Models/RawModel.h"
#include "Amber3D/API/Shaders/TextureShader.h"
#include "Amber3D/API/Shaders/ColorShader.h"

namespace Amber3D
{
    namespace API
    {
        class GfxLoader
        {
            QVector<QOpenGLVertexArrayObject*> m_vaos;
            QVector<QOpenGLBuffer*> m_vbos;
            QVector<QOpenGLBuffer*> m_indexBuffers;
            QVector<QOpenGLTexture*> m_textures;

            //API::TextureShader *m_textureShader;
            //API::ColorShader *m_colorShader;
            QOpenGLShaderProgram *m_textureShader;
            QOpenGLShaderProgram *m_colorShader;
            QOpenGLShaderProgram *m_currentShader;

        public:
            GfxLoader();
            ~GfxLoader();

            void SetShader(
                QOpenGLShaderProgram *colorShader,
                QOpenGLShaderProgram *textureShader
            );

            Models::RawModel* LoadToVAO(            // Need to add normals
                uint *indices, int numIndices,
                float *positions, int numPositions,
                float *color, int numColors,
                float *texCoords, int numTexCoords
            );
                      
            QOpenGLTexture* loadTexture(
                QString fileName
            );
                                        
        private:
            QOpenGLVertexArrayObject* CreateVAO();

            void StoreDataToAttribList(
                int attribute,
                int tupleSize, 
                float *data, 
                int dataSize
            );

            void StoreIndicesBuffer(
                uint *data,
                int dataSize
            );

            void DestroyBuffer(
                QVector<QOpenGLBuffer*> buffer
            );

            NULL_COPY_AND_ASSIGN(GfxLoader)
        };        
    }
}
