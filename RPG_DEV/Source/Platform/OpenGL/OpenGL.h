
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 12th
 *
 *      Amber 3D - Qt C++ Version Test 0.2
 *
 * Contact email  : amberskies@virginmail.com
 * Website        : www.amberskies.org.uk
 * Twitch         : FrazorBladezSharp
 * Youtube        : Amberskies
 *
 * All code is free to use as you please
 * Please be aware of the Open Source Licence
 * given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
 *
 * ---------------------------------------------------*/
#pragma once
#include "Source/Common.h"
#include <QObject>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLContext>
#include <QSurfaceFormat>
#include <QMatrix4x4>

#include "Source/Core/FunctionKey3.h"


class OpenGL : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
        Q_OBJECT

        int m_function;
        QSurfaceFormat m_format;
        QOpenGLContext m_context;

        FunctionKey3 *m_F3;

        QMatrix4x4 m_projection;

    public:
        explicit OpenGL(QWidget *parent = nullptr);
        ~OpenGL() override;

        // getters

        // setters
        void setFunctionKey(int x) { m_function = x; }
    signals:

    public slots:

    protected:
        void initializeGL() override;
        void paintGL() override;
        void resizeGL(int width, int height) override;

    private:
        

};
