
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
#include "Game.h"

Game::Game(Amber3D::OpenGL::Window3D* window, QObject *parent)
    : QObject(parent)
    , m_window(window)
    , m_loop(new QTimer(this))
{
   // Empty
}

Game::~Game()
{
    delete m_loop;
}

void Game::Start()
{
     //set the shaders we would like to use.
     m_window->SetShaders(
        "BuilderColor",
        "BuilderTexture"
    );

     m_window->SetCameraTranslation(40.0f, 1.0f, 40.0f);

    m_loop->setTimerType(Qt::PreciseTimer);
    connect(m_loop, SIGNAL(timeout()), this, SLOT(Loop()));

    m_loop->start(LOOP_DELAY);
}

/////////////////// Public Slots ////////////////////////

void Game::Loop()
{
    m_loop->stop();

    // Update
    m_window->UpdateWindow3D();

    m_loop->start(LOOP_DELAY);

}
