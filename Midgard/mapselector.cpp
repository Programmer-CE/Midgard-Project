#include "mapselector.h"
#include "ui_mapselector.h"
#include "qdebug.h"
#include "iostream"
#include "logic/emulationsmanager.h"
QString MapSelector::getMapPath() const
{
    return mapPath;
}

void MapSelector::setMapPath(const QString &value)
{
    mapPath = value;
}

QString MapSelector::getGeneticConfigurationPath() const
{
    return geneticConfigurationPath;
}

void MapSelector::setGeneticConfigurationPath(const QString &value)
{
    geneticConfigurationPath = value;
}

QString MapSelector::getIdEmulation() const
{
    return idEmulation;
}

void MapSelector::setIdEmulation(const QString &value)
{
    idEmulation = value;
}

QString MapSelector::getMapName() const
{
    return mapName;
}

void MapSelector::setMapName(const QString &value)
{
    mapName = value;
}

QString MapSelector::getConfigName() const
{
    return configName;
}

void MapSelector::setConfigName(const QString &value)
{
    configName = value;
}

int MapSelector::portConector() const
{
    return _portConector;
}

void MapSelector::setPortConector(int portConector)
{
    _portConector = portConector;
}
MapSelector::MapSelector(QWidget *parent) :
    QDialog(parent), fileDialog(this),
    ui(new Ui::MapSelector),_warningMessage(this)
{
    ui->setupUi(this);
}

MapSelector::~MapSelector()
{
    if (ui!=0)delete ui;
}

void MapSelector::accept()
{
    if (ui->mapconfig->text().compare("")!=0 && ui->geneticconfigure->text().compare("")!=0){
        QDialog::accept();
        EmulationsManager *emulationMan = EmulationsManager::getInstance();
        IDEmulatorMessage idemu= emulationMan->createEmulation(ui->mapconfig->text(),ui->geneticconfigure->text(),_portConector);
        if(idemu.getMessage().compare(emulationMan->SUCESS) == 0){
            mapPath = ui->mapconfig->text();
            geneticConfigurationPath = ui->geneticconfigure->text();
            idEmulation = idemu.getId();
            mapName = idemu.getNameMap();
            configName = idemu.getNameConfig();
        }
        else{
            QDialog::reject();
        }
        ui->mapconfig->setText("");
        ui->geneticconfigure->setText("");
        _warningMessage.about(this,"mensage", idemu.getMessage());
    }
    else{
        _warningMessage.about(this,"Error: direcciones invalidas", "Por favor inserte las direcciones a usar, estan incompletas");
    }
}

void MapSelector::reject()
{
    mapPath = "";
    geneticConfigurationPath = "";
    ui->geneticconfigure->setText("");
    ui->mapconfig->setText("");
    QDialog::reject();
}

void MapSelector::cargarMapa()
{
    ui->mapconfig->setText(fileDialog.getOpenFileName(this,"","","XML (*.xml)"));
}

void MapSelector::cargarConfiguracion()
{

    ui->geneticconfigure->setText(fileDialog.getOpenFileName(this,"","","XML (*.xml)"));
}
