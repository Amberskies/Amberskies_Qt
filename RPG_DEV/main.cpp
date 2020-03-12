#include "TestWindow3D.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestWindow3D w;
    w.show();
    return a.exec();
}
