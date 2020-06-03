
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

namespace Amber3D
{
    namespace Maths
    {
        class Transform
        {
            bool m_hasChanged;
            QVector3D m_translation;
            QQuaternion m_rotation;
            QVector3D m_scale;
            QMatrix4x4 m_world;

        public:
            Transform();
            void Translate(const QVector3D& deltaTranslation);
            void Translate(float deltaX, float deltaY, float deltaZ);
            void Rotate(const QQuaternion deltaRotation);
            void Rotate(float angle, const QVector3D& axis);
            void Rotate(float angle, float angleX, float angleY, float angleZ);
            void Scale(const QVector3D& deltaScale);
            void Scale(float deltaX, float deltaY, float deltaZ);
            void Grow(const QVector3D& deltaScale);
            void Grow(float deltaX, float deltaY, float deltaZ);

            // Getters
            const QMatrix4x4& GetMatrix();
            const QVector3D& GetTranslation() const { return m_translation; }
            const QQuaternion& GetRotation() const { return m_rotation; }
            const QVector3D& GetScale() const { return m_scale; }

            // Setters
            void SetTranslation(const QVector3D& deltaTranslation);
            void SetTranslate(float deltaX, float deltaY, float deltaZ);
            void SetRotation(const QQuaternion deltaRotation);
            void SetRotate(float angle, const QVector3D& axis);
            void SetRotate(float angle, float angleX, float angleY, float angleZ);
            void SetScale(const QVector3D& deltaScale);
            void SetScale(float deltaX, float deltaY, float deltaZ);
        };
    }
}
