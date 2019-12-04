#pragma once

#include <QObject>
#include <QProcess>
#include "ChatBox.h"

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
//    qint64	readData(char *data, qint64 maxlen) override;
//    qint64	writeData(const char *data, qint64 len) override;


private:
    ChatBox *m_chatBox;
    int m_error;
};

