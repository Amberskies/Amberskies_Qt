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

