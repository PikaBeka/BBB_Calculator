#include "tictac.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TicTac w;
    w.show();

    return a.exec();
}
