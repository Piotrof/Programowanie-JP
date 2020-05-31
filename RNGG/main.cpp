#include "rng.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RNG w;
    w.show();
    return a.exec();
}
