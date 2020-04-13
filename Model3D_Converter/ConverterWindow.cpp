
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Apr 2nd
 *
 *      Amber3D - Qt C++
 *
 * Contact email  : amberskies@virginmail.com
 * Website        : www.amberskies.org.uk
 * Twitch         : FrazorBladezSharp
 * Youtube        : Amberskies
 * Github         : https://github.com/Amberskies
 *
 * All code is free to use as you please
 * Please be aware of the Open Source Licence
 * given by Qt    : doc.qt.io/qt-5/opensourcelicence.html
 *
 * ---------------------------------------------------*/
#include "ConverterWindow.h"
#include "ui_ConverterWindow.h"

ConverterWindow::ConverterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ConverterWindow)
{
    ui->setupUi(this);
}

ConverterWindow::~ConverterWindow()
{
    delete ui;
}

