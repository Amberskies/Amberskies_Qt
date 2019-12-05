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
#include <QTcpSocket>

#include <QDebug>


namespace NetDev
{
    namespace TCP
    {
        class TcpMessenger : public QObject
        {
            Q_OBJECT

        public:
            explicit TcpMessenger(QObject *parent = nullptr) Q_DECL_NOTHROW;

            void setSocket(QTcpSocket *m_socket);

        signals:


        public slots:
            virtual void connected();
            virtual void disconnected();
            virtual void readyRead();
            virtual void bytesWritten(qint64 bytes);
            virtual void stateChanged(QAbstractSocket::SocketState socketState);
            virtual void error(QAbstractSocket::SocketError socketError);

        protected:
            QTcpSocket *m_socket;

            QTcpSocket* getSocket();

        };
    }
}
