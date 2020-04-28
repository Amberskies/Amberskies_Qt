
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


#include "Test/TestWindow3D.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication mainLoop(argc, argv);
    TestWindow3D w;
    w.showFullScreen();
    //w.show();
    return mainLoop.exec();
}
