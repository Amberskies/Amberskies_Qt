
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

#include <QVector3D>
#include <QQuaternion>
#include <QMatrix4x4>
#include <QDataStream>
#include <QDebug>

namespace Amber3D
{
    namespace Maths
    {
        class Transform3D
        {
        public:

          // Constants
          static const QVector3D LocalForward;
          static const QVector3D LocalUp;
          static const QVector3D LocalRight;

          // Constructors
          Transform3D();

          // Add/Scale
          void Translate(const QVector3D &dt);
          void Translate(float dx, float dy, float dz);
          void Scale(const QVector3D &ds);
          void Scale(float dx, float dy, float dz);
          void Scale(float factor);
          void Rotate(const QQuaternion &dr);
          void Rotate(float angle, const QVector3D &axis);
          void Rotate(float angle, float ax, float ay, float az);
          void Grow(const QVector3D &ds);
          void Grow(float dx, float dy, float dz);
          void Grow(float factor);

          // Setters
          void SetTranslation(const QVector3D &t);
          void SetTranslation(float x, float y, float z);
          void SetScale(const QVector3D &s);
          void SetScale(float x, float y, float z);
          void SetScale(float k);
          void SetRotation(const QQuaternion &r);
          void SetRotation(float angle, const QVector3D &axis);
          void SetRotation(float angle, float ax, float ay, float az);

          // Accessors
          const QVector3D& Translation() const;
          const QVector3D& Scale() const;
          const QQuaternion& Rotation() const;
          const QMatrix4x4& ToMatrix();

          // Queries
          QVector3D Forward() const;
          QVector3D Up() const;
          QVector3D Right() const;

        private:
          bool m_hasChanged;
          QVector3D m_translation;
          QVector3D m_scale;
          QQuaternion m_rotation;
          QMatrix4x4 m_world;

        #ifndef QT_NO_DATASTREAM
          friend QDataStream &operator<<(QDataStream &out, const Transform3D &transform);
          friend QDataStream &operator>>(QDataStream &in, Transform3D &transform);
        #endif
        };


        inline Transform3D::Transform3D() : m_hasChanged(true), m_scale(1.0f, 1.0f, 1.0f) {}


        // Transform By (Add/Scale)
        inline void Transform3D::Translate(float dx, float dy,float dz)
        { Translate(QVector3D(dx, dy, dz)); }

        inline void Transform3D::Scale(float dx, float dy,float dz)
        { Scale(QVector3D(dx, dy, dz)); }

        inline void Transform3D::Scale(float factor)
        { Scale(QVector3D(factor, factor, factor)); }

        inline void Transform3D::Rotate(float angle, const QVector3D &axis)
        { Rotate(QQuaternion::fromAxisAndAngle(axis, angle)); }

        inline void Transform3D::Rotate(float angle, float ax, float ay,float az)
        { Rotate(QQuaternion::fromAxisAndAngle(ax, ay, az, angle)); }

        inline void Transform3D::Grow(float dx, float dy, float dz)
        { Grow(QVector3D(dx, dy, dz)); }

        inline void Transform3D::Grow(float factor)
        { Grow(QVector3D(factor, factor, factor)); }

        // Setters
        inline void Transform3D::SetTranslation(float x, float y, float z)
        { SetTranslation(QVector3D(x, y, z)); }

        inline void Transform3D::SetScale(float x, float y, float z)
        { SetScale(QVector3D(x, y, z)); }

        inline void Transform3D::SetScale(float k)
        { SetScale(QVector3D(k, k, k)); }

        inline void Transform3D::SetRotation(float angle, const QVector3D &axis)
        { SetRotation(QQuaternion::fromAxisAndAngle(axis, angle)); }

        inline void Transform3D::SetRotation(float angle, float ax, float ay, float az)
        { SetRotation(QQuaternion::fromAxisAndAngle(ax, ay, az, angle)); }

        // Accessors
        inline const QVector3D& Transform3D::Translation() const { return m_translation; }
        inline const QVector3D& Transform3D::Scale() const { return m_scale; }
        inline const QQuaternion& Transform3D::Rotation() const { return m_rotation; }

        // Qt Streams
        #ifndef QT_NO_DEBUG_STREAM
        QDebug operator<<(QDebug dbg, const Transform3D &transform);
        #endif

        #ifndef QT_NO_DATASTREAM
        QDataStream &operator<<(QDataStream &out, const Transform3D &transform);
        QDataStream &operator>>(QDataStream &in, Transform3D &transform);
        #endif
    }
}
Q_DECLARE_TYPEINFO(Amber3D::Maths::Transform3D, Q_MOVABLE_TYPE);

