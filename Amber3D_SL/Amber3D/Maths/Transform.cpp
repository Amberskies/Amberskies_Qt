
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Jun 2nd
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
#include "Transform.h"


namespace Amber3D
{
    namespace Maths
    {
        Transform::Transform()
            : m_hasChanged(false)
            , m_translation(QVector3D(0.0f, 0.0f, 0.0f))
            , m_scale(QVector3D(1.0f, 1.0f, 1.0f))
        {
            m_rotation = QQuaternion::QQuaternion();
            m_world.setToIdentity();
        }

        void Transform::Translate(const QVector3D& deltaTranslation)
        {
            m_hasChanged = true;
            m_translation += deltaTranslation;
        }

        void Transform::Rotate(const QQuaternion deltaRotation)
        {
            m_hasChanged = true;
            m_rotation = deltaRotation * m_rotation;
        }
        
        void Transform::Scale(const QVector3D& deltaScale)
        {
            m_hasChanged = true;
            m_scale *= deltaScale;
        }

        void Transform::Grow(const QVector3D& deltaScale)
        {
            m_hasChanged = true;
            m_scale += deltaScale;
        }

        // Getters
        const QMatrix4x4& Transform::GetMatrix()
        {
            if (m_hasChanged)
            {
                m_hasChanged = false;
                m_world.setToIdentity();
                m_world.translate(m_translation);
                m_world.rotate(m_rotation);
                m_world.scale(m_scale);
            }

            return m_world;
        }
        // Setters
        void Transform::setTranslation(const QVector3D& deltaTranslation)
        {
            m_hasChanged = true;
            m_translation = deltaTranslation;
        }

        void Transform::setRotation(const QQuaternion deltaRotation)
        {
            m_hasChanged = true;
            m_rotation = deltaRotation;
        }

        void Transform::setScale(const QVector3D& deltaScale)
        {
            m_hasChanged = true;
            m_scale = deltaScale;
        }
    }
}
