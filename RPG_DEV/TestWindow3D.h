#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TestWindow3D; }
QT_END_NAMESPACE

class TestWindow3D : public QMainWindow
{
    Q_OBJECT

public:
    TestWindow3D(QWidget *parent = nullptr);
    ~TestWindow3D();

private:
    Ui::TestWindow3D *ui;
};
