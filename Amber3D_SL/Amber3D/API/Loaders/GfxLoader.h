
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
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

#include "Amber3D/Models/RawModel.h"


namespace Amber3D
{
    namespace API
    {
        class GfxLoader
        {
            QVector<QOpenGLVertexArrayObject*> m_vaos;
            QVector<QOpenGLBuffer*> m_vbos;
            
            QOpenGLShaderProgram *m_currentShader;

            public:
                GfxLoader();
                ~GfxLoader();

                void SetShader(QOpenGLShaderProgram *currentShader);
                Models::RawModel* LoadToVAO(float *positions, int numPositions);
            
            private:
                QOpenGLVertexArrayObject* CreateVAO();
                void StoreDataToAttribList(int attribute, float *data, int dataSize);
                void UnbindVAO();

                NULL_COPY_AND_ASSIGN(GfxLoader)
        };        
    }
}
