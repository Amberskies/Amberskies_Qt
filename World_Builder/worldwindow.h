#ifndef WORLDWINDOW_H
#define WORLDWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WorldWindow; }
QT_END_NAMESPACE

class WorldWindow : public QMainWindow
{
    Q_OBJECT

public:
    WorldWindow(QWidget *parent = nullptr);
    ~WorldWindow();

private:
    Ui::WorldWindow *ui;
};
#endif // WORLDWINDOW_H
