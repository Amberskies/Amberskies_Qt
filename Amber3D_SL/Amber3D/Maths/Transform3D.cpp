
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
#include "Transform3D.h"
#include <QDebug>

namespace Amber3D
{
    namespace Maths
    {
        const QVector3D Transform3D::LocalForward(0.0f, 0.0f, 1.0f);
        const QVector3D Transform3D::LocalUp(0.0f, 1.0f, 0.0f);
        const QVector3D Transform3D::LocalRight(1.0f, 0.0f, 0.0f);

        // Add/Scale
        void Transform3D::Translate(const QVector3D &dt)
        {
          m_hasChanged = true;
          m_translation += dt;
        }

        void Transform3D::Scale(const QVector3D &ds)
        {
          m_hasChanged = true;
          m_scale *= ds;
        }

        void Transform3D::Rotate(const QQuaternion &dr)
        {
          m_hasChanged = true;
          m_rotation = dr * m_rotation;
        }

        void Transform3D::Grow(const QVector3D &ds)
        {
          m_hasChanged = true;
          m_scale += ds;
        }

        // Transform To (Setters)
        void Transform3D::SetTranslation(const QVector3D &t)
        {
          m_hasChanged = true;
          m_translation = t;
        }

        void Transform3D::SetScale(const QVector3D &s)
        {
          m_hasChanged = true;
          m_scale = s;
        }

        void Transform3D::SetRotation(const QQuaternion &r)
        {
          m_hasChanged = true;
          m_rotation = r;
        }

        // Accessors
        const QMatrix4x4 &Transform3D::ToMatrix()
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

        // Queries
        QVector3D Transform3D::Forward() const
        {
          return m_rotation.rotatedVector(LocalForward);
        }

        QVector3D Transform3D::Up() const
        {
          return m_rotation.rotatedVector(LocalUp);
        }

        QVector3D Transform3D::Right() const
        {
          return m_rotation.rotatedVector(LocalRight);
        }

        // Qt Streams
        QDebug operator<<(QDebug dbg, const Transform3D &transform)
        {
          dbg << "Transform3D\n{\n";
          dbg << "Position: <" << transform.Translation().x() << ", " << transform.Translation().y() << ", " << transform.Translation().z() << ">\n";
          dbg << "Scale: <" << transform.Scale().x() << ", " << transform.Scale().y() << ", " << transform.Scale().z() << ">\n";
          dbg << "Rotation: <" << transform.Rotation().x() << ", " << transform.Rotation().y() << ", " << transform.Rotation().z() << " | " << transform.Rotation().scalar() << ">\n}";
          return dbg;
        }

        QDataStream &operator<<(QDataStream &out, const Transform3D &transform)
        {
          out << transform.m_translation;
          out << transform.m_scale;
          out << transform.m_rotation;
          return out;
        }

        QDataStream &operator>>(QDataStream &in, Transform3D &transform)
        {
          in >> transform.m_translation;
          in >> transform.m_scale;
          in >> transform.m_rotation;
          transform.m_hasChanged = true;
          return in;
        }
    }
}
