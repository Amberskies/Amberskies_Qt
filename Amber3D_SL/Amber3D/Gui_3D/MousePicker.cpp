
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
        {
            // Empty
        }

        void MousePicker::update(
                int width,
                int height,
            Entities::Camera* camera,
            QMatrix4x4 projection)
        {
            m_currentRay = CalcMouseRay(
                width,
                height,
                camera,
                projection
            );

            printf(
                "Current Mouse Ray ( %f, %f, %f )\n",
                m_currentRay.x(),
                m_currentRay.y(),
                m_currentRay.z()
            );
        }

        /////////////////////// Private ////////////////////////

        QPoint MousePicker::GetNormalizedWindowCoord(
            float windowWidth,
            float windowHeight)
        {
            QPoint mouseLoc = Input::mousePosition();   // which coord did we get ? window or screen
                                                        // may have to reflect the y direction from window to opengl
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
            QVector4D projectionSpace = invertedProjection * mousePos; 
            
            return QVector4D(
                projectionSpace.x(),
                projectionSpace.y(),
                -1.0f,
                0.0f
            );
        }

        QVector3D MousePicker::ConvertToModelSpace(
            QVector4D projectionSpace,
            Entities::Camera* camera)
        {
            QMatrix4x4 view = Maths::CreateViewMatrix(camera);
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
            Entities::Camera* camera,
            QMatrix4x4 projection)
        {
            QPoint windowCoord = GetNormalizedWindowCoord(
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
                viewCoord,
                camera
            );

            return modelCoord;
        }

    }
}
