
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2019 Nov 20th
 *
 *      Amber 3D - Qt C++ Version Research 0.1
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

#include <QMainWindow>
#include "Chat.h"
//#include "ChatBox.h"

//#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class AmberLauncher; }
QT_END_NAMESPACE

class AmberLauncher : public QMainWindow
{
    Q_OBJECT

public:
    AmberLauncher(QWidget *parent = nullptr);
    ~AmberLauncher();

public slots:


private slots:
    void on_Btn_Exit_clicked();
    void on_Btn_Chat_clicked();
    void on_Btn_SendMessage_clicked();


private:
    Ui::AmberLauncher *ui;
    Chat *m_chat;
    bool isChatRunning;
    //QProcess m_process;
};
