#ifndef TERRAINPAINTER_H
#define TERRAINPAINTER_H

#include <QWidget>
#include "updater.h"
class MapMaker;
class TerrainPainter : public QWidget
{
    Q_OBJECT
    MapMaker *_mapMaker;
    Updater *_updater;
    QPixmap forest,terrain;
    bool terrainMatrix[64][64];
    bool pressedB;
public:
    explicit TerrainPainter(QWidget *parent = 0);
    void setMapMaker(MapMaker *pMapMaker);
    Updater *updater() const;
    void setUpdater(Updater *updater);
    void unactivateUpdater();
    void saveMap(QString name);
signals:

public slots:
    void paintMap();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

};

#endif // TERRAINPAINTER_H
