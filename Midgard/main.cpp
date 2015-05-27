#include "midgardmenu.h"
#include <QApplication>
#include <iostream>
#include "logic/customgenetics/villager.h"


using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MidgardMenu w;
    w.show();
    cout << sizeof (Villager) << endl;
    cout << sizeof (Villager)*4*5*60 << endl;
    return a.exec();
}
