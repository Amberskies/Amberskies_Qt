
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
#include "WorldBuilder.h"

WorldBuilder::WorldBuilder(Amber3D::OpenGL::Window3D* window, QObject *parent)
    : QObject(parent)
    , m_window(window)
    , m_loop(new QTimer(this))
{
   // Empty
}

WorldBuilder::~WorldBuilder()
{
    delete m_loop;
}

void WorldBuilder::Start()
{
    m_loop->setTimerType(Qt::PreciseTimer);
    connect(m_loop, SIGNAL(timeout()), this, SLOT(Loop()));

    m_loop->start(LOOP_DELAY);
}

/////////////////// Public Slots ////////////////////////

void WorldBuilder::Loop()
{
    m_loop->stop();

    // Update
    m_window->UpdateWindow3D();

    m_loop->start(LOOP_DELAY);

}
