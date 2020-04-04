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

