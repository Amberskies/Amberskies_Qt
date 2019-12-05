
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2019 Nov 14th
 *
 *      AmberNet - Qt C++
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

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>

#include <QDebug>

#include "TcpMessenger.h"
#include "TcpUsers.h"



namespace NetDev
{
    namespace TCP
    {
        class AmberTcpServer : public QTcpServer
        {
            Q_OBJECT

        public:
            explicit AmberTcpServer(QObject *parent = nullptr) Q_DECL_NOTHROW;

            virtual bool startServer(const QHostAddress &ip, quint16 port);
            void close();

        signals:
            void accepting(qintptr socketDescriptor, TcpMessenger *messenger);
            void finished();

        public slots:
            void complete();
            void newConnection();

        protected:
            QThread *m_thread;
            TcpUsers *m_users;
            // answer : check the spelling ie incoming + override +qintptr
            void incomingConnection(qintptr descriptor);
            virtual void accept(qintptr descriptor, TcpMessenger *messenger);
        };
    }
}
