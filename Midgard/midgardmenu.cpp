#include "midgardmenu.h"
#include "ui_midgardmenu.h"
#include <iostream>
#include <QMessageBox>
#include <QtNetwork/QHostAddress>


MidgardMenu::MidgardMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MidgardMenu)//,mapSelector(this)
{
    QRegExp rx = QRegExp( "[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}" );
    ipVerificator = new QRegExpValidator(rx,0);
    ui->setupUi(this);
    //ui->ipget->setInputMask("000.000.000.000");
    ui->ipget->setValidator(ipVerificator);
}

MidgardMenu::~MidgardMenu()
{
    delete ui;
    ui = 0;
    delete ipVerificator;
}

void MidgardMenu::on_insertar_clicked()
{
    QMessageBox box(this);
    QHostAddress address;
    //delete box;
    if (address.setAddress(ui->ipget->text())){
        mapSelector.exec();
        if (mapSelector.result() == QDialog::Accepted){

            ui->servers->addItem(ui->ipget->text().append(QString(" : ").append(ui->portget->text())));
        }
        mapSelector.close();
    }
    else{
        box.about(this, "Error Ip Invalido", "El ip ingresado es invalido");
    }
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
