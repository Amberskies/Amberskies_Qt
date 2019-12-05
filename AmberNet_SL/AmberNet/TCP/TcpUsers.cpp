
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


#include "TcpUsers.h"

namespace NetDev
{
    namespace TCP
    {
        TcpUsers::TcpUsers(QObject *parent) : QObject(parent)
        {
            // Empty
            qDebug() << this << "Constructed.";
        }

        int TcpUsers::count()
        {
            QReadWriteLock lock;
            lock.lockForRead();
            int value = m_users.count();
            lock.unlock();

            return value;
        }

        /* ***** Public Slots ***** */

        void TcpUsers::start()
        {
            qDebug() << this << "Clients / Users started on : " << QThread::currentThreadId();
        }

        void TcpUsers::quit()
        {
            if (!sender()) return;
            qDebug() << this << "Amber Server Shutdown in progress.";

            foreach(QTcpSocket *socket, m_users.keys())
            {
                qDebug() << this << "Closing Socket : " << socket;
                removeSocket(socket);
            }

            qDebug() << this << "Server will now Shutdown.";
            emit finished();
        }

        void TcpUsers::accept(qintptr handle, TcpMessenger *messenger)
        {
            qDebug() << "    <*** Accepting User ***>";
            QTcpSocket *socket = new QTcpSocket(this);

            if (!socket->setSocketDescriptor(handle))
            {
                qWarning() << this << "could not accept connection." << handle;
                messenger->deleteLater();
                return;
            }

            // connect the socket to signals and slots
            connect(socket, &QTcpSocket::disconnected,
                    this, &TcpUsers::disconnected);

            connect(socket, static_cast<void(QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error),
                    this, &TcpUsers::error);

            messenger->moveToThread(QThread::currentThread());
            messenger->setSocket(socket);     // check how this is working !
            // the function has not yet been written

            m_users.insert(socket, messenger);
            qDebug() << this << "Total Users = " << m_users.count();
            emit socket->connected();
        }

        /* ***** Protected ***** */

        void TcpUsers::removeSocket(QTcpSocket *socket)
        {
            if (!socket) return;
            if (!m_users.contains(socket)) return;

            if (socket->isOpen())
            {
                qDebug() << this << "Socket Open : attempting to close" << socket;
                socket->disconnect();
                socket->close();
            }

            qDebug() << this << "Deleting Socket" << socket;
            m_users.remove(socket);
            socket->deleteLater();

            qDebug() << this << "Client / Users count = " << m_users.count();
        }

        /* ***** Protected Slots ***** */

        void TcpUsers::disconnected()
        {
            if(!sender()) return;
            qDebug() << this << "Disconnecting Socket : " << sender();

            dropSocket();
        }

        void TcpUsers::error(QAbstractSocket::SocketError socketError)
        {
            if (!sender()) return;
            qDebug() << this << "Error in Socket : " << sender()
                     << " error = " << socketError;
            dropSocket();
        }

        /* ***** Private ***** */

        void TcpUsers::dropSocket()
        {
            QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
            if (!socket) return;
            removeSocket(socket);
        }
    }
}
