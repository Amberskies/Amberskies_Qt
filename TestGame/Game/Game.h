
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 May 11th
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

#define LOOP_DELAY 10

#include <QObject>
#include <QTimer>

#include <Amber3D/OpenGL/Window3D.h>
#include <Amber/ECS/Ecs.h>

class Game : public QObject
{
    Q_OBJECT

    Amber3D::OpenGL::Window3D* m_window;
    QTimer* m_loop;

public:
    Game(Amber3D::OpenGL::Window3D* window, QObject *parent = nullptr);
     ~Game();

     void Start();

signals:

public slots:
    void Loop();

};

