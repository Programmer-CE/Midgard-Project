#include "midgardmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MidgardMenu w;
    w.show();

    return a.exec();
}
