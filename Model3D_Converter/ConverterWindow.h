
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
#pragma once

#include <QMainWindow>
#include <QTimer>
#include <Amber3D/Models/RawModel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ConverterWindow; }
QT_END_NAMESPACE

class ConverterWindow : public QMainWindow
{
    Q_OBJECT

    Ui::ConverterWindow *ui;
    Amber3D::Models::RawModel* m_model;
    QTimer *m_mainLoopTimer;
    bool m_model_is_loaded;

public:
    ConverterWindow(QWidget *parent = nullptr);
    ~ConverterWindow();

    void StartMainLoop();

private slots:
    void on_Load_OBJ_clicked();
    void on_ExitButton_clicked();
    void MainLoop();

private:
    void Load3DModel();


};
