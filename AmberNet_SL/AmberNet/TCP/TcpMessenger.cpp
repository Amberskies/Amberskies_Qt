
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


#include "TcpMessenger.h"

namespace NetDev
{
    namespace TCP
    {
        TcpMessenger::TcpMessenger(QObject *parent) noexcept
            :
              QObject(parent),
              m_socket(nullptr)
        {
            // Empty
            qDebug() << this << "Constructed";
        }

        void TcpMessenger::setSocket(QTcpSocket *socket)
        {
            m_socket = socket;

            connect(m_socket, &QTcpSocket::connected,
                    this, &TcpMessenger::connected);

            connect(m_socket, &QTcpSocket::disconnected,
                    this, &TcpMessenger::disconnected);

            connect(m_socket, &QTcpSocket::readyRead,
                    this, &TcpMessenger::readyRead);

            connect(m_socket, &QTcpSocket::bytesWritten,
                    this, &TcpMessenger::bytesWritten);

            connect(m_socket, &QTcpSocket::stateChanged,
                    this, &TcpMessenger::stateChanged);

            connect(m_socket, static_cast<void(QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error),
                    this, &TcpMessenger::error);
        }

        /* ***** Public Slots ***** */

        void TcpMessenger::connected()
        {
            if (!sender()) return;
            qDebug() << this << ":>> Connected " << sender();
        }

        void TcpMessenger::disconnected()
        {
            if (!sender()) return;
            qDebug() << this << ":>>> Disconnected " << sender();
        }

        void TcpMessenger::readyRead()
        {
            if (!sender()) return;
            qDebug() << this << ":> readyRead : " << getSocket();

            //QTcpSocket *socket = getSocket();
        }

        void TcpMessenger::bytesWritten(qint64 bytes)
        {
            if (!sender()) return;
            qDebug() << this << ":> bytesWritten : "
                     << getSocket()
                     << " number of bytes = " << bytes;
        }

        void TcpMessenger::stateChanged(QAbstractSocket::SocketState socketState)
        {
            if (!sender()) return;
            qDebug() << this << ":> stateChanged : "
                     << getSocket()
                     << " state = " << socketState;
        }

        void TcpMessenger::error(QAbstractSocket::SocketError socketError)
        {
            if (!sender()) return;
            qDebug() << this << ":> Error : "
                     << getSocket()
                     << " error = " << socketError;
        }

        QTcpSocket *TcpMessenger::getSocket()
        {
            if(!sender()) return nullptr;
            return static_cast<QTcpSocket*>(sender());
        }
    }
}
