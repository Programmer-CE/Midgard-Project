#include "mapselector.h"
#include "ui_mapselector.h"
#include "qdebug.h"
#include "iostream"
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
MapSelector::MapSelector(QWidget *parent) :
    QDialog(parent), fileDialog(this),
    ui(new Ui::MapSelector),_warningMessage(this)
{
    ui->setupUi(this);
}

MapSelector::~MapSelector()
{
    if (ui!=0)delete ui;
    else std::cout << "fine, I find you error" << std::endl;
}

void MapSelector::accept()
{
    if (ui->mapconfig->text().compare("")!=0 && ui->geneticconfigure->text().compare("")!=0){
        QDialog::accept();
        mapPath = ui->mapconfig->text();
        geneticConfigurationPath = ui->geneticconfigure->text();
        ui->geneticconfigure->setText("");
        ui->mapconfig->setText("");
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
