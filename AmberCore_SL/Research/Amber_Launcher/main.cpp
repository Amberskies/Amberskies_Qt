
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2019 Nov 20th
 *
 *      Amber 3D - Qt C++ Version Research 0.1
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


#include <QApplication>

#include "AmberDev/AmberLauncher.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AmberLauncher launcher;
    launcher.show();

    return a.exec();
}
