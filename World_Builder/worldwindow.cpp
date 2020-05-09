
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 May 07th
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
#include "worldwindow.h"
#include "ui_worldwindow.h"
#include "Input.h"

WorldWindow::WorldWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_loop(new QTimer(this))
    , ui(new Ui::WorldWindow)

{
    ui->setupUi(this);

    m_loop->setTimerType(Qt::PreciseTimer);
    connect(m_loop, SIGNAL(timeout()), this, SLOT(Loop()));
   
    m_loop->start(LOOP_DELAY);
}

WorldWindow::~WorldWindow()
{
    delete ui;
    delete m_loop;
}

// ***** Inherited Protected Events *****

void WorldWindow::mousePressEvent(QMouseEvent* event)
{
    Input::registerMousePress(event->button());
}

void WorldWindow::mouseReleaseEvent(QMouseEvent* event)
{
    Input::registerMouseRelease(event->button());
}

void WorldWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->isAutoRepeat())
    {
        event->ignore();
    }
    else
    {
        Input::registerKeyPress(event->key());
    }
}

void WorldWindow::keyReleaseEvent(QKeyEvent* event)
{
    if (event->isAutoRepeat())
    {
        event->ignore();
    }
    else
    {
        Input::registerKeyRelease(event->key());
    }
}

/////////////////// Public slots //////////////

void WorldWindow::Loop()
{
    m_loop->stop();

    // Update input
    Input::update();

    ui->ViewPort->update();

    m_loop->start(LOOP_DELAY);
}
