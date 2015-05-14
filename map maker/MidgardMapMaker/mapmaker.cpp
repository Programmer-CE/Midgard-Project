#include "mapmaker.h"
#include "ui_mapmaker.h"
#include "iostream"
#include "terrainpainter.h"
#include <QFileSystemWatcher>
MapMaker::MapMaker(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapMaker)
{
    ui->setupUi(this);
    _helpOpen = false;
    connect(&_dialog,SIGNAL(finished(int)),this,SLOT(closedHelpDialog()));
    if (ui->addTileset->isChecked())mouseAction = true;
    else mouseAction = false;
    if(ui->tierra->isChecked()) tilesetActive = false;
    else tilesetActive = true;
    ui->widget->setMapMaker(this);

}

bool MapMaker::getMouseAction()
{
    return mouseAction;
}

bool MapMaker::getTileSetActive()
{
    return tilesetActive;
}

TerrainPainter *MapMaker::getTerrainPainter()
{
    return ui->widget;
}

MapMaker::~MapMaker()
{
    delete ui;
}

void MapMaker::on_actionManual_de_uso_triggered()
{
    if (!_helpOpen){
        _helpOpen = true;
        _dialog.show();
    }
}

void MapMaker::closeEvent(QCloseEvent *e)
{
    ui->widget->unactivateUpdater();
    QWidget::closeEvent(e);
}

void MapMaker::closedHelpDialog()
{
    _helpOpen = false;
}

void MapMaker::setActiveTileSet()
{
    if(ui->tierra->isChecked()) tilesetActive = false;
    else tilesetActive = true;
}

void MapMaker::changeMouseAction()
{
    if (ui->addTileset->isChecked())mouseAction = true;
    else mouseAction = false;

}

void MapMaker::saveData()
{
    ui->widget->saveMap("myMap.xml");
}
