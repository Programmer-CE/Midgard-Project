#include "midgardmenu.h"
#include <QApplication>
#include <iostream>
#include "logic/customgenetics/villager.h"
#include "logic/random.h"

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MidgardMenu w;
    Random random;
    w.show();
    return a.exec();
}
