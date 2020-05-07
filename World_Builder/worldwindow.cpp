#include "worldwindow.h"
#include "ui_worldwindow.h"

WorldWindow::WorldWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WorldWindow)
{
    ui->setupUi(this);
}

WorldWindow::~WorldWindow()
{
    delete ui;
}

