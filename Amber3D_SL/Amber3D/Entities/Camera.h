
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

namespace Amber3D
{
    namespace Entities
    {
        class Camera
        {
            QVector3D m_position;
            float m_pitch;
            float m_yaw;
            float m_roll;
        public:
            Camera(
                QVector3D position,
                float pitch,
                float yaw,
                float roll
            );

            void MoveCamera();

            void IncreasePosition(
                float deltaX,
                float deltaY,
                float deltaZ
            );

            void IncreaseRotation(
                float pitch,
                float yaw,
                float roll
            );

            // Getters
            QVector3D GetPosition() { return m_position; }
            float GetPitch() { return m_pitch; }
            float GetYaw() { return m_yaw; }
            float GetRoll() { return m_roll; }
            // Setters
            void SetPosition(QVector3D position) { m_position = position; }
            void SetPitch(float pitch) { m_pitch = pitch; }
            void SetYaw(float yaw) { m_yaw = yaw; }
            void SetRoll(float roll) { m_roll = roll; }
        };
    }
}
