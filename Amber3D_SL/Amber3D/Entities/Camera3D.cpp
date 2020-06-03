
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
#include "Camera3D.h"


namespace Amber3D
{
    namespace Entities
    {
        QVector3D Camera3D::localForward(0.0f, 0.0f, -1.0f);
        QVector3D Camera3D::localUp(0.0f, 1.0f, 0.0f);
        QVector3D Camera3D::localRight(1.0f, 0.0f, 0.0f);

        Camera3D::Camera3D()
            : m_hasChanged(false)
            , m_translation(QVector3D(0.0f, 0.0f, 0.0f))
            , m_rotation(QQuaternion())
        {
            m_world.setToIdentity();
        }

        void Camera3D::Translate(QVector3D& deltaTranslation)
        {
            m_hasChanged = true;
            m_translation += deltaTranslation;
        }

        void Camera3D::Rotate(QQuaternion& deltaRotation)
        {
            m_hasChanged = true;
            m_rotation = deltaRotation * m_rotation;
        }

        void Camera3D::SetTranslation(QVector3D &translation)
        {
            m_hasChanged = true;
            m_translation = translation;
        }

        void Camera3D::SetRotation(QQuaternion& rotation)
        {
            m_hasChanged = true;
            m_rotation = rotation;
        }

        const QMatrix4x4& Camera3D::GetMatrix()
        {
            if (m_hasChanged)
            {
                m_hasChanged = false;
                m_world.setToIdentity();
                m_world.rotate(m_rotation.conjugated());
                m_world.translate(-m_translation);
            }
            return m_world;
        }

        QVector3D Camera3D::Forward()
        {
            return m_rotation.rotatedVector(localForward);
        }

        QVector3D Camera3D::Up()
        {
            return m_rotation.rotatedVector(localUp);
        }

        QVector3D Camera3D::Right()
        {
            return m_rotation.rotatedVector(localRight);
        }


    }
}
