
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


#include "AmberTcpServer.h"

namespace NetDev
{
    namespace TCP
    {
        AmberTcpServer::AmberTcpServer(QObject *parent) noexcept
            : QTcpServer(parent)
        {
            // Empty
            qDebug() << this << "Constructed on thread :" << QThread::currentThreadId();
        }

        bool AmberTcpServer::startServer(const QHostAddress &ip, quint16 port)
        {
            if (!this->listen(ip, port))
                return false;

            m_thread = new QThread(this);
            m_users = new TcpUsers();

            // connect signals and slots across the thread boundary

            connect(m_thread, &QThread::started,            // emitter
                    m_users, &TcpUsers::start,              // receiver
                    Qt::QueuedConnection);

            connect(this, &AmberTcpServer::accepting,       // emitter
                    m_users, &TcpUsers::accept,             // receiver
                    Qt::QueuedConnection);

            connect(this, &AmberTcpServer::finished,        // emitter
                    m_users, &TcpUsers::quit,               // receiver
                    Qt::QueuedConnection);

            connect(m_users, &TcpUsers::finished,           // emitter
                    this, &AmberTcpServer::complete,        // receiver
                    Qt::QueuedConnection);

            // connections complete. ******


            m_users->moveToThread(m_thread);
            m_thread->start();

            return true;
        }

        void AmberTcpServer::close()
        {
            qDebug() << this << "Closing the Server.";
            emit finished();
            QTcpServer::close();
        }

        /* ***** Public Slots ***** */

        void AmberTcpServer::complete()
        {
            if (!m_thread)
            {
                qWarning() << this << "Exiting complete as there was no thread.";
                return;
            }

            qDebug() << this << "Deleting Connections.";
            delete m_users;

            qDebug() << this << "Closing the Thread.";
            m_thread->quit();
            m_thread->wait();

            delete m_thread;
            qDebug() << this << "Thread deleted.";

            // for Testing
            exit(0);
        }

        void AmberTcpServer::newConnection()
        {
            qDebug() << this << "Checking New Connection."
                     << nextPendingConnection();
        }

        /* ***** Protected ***** */

        void AmberTcpServer::incomingConnection(qintptr descriptor)
        {
            qDebug() << this << "Checking New Connection." << descriptor;
            TcpMessenger *messenger = new TcpMessenger();

            // this is where we can check log in details etc ...

            accept(descriptor, messenger);
        }

        void AmberTcpServer::accept(qintptr descriptor, TcpMessenger *messenger)
        {
            qDebug() << this << "accepting the connection." << descriptor;
            messenger->moveToThread(m_thread);
            emit accepting(descriptor, messenger);
        }
    }
}
