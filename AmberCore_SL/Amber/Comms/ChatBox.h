
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
#pragma once

#include <QWidget>
#include <QTextEdit>
#include <QColor>

namespace Amber
{
    namespace Comms
    {
        class ChatBox : public QTextEdit
        {
            Q_OBJECT
        public:
            explicit ChatBox(QWidget *parent = nullptr);
            void addMessage(int type, const QString &message);

        signals:

        public slots:
        };
    }
}
