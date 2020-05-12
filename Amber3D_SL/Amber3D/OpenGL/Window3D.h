
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
#pragma once

#include "Amber3D/Common.h"
#include <QObject>
#include <QOpenGLWindow> 
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLContext>
#include <QSurfaceFormat>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QKeyEvent>

#include "ModelWarehouse.h"


namespace Amber3D
{
    namespace OpenGL 
    {
        class Window3D : public QOpenGLWindow, protected QOpenGLFunctions_3_3_Core
        {
            Q_OBJECT

            QMatrix4x4 m_projection;
            ModelWarehouse* m_modelWarehouse;

        public:
            Window3D(QWindow* parent = nullptr);
            ~Window3D();

            void UpdateWindow3D();

        protected:
            void initializeGL() override;
            void paintGL() override;
            void resizeGL(int width, int height) override;
            void mousePressEvent(QMouseEvent* event) override;
            void mouseReleaseEvent(QMouseEvent* event) override;
            void keyPressEvent(QKeyEvent* event) override;
            void keyReleaseEvent(QKeyEvent* event) override;

        private:


        };
    }
}