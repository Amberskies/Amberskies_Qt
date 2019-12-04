#pragma once

#include <QWidget>
#include <QTextEdit>
#include <QColor>

class ChatBox : public QTextEdit
{
    Q_OBJECT
public:
    explicit ChatBox(QWidget *parent = nullptr);
    void addMessage(int type, const QString &message);

signals:

public slots:
};

