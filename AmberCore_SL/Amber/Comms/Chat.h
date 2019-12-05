
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
 * ---------------------------------------------------*/#pragma once

#include <QObject>
#include <QProcess>
#include "ChatBox.h"

namespace Amber
{
    namespace Comms
    {
        enum MessageType
        {
            NORMAL = 0,
            PUBLIC,
            PRIVATE,
            ADMIN,
            SYSTEM,
            ERROR
        };

        class Chat : public QProcess
        {
            Q_OBJECT

        public:
            explicit Chat(ChatBox *chatBox, QObject *parent = nullptr);

            void initChat();
            bool isChatRunning();
            bool hasErrorOccured();
            void shutdownChat();
            void dataOut(QString messageOut);

        signals:


        public slots:
            void chatRunning();
            void dataIn();
            void errorDetected(ProcessError error);

        protected:
            //Reimplemented Protected Functions
            //qint64	readData(char *data, qint64 maxlen) override;
            //qint64	writeData(const char *data, qint64 len) override;


        private:
            ChatBox *m_chatBox;
            int m_error;
        };
    }
}
