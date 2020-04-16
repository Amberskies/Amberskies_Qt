
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Apr 2nd
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
#include <QApplication>
#include "ConverterWindow.h"

/////////////////////   MAIN ////////////////////////////////


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConverterWindow w;
    w.show();

    w.StartMainLoop();
    return a.exec();
}

/**
 * 
 * This program has the following Goals :
 *  1.  To Load any 3D Model (Initialy .obj but to be expanded).
 *  2.  To be able to check and warn if faces wind the wrong way
 *      Defaults in openGL to Counter Clockwise or CCW
 *  3.  To be able to Genrate Normals if none supplied.
 *  4.  Generate Smoothed Normals at users request.
 *  5.  On Smoothed normals offer compression of indices
 *  
 *  6.  Save Final data in a format for easy loading in the 3D library.
 *      We get to decide what that format is
 * 
 */
