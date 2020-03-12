#include "TestWindow3D.h"
#include "ui_TestWindow3D.h"

TestWindow3D::TestWindow3D(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestWindow3D)
{
    ui->setupUi(this);
}

TestWindow3D::~TestWindow3D()
{
    delete ui;
}


void TestWindow3D::on_MenuButton_clicked()
{

}

void TestWindow3D::on_F1pushButton_clicked()
{

}

void TestWindow3D::on_F2pushButton_clicked()
{

}

void TestWindow3D::on_F3pushButton_clicked()
{

}

void TestWindow3D::on_ExitButton_clicked()
{
    this->close();
}
