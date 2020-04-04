#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ConverterWindow; }
QT_END_NAMESPACE

class ConverterWindow : public QMainWindow
{
    Q_OBJECT

public:
    ConverterWindow(QWidget *parent = nullptr);
    ~ConverterWindow();

private:
    Ui::ConverterWindow *ui;
};
