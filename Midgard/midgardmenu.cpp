#include "midgardmenu.h"
#include "ui_midgardmenu.h"

MidgardMenu::MidgardMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MidgardMenu)
{
    ui->setupUi(this);
}

MidgardMenu::~MidgardMenu()
{
    delete ui;
}
