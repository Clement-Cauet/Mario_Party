#include "Mario_Party.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mario_Party w;
    w.show();
    return a.exec();
}
