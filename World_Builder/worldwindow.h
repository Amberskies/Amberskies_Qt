
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

#include <QMainWindow>
#include <QOpenGLWindow>
#include <QOpenGLFunctions>

QT_BEGIN_NAMESPACE
namespace Ui { class WorldWindow; }
QT_END_NAMESPACE

class WorldWindow : public QMainWindow
{
    Q_OBJECT

public:
    WorldWindow(QWidget *parent = nullptr);
    ~WorldWindow();

private:
    Ui::WorldWindow *ui;
};
