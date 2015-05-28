#include "midgardmenu.h"
#include "ui_midgardmenu.h"
#include <iostream>
#include <QMessageBox>
#include <QtNetwork/QHostAddress>
#include "logic/emulationsmanager.h"

MidgardMenu::MidgardMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MidgardMenu)//,mapSelector(this)
{
    randomGenerator = new Updater();
    QRegExp rx = QRegExp( "[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}" );
    ipVerificator = new QRegExpValidator(rx,0);
    ui->setupUi(this);
    randomGenerator->start();
    //ui->servers->horizontalHeader()->;
}

MidgardMenu::~MidgardMenu()
{
    randomGenerator->terminate();
    delete ui;
    ui = 0;
    delete ipVerificator;
}

void MidgardMenu::on_insertar_clicked()
{
    QMessageBox box(this);
        mapSelector.setPortConector(ui->portget->value());
        mapSelector.exec();
        if (mapSelector.result() == QDialog::Accepted){
            ui->servers->insertRow(0);
            QString toAppear = ui->portget->text().append(" : config: ").append(mapSelector.getConfigName()).append(" : map name: ").append(mapSelector.getMapName());
            QTableWidgetItem *element = new QTableWidgetItem(QVariant(ui->portget->value()).toString());
            element->setWhatsThis(mapSelector.getIdEmulation());
            ui->servers->setItem(0,0,element);
            element = new QTableWidgetItem(mapSelector.getConfigName());
            element->setWhatsThis(mapSelector.getIdEmulation());
            ui->servers->setItem(0,1,element);
            element = new QTableWidgetItem(mapSelector.getMapName());
            element->setWhatsThis(mapSelector.getIdEmulation());
            ui->servers->setItem(0,2,element);
        }
        mapSelector.close();
}

void MidgardMenu::on_borrar_clicked()
{
    if (ui->servers->selectedItems().size() > 0){
        EmulationsManager::getInstance()->removeEmulation(ui->servers->selectedItems().at(0)->whatsThis());
        int fila = ui->servers->selectedItems().at(0)->row();
        for(int x = 0; x < 3;x++){
            delete ui->servers->item(fila,x);
        }
        ui->servers->removeRow(fila);
    }
}

void MidgardMenu::on_ver_clicked()
{
    if (ui->servers->selectedItems().size() > 0){
        EmulationsManager::getInstance()->runEmulation(ui->servers->selectedItems().at(0)->whatsThis());
        int fila = ui->servers->selectedItems().at(0)->row();
    }
}

void MidgardMenu::on_playOrPause_clicked()
{
    if (ui->servers->selectedItems().size() > 0){
        EmulationsManager::getInstance()->changeState(ui->servers->selectedItems().at(0)->whatsThis());
    }
}
