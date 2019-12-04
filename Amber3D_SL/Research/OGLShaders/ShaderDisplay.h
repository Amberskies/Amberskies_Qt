#pragma once

#include <QMainWindow>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class ShaderDisplay; }
QT_END_NAMESPACE

class ShaderDisplay : public QMainWindow
{
    Q_OBJECT

public:
    ShaderDisplay(QWidget *parent = nullptr);
    ~ShaderDisplay();

private slots:
    void on_pushButton_clicked();
    void timerUpdate();

private:
    Ui::ShaderDisplay *ui;
    QTimer *m_timer;
    const double ELAPSED_TIME = 2.0;
    double m_result;
};
