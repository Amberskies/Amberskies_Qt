#include "ConverterWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConverterWindow w;
    w.show();
    return a.exec();
}
