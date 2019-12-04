#include "ShaderDisplay.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShaderDisplay w;
    w.show();
    return a.exec();
}
