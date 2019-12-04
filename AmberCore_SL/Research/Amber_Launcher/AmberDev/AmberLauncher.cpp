
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


#include "AmberLauncher.h"
#include "ui_AmberLauncher.h"

AmberLauncher::AmberLauncher(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::AmberLauncher),
    isChatRunning(false)
{
    ui->setupUi(this);

    m_chat = new Chat(ui->Chat_Box, this);
}

AmberLauncher::~AmberLauncher()
{
    delete ui;
}

/* ***** Private Slots ***** */

void AmberLauncher::on_Btn_Exit_clicked()
{
    m_chat->shutdownChat();
    this->close();
}


void AmberLauncher::on_Btn_Chat_clicked()
{
    if (m_chat->isChatRunning()) return;
    if (m_chat->hasErrorOccured()) return;
    m_chat->initChat();

}

void AmberLauncher::on_Btn_SendMessage_clicked()
{
    QString messageOut = ui->MessageOut->text();
    m_chat->dataOut(messageOut);
}

