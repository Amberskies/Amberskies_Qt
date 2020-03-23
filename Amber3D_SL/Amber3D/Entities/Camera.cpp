
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
#include "Camera.h"
#include <Amber3D/Maths/ClampRotation.h>

namespace Amber3D
{
    namespace Entities
    {
        Camera::Camera(
            QVector3D position,
            float pitch,
            float yaw,
            float roll)
            : m_position(position)
            , m_pitch(pitch)
            , m_yaw(yaw)
            , m_roll(roll)
        {
            // empty
        }
        void Camera::MoveCamera()
        {
            // keyboard input required.
        }
        
        void Camera::IncreasePosition(
            float deltaX,
            float deltaY,
            float deltaZ)
        {
            m_position.setX(
                m_position.x() + deltaX
            );

            m_position.setY(
                m_position.y() + deltaY
            );

            m_position.setZ(
                m_position.z() + deltaZ
            );
        }

        void Camera::IncreaseRotation(
            float pitch,
            float yaw,
            float roll)
        {
            m_pitch = Maths::ClampRotation(
                m_pitch += pitch
            );

            m_yaw = Maths::ClampRotation(
                m_yaw += yaw
            );

            m_roll = Maths::ClampRotation(
                m_roll += roll
            );            
        }
    }
}
