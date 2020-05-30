
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
#include <QGuiApplication>

#include <Amber3D/OpenGL/Window3D.h>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Amber3D::OpenGL::Window3D* view =
        new Amber3D::OpenGL::Window3D();



    view->show();

    return app.exec();
}
