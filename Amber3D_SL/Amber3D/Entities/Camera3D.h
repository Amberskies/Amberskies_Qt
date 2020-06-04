
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
#pragma once

#include "Amber3D/Common.h"
#include "Amber3D/Maths/Transform3D.h"

namespace Amber3D
{
    namespace Entities
    {
        class Camera3D
        {
        public:

          // Constants
          static const QVector3D LocalForward;
          static const QVector3D LocalUp;
          static const QVector3D LocalRight;

          // Constructors
          Camera3D();

          // Add/Scale
          void Translate(const QVector3D &dt);
          void Translate(float dx, float dy, float dz);
          void Rotate(const QQuaternion &dr);
          void Rotate(float angle, const QVector3D &axis);
          void Rotate(float angle, float ax, float ay, float az);

          // Setters
          void SetTranslation(const QVector3D &t);
          void SetTranslation(float x, float y, float z);
          void SetRotation(const QQuaternion &r);
          void SetRotation(float angle, const QVector3D &axis);
          void SetRotation(float angle, float ax, float ay, float az);

          // Getters
          const QVector3D& Translation() const;
          const QQuaternion& Rotation() const;
          const QMatrix4x4& ToMatrix();

          // Queries
          QVector3D Forward() const;
          QVector3D Up() const;
          QVector3D Right() const;

        private:
          bool m_hasChanged;
          QVector3D m_translation;
          QQuaternion m_rotation;
          QMatrix4x4 m_world;

        #ifndef QT_NO_DATASTREAM
          friend QDataStream &operator<<(QDataStream &out, const Camera3D &transform);
          friend QDataStream &operator>>(QDataStream &in, Camera3D &transform);
        #endif
        };


        // Constructors
        inline Camera3D::Camera3D() : m_hasChanged(true) {}


        // Add/Scale
        inline void Camera3D::Translate(float dx, float dy,float dz)
        { Translate(QVector3D(dx, dy, dz)); }

        inline void Camera3D::Rotate(float angle, const QVector3D &axis)
        { Rotate(QQuaternion::fromAxisAndAngle(axis, angle)); }

        inline void Camera3D::Rotate(float angle, float ax, float ay,float az)
        { Rotate(QQuaternion::fromAxisAndAngle(ax, ay, az, angle)); }


        // Setters
        inline void Camera3D::SetTranslation(float x, float y, float z)
        { SetTranslation(QVector3D(x, y, z)); }

        inline void Camera3D::SetRotation(float angle, const QVector3D &axis)
        { SetRotation(QQuaternion::fromAxisAndAngle(axis, angle)); }

        inline void Camera3D::SetRotation(float angle, float ax, float ay, float az)
        { SetRotation(QQuaternion::fromAxisAndAngle(ax, ay, az, angle)); }

        // Getters
        inline const QVector3D& Camera3D::Translation() const { return m_translation; }
        inline const QQuaternion& Camera3D::Rotation() const { return m_rotation; }

        // Qt Streams
        #ifndef QT_NO_DEBUG_STREAM
        QDebug operator<<(QDebug dbg, const Camera3D &transform);
        #endif

        #ifndef QT_NO_DATASTREAM
        QDataStream &operator<<(QDataStream &out, const Camera3D &transform);
        QDataStream &operator>>(QDataStream &in, Camera3D &transform);
        #endif
    }
}
Q_DECLARE_TYPEINFO(Amber3D::Entities::Camera3D, Q_MOVABLE_TYPE);
