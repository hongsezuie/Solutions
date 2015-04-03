#include <QCoreApplication>
#include <solution.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Solution MySolution;

    std::cout<<MySolution.convertToTitle(51)<<std::endl;

    return a.exec();
}
