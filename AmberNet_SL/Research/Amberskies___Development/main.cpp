
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2019 Nov 14th
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


#include <QCoreApplication>
#include <QHostAddress>
#include <QPointer>

#include <QDebug>

#include"NetDev/AmberTcpServer.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Welcome to Amberskies Development." ;

    // Test Code goes here
    QPointer<NetDev::AmberTcpServer> server = new NetDev::AmberTcpServer();
    bool serverOpen = server->startServer(QHostAddress::LocalHost, 2019);
    if (!serverOpen) return -99;

    return a.exec();
}
