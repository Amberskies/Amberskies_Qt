#include "ChatBox.h"

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
