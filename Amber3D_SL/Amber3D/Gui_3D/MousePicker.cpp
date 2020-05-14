
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 May 11th
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
#include "MousePicker.h"
#include "Input.h"
#include <Amber3D/Maths/CreateViewMatrix.h>


namespace Amber3D
{
    namespace Gui_3D
    {
        MousePicker::MousePicker()
            : m_camera(nullptr)
            , m_terrain(nullptr)
        {
            // Empty
        }

        QVector3D MousePicker::update(
            QPoint mousePosition,
            Entities::TexturedEntity* terrain,
                int width,
                int height,
            Entities::Camera* camera,
            QMatrix4x4 projection)
        {
            m_terrain = terrain;
            m_camera = camera;
            m_mousePosition = mousePosition;

            m_currentRay = CalcMouseRay(
                width,
                height,
                projection
            );

             m_currentCursor = QVector3D(0.0f, 0.0f, 0.0f);

            if (IntersectionInRange(0, RAY_RANGE))
            {
                m_currentCursor = BinarySearch(
                    0,
                    0.0f,
                    RAY_RANGE
                );
            }

            return m_currentCursor;
        }

        /////////////////////// Private ////////////////////////

        QVector2D MousePicker::GetNormalizedWindowCoord(
            float windowWidth,
            float windowHeight)
        {
            QVector2D mouseLoc;
            mouseLoc.setX(m_mousePosition.x());
            mouseLoc.setY(m_mousePosition.y());

            mouseLoc.setX(
                ((2.0f * mouseLoc.x()) / windowWidth) - 1
            );

            mouseLoc.setY(
                ((2.0f * mouseLoc.y()) / windowHeight) - 1
            );

            return mouseLoc;
        }

        QVector4D MousePicker::ConvertToViewSpace(
            QMatrix4x4 projection,
            QVector4D mousePos)
        {
            QMatrix4x4 invertedProjection = projection.inverted();
            QVector4D projectionSpace = invertedProjection * -mousePos; 
            
            return QVector4D(
                projectionSpace.x(),
                projectionSpace.y(),
                -1.0f,
                0.0f
            );
        }

        QVector3D MousePicker::ConvertToModelSpace(
            QVector4D projectionSpace)
        {
            QMatrix4x4 view = Maths::CreateViewMatrix(m_camera);
            QMatrix4x4 invertedView = view.inverted();
            QVector4D rayView = invertedView * projectionSpace;
            rayView.normalize();
            
            return QVector3D(
                rayView.x(),
                rayView.y(),
                rayView.z()
            );
        }

        QVector3D MousePicker::CalcMouseRay(
            int width,
            int height,
            QMatrix4x4 projection)
        {
            QVector2D windowCoord = GetNormalizedWindowCoord(
                width,
                height
            );

            QVector4D mousePos = QVector4D(
                windowCoord.x(),
                windowCoord.y(),
                -1.0f,
                1.0f
            );

            QVector4D viewCoord = ConvertToViewSpace(
                projection,
                mousePos
            );

            QVector3D modelCoord = ConvertToModelSpace(
                viewCoord
            );

            return modelCoord;
        }

        // next check the models against the ray for an intersection.

        bool MousePicker::IntersectionInRange(float start, float finish)
        {
            QVector3D startPoint = PointOnRay(start);
            QVector3D endPoint = PointOnRay(finish);

            if (CheckIfUnderGround(startPoint) == false &&
                CheckIfUnderGround(endPoint) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        QVector3D MousePicker::PointOnRay(float distance)
        {
            QVector3D cameraPosition = m_camera->GetPosition();
            
            QVector3D scaledRay = QVector3D(
                m_currentRay.x() * distance,
                m_currentRay.y() * distance,
                m_currentRay.z() * distance
            );

            return cameraPosition + scaledRay;
        }

        bool MousePicker::CheckIfUnderGround(QVector3D testPoint)
        {
            // we need to be able to get the height @ the terrain(testPoint(x,z))
            // so far we can only test on a flat terrain @ y = 0
            if (testPoint.y() < m_terrain->GetPosition().y())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        QVector3D MousePicker::BinarySearch(
            int count,
            float start,
            float finish)
        {
            float half = start + ((finish - start) / 2.0f); // records the current distance
            if (count >= RECURSION_COUNT)
            {
                QVector3D lastPoint = PointOnRay(half);
                if (lastPoint.x() >= m_terrain->GetPosition().x() + 50.0f || 
                    lastPoint.z() >= m_terrain->GetPosition().z() + 50.0f)
                {
                    return QVector3D(25.0f, 0.0f, 25.0f);
                }
                else
                {
                    return lastPoint;
                }
            }

            if (IntersectionInRange(start, half))
                return BinarySearch(count + 1, start, half);
            else
                return BinarySearch(count + 1, half, finish);

            return QVector3D();
        }
    }
}
