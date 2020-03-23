
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
#include "TexturedEntity.h"
#include "Amber3D/Maths/ClampRotation.h"

namespace Amber3D
{
    namespace Entities
    {
        TexturedEntity::TexturedEntity(
            Models::TexturedModel *texturedModel,
            QVector3D position,
            float rotationX,
            float rotationY,
            float rotationZ,
            float scale)
            : m_texturedModel(texturedModel)
            , m_position(position)
            , m_rotationX(rotationX)
            , m_rotationY(rotationY)
            , m_rotationZ(rotationZ)
            , m_scale(scale)
        {
            // Empty
        }

        void TexturedEntity::IncreasePosition(
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

        void TexturedEntity::IncreaseRotation(
            float deltaX,
            float deltaY,
            float deltaZ)
        {
            m_rotationX = Maths::ClampRotation(
                m_rotationX += deltaX
            );

            m_rotationY = Maths::ClampRotation(
                m_rotationY += deltaY
            );

            m_rotationZ = Maths::ClampRotation(
                m_rotationZ += deltaZ
            );            
        }
    }
}
