
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2019 Nov 14th
 *
 *      Amber Core - Qt C++
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
#include "ChatBox.h"

namespace Amber
{
    namespace Comms
    {
        ChatBox::ChatBox(QWidget *parent) : QTextEdit(parent)
        {

        }

        void ChatBox::addMessage(int type, const QString &message)
        {
            setTextColor(Qt::white);
            if (type == 3) setTextColor(Qt::green);
            else if (type == 4) setTextColor(Qt::yellow);
            else if (type == 5) setTextColor(Qt::red);
            append(message);
        }
    }
}
