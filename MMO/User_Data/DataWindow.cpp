
/* ----------------------------------------------------/
 *
 * Project created by Frazor Sharp : 2020 Mar 3rd
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


#include "DataWindow.h"
#include "ui_DataWindow.h"

DataWindow::DataWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DataWindow)
{
    ui->setupUi(this);
}

DataWindow::~DataWindow()
{
    delete ui;
}


void DataWindow::on_SaveButton_clicked()
{
    this->ui->Speadsheet->SaveData();
}



void DataWindow::on_LoadButton_clicked()
{
    this->ui->Speadsheet->LoadData();
}

void DataWindow::on_RefreshButton_clicked()
{
    this->ui->Speadsheet->RefreshData();
}

void DataWindow::on_ExitButton_clicked()
{
    this->close();
}
