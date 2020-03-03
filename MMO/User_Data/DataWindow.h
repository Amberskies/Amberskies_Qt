#pragma once

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

private:
    Ui::DataWindow *ui;
};
