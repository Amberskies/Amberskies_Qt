#pragma once

/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2019 Nov 14th
 *
 *      Amber 3D - Qt C++
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

#include <QObject>
#include <QThread>
#include <QReadWriteLock>
#include <QTcpSocket>
#include <QMap>

#include <QDebug>

#include "TcpMessenger.h"

namespace NetDev
{
    class TcpUsers : public QObject
    {
        Q_OBJECT
    public:
        explicit TcpUsers(QObject *parent = nullptr);
        virtual int count();

    signals:
        void quitting();
        void finished();

    public slots:
        void start();
        void quit();
        void accept(qintptr handle, TcpMessenger *messenger);

    protected:
        QMap<QTcpSocket*, TcpMessenger*> m_users;

        void removeSocket(QTcpSocket *socket);

    protected slots:
        void disconnected();
        void error(QAbstractSocket::SocketError socketError);

    private:
        void dropSocket();
    };
}
