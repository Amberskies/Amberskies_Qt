
#pragma once
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


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DataWindow; }
QT_END_NAMESPACE

class DataWindow : public QMainWindow
{
    Q_OBJECT

public:
    DataWindow(QWidget *parent = nullptr);
    ~DataWindow();

private slots:
    void on_SaveButton_clicked();

    void on_LoadButton_clicked();

    void on_RefreshButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::DataWindow *ui;
};
