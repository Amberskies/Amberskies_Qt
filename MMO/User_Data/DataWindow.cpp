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

