#include "terrainpainter.h"
#include "qpainter.h"
#include <QMouseEvent>
#include <iostream>
#include "mapmaker.h"
#include <QCloseEvent>
#include <QDragMoveEvent>
#include <QtXml/QtXml>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

Updater *TerrainPainter::updater() const
{
    return _updater;
}

void TerrainPainter::setUpdater(Updater *updater)
{
    _updater = updater;
}

void TerrainPainter::unactivateUpdater()
{
    _updater->stop();
    while(_updater->isRunning())continue;
    delete _updater;
    _updater = 0;
}

void TerrainPainter::saveMap(QString name)
{
    QDomDocument qdd;
    QDomElement root = qdd.createElement("map");
    qdd.appendChild(root);
    QString s;
    QVariant qv;
    QDomElement node = qdd.createElement("row");
    for (int x = 0; x < 64; x++){
        node = qdd.createElement("row");
        for(int y = 0; y < 64; y++){
            s.append(terrainMatrix[y][x]?"1":"0");
        }
        node.setAttribute("xrow",s);
        root.appendChild(node);
        s = "";
    }


    QFile file(name);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){

    }
    else{
        QTextStream qts(&file);
        qts << qdd.toString();
        file.close();
    }


}

void TerrainPainter::paintMap()
{
    repaint();
}
TerrainPainter::TerrainPainter(QWidget *parent) :
    QWidget(parent), terrain(":/images/t.jpg"), forest(":/images/v.jpg")
{
    _mapMaker = 0;
    pressedB = false;
}

void TerrainPainter::setMapMaker(MapMaker *pMapMaker)
{
    _mapMaker = pMapMaker;
}

void TerrainPainter::paintEvent(QPaintEvent *)
{
    QPainter p;
    int current = 0;
    p.begin(this);
    p.fillRect(rect(),Qt::black);
    for (int x = 0; x < 64; x++){
        for(int y = 0; y < 64; y++){
            current = terrainMatrix[x][y];
            if (!current){
                p.drawPixmap(x*64,y*64,64,64,terrain);
            }
            else if (current){
                p.drawPixmap(x*64,y*64,64,64,forest);
            }
        }
    }
    p.end();
}

void TerrainPainter::mousePressEvent(QMouseEvent *m)
{
    pressedB = true;
    if(_mapMaker->getMouseAction()){
        if (!_mapMaker->getTileSetActive()){
            terrainMatrix[m->x()/64][m->y()/64] = false;
        }
        else{
            terrainMatrix[m->x()/64][m->y()/64] = true;
        }
    }
    else{
        terrainMatrix[m->x()/64][m->y()/64] = false;
    }
}

void TerrainPainter::mouseReleaseEvent(QMouseEvent *)
{
    pressedB = false;
}

void TerrainPainter::mouseMoveEvent(QMouseEvent *e)
{
    if (pressedB && rect().contains(e->pos())){
        if(_mapMaker->getMouseAction()){
            if (!_mapMaker->getTileSetActive()){
                terrainMatrix[e->pos().x()/64][e->pos().y()/64] = false;
            }
            else{
                terrainMatrix[e->pos().x()/64][e->pos().y()/64] = true;
            }
        }
        else{
            terrainMatrix[e->pos().x()/64][e->pos().y()/64] = false;
        }
    }
}
