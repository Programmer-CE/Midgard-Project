#include "midgardmenu.h"
#include "ui_midgardmenu.h"
#include <iostream>
#include <QMessageBox>

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

void MidgardMenu::on_insertar_clicked()
{
    QMessageBox box(this);
    //delete box;
    ui->servers->addItem(ui->ipget->text().append(QString(" : ").append(ui->portget->text())));
}

void MidgardMenu::on_borrar_clicked()
{
    if (ui->servers->selectedItems().size() > 0){
        delete ui->servers->selectedItems().at(0);
    }
}

void MidgardMenu::on_ver_clicked()
{

}
