
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2019 Nov 14th
 *
 *      Amber - Qt C++
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
#include "Chat.h"

namespace Amber
{
    namespace Comms
    {
        Chat::Chat(ChatBox *chatBox, QObject *parent) : QProcess(parent),
            m_chatBox(chatBox),
            m_error(-1)
        {
            // Empty

            // signals emitted from process
            // started()        -> chatRunning()
            // readyRead()      -> dataIn()
            // errorOccurred()  -> errorDetected()
            // finished()       -> chatFinished() needs more research

            // do we need a shutdown ?
        }

        void Chat::initChat()
        {
            m_chatBox->addMessage(SYSTEM,"Opening the Chat Server ...");

            connect(this, &QProcess::started,
                    this, &Chat::chatRunning);

            connect(this, &QProcess::readyRead,
                    this, &Chat::dataIn);

            connect(this, &QProcess::errorOccurred,
                    this, &Chat::errorDetected);

            this->start("Testing");

            // this is a hack to stop buttons working after the external
            // program is closed by itself.
            // no messages appear for this type of closure.
            // this needs more research

            m_error = 0;
        }

        bool Chat::isChatRunning()
        {
            if (this->state() == QProcess::Running) return true;
            else return false;
        }

        bool Chat::hasErrorOccured()
        {
            if (m_error >= 0) return true;
            return false;
        }

        void Chat::shutdownChat()
        {
            m_chatBox->addMessage(SYSTEM,"The Chat Server has shutdowm");
        }

        void Chat::dataOut(QString messageOut)
        {
            if (!isChatRunning()) return;

            m_chatBox->addMessage(ADMIN, messageOut);
            // send message to Chat Server
        }

        void Chat::chatRunning()
        {
            m_chatBox->addMessage(SYSTEM, "The Chat Server is running.");
        }

        /* ***** Public Slots ***** */

        void Chat::dataIn()
        {
            // receive data from process and send to m_chatBox
        }

        void Chat::errorDetected(QProcess::ProcessError error)
        {
            m_error = error;
            if (error == 0) m_chatBox->addMessage(ERROR, "Chat Server failed to start.");
            else if (error == 1) m_chatBox->addMessage(ERROR,"Chat Server Crashed. !!!");
            else if (error == 2) m_chatBox->addMessage(ERROR,"Chat Server Timedout. !!");
            else if (error == 3) m_chatBox->addMessage(ERROR,"Error while transmitting message. !");
            else if (error == 4) m_chatBox->addMessage(ERROR,"Error while receiving messages. !");
            else if (error == 5) m_chatBox->addMessage(ERROR,"Unknown Error Occured <YiKeS!>");
        }


        /* ***** Reimplemented Protected Functions ***** */

        // are these needed or can we just use the underlying functionality.

        //qint64 Chat::readData(char *data, qint64 maxlen)
        //{
        //    return 2; // number of bytes read
        //}

        //qint64 Chat::writeData(const char *data, qint64 len)
        //{
        //    return 3; // number of bytes written
        //}
    }
}
