
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
#include "Amber3D/Maths/Transform.h"

namespace Amber3D
{
    namespace Entities
    {
        class Camera3D
        {
            bool m_hasChanged;
            QVector3D m_translation;
            QQuaternion m_rotation;
            QMatrix4x4 m_world;

        public:
            static  QVector3D localForward;
            static  QVector3D localUp;
            static  QVector3D localRight;

            Camera3D();

            void Translate( QVector3D& deltaTranslation);
            void Translate(float deltaX, float deltaY, float deltaZ);
            void Rotate(QQuaternion& deltaRotation);
            void Rotate(float angle, QVector3D& axis);
            void Rotate(float angle, float angleX, float angleY, float angleZ);

            // Setters
            void SetTranslation(QVector3D& translation);
            void SetTranslation(float deltaX, float deltaY, float deltaZ);
            void SetRotation(QQuaternion &rotation);
            void SetRotation(float angle, QVector3D& axis);
            void SetRotation(float angle, float angleX, float angleY, float angleZ);
            
            // Getters
            const QVector3D& GetTranslation() { return m_translation; }
            const QQuaternion& GetRotation() { return m_rotation; }
            const QMatrix4x4& GetMatrix();

            QVector3D Forward();
            QVector3D Up();
            QVector3D Right();
        };
    }
}
