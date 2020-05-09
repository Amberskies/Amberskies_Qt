
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
#pragma once

#define LOOP_DELAY 10

#include <QMainWindow>
#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class WorldWindow; }
QT_END_NAMESPACE

class WorldWindow : public QMainWindow
{
    Q_OBJECT

    QTimer* m_loop;

public:
    WorldWindow(QWidget *parent = nullptr);
    ~WorldWindow();

protected:
    // inherited from QWindow.
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

public slots:
    void Loop();

private:
    Ui::WorldWindow *ui;
};
