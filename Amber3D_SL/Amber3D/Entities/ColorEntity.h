
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 23rd
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
#include <QVector3D>
#include "Amber3D/Models/RawModel.h"

namespace Amber3D
{
    namespace Entities
    {
        class ColorEntity
        {
            Models::RawModel *m_rawModel;
            QVector3D m_position;
            float m_rotationX;
            float m_rotationY;
            float m_rotationZ;
            float m_scale;

        public:
            ColorEntity(
                Models::RawModel *rawModel,
                QVector3D position,
                float rotationX,
                float rotationY,
                float rotationZ,
                float scale
            );

            void IncreasePosition(
                float deltaX,
                float deltaY,
                float deltaZ
            );

            void IncreaseRotation(
                float deltaX,
                float deltaY,
                float deltaZ
            );

            // Getters
            Models::RawModel* GetRawModel() { return m_rawModel; }
            QVector3D GetPosition() { return m_position; }
            float GetRotationX() { return m_rotationX; }
            float GetRotationY() { return m_rotationY; }
            float GetRotationZ() { return m_rotationZ; }
            float GetScale() { return m_scale; }
            // Setters
            void SetRawModel(Models::RawModel *rawModel) { m_rawModel = rawModel; }
            void SetPosition(QVector3D position) { m_position = position; }
            void SetRotationX(float rotationX) { m_rotationX = rotationX; }
            void SetRotationY(float rotationY) { m_rotationY = rotationY; }
            void SetRotationZ(float rotationZ) { m_rotationZ = rotationZ; }
            void SetScale(float scale) { m_scale = scale;}
        };
    }
}
