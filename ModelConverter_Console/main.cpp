//#include <QCoreApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    std::cout << "Num Arguments = " << argc << std::endl;
    std::cout << "Argument 1 = " << argv[0] << std::endl;

    return 0;//a.exec();
}
