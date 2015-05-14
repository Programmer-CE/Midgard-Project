#ifndef MAPMAKER_H
#define MAPMAKER_H

#include <QMainWindow>
#include <QDialog>
#include "terrainpainter.h"
namespace Ui {
class MapMaker;
}

class MapMaker : public QMainWindow
{
    Q_OBJECT
    bool _helpOpen;
    QDialog _dialog;
    bool tilesetActive;//false tierra, true bosque
    bool mouseAction;// false remove, true agregar
public:
    explicit MapMaker(QWidget *parent = 0);
    bool getMouseAction();
    bool getTileSetActive();
    TerrainPainter *getTerrainPainter();
    ~MapMaker();

private slots:
    void on_actionManual_de_uso_triggered();
protected:
    void closeEvent(QCloseEvent *);
public slots:
    void closedHelpDialog();
    void setActiveTileSet();
    void changeMouseAction();
    void saveData();
private:
    Ui::MapMaker *ui;
};

#endif // MAPMAKER_H
