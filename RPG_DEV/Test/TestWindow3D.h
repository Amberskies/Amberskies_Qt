#pragma once
#include <Amber3D/Common.h>

#include <QObject>
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class TestWindow3D; }
QT_END_NAMESPACE

class TestWindow3D : public QMainWindow
{
    Q_OBJECT

public:
    TestWindow3D(QWidget *parent = nullptr);
    ~TestWindow3D();

private slots:
    void on_MenuButton_clicked();
    void on_F1pushButton_clicked();
    void on_F2pushButton_clicked();
    void on_F3pushButton_clicked();
    void on_ExitButton_clicked();

    void Loop();
    void FPS();
    /////////// F2 Buttons ///////////
    void on_LoadButton_clicked();
    void on_SaveButton_clicked();
    void on_RefreshButton_clicked();

private:
    Ui::TestWindow3D *ui;
    QTimer *m_loop;
    QTimer *m_FPS;
    uint m_frameCounter;
};
