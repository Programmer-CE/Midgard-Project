#ifndef MIDGARDMENU_H
#define MIDGARDMENU_H

#include <QMainWindow>
#include <QRegExpValidator>
#include "mapselector.h"
namespace Ui {
class MidgardMenu;
}

class MidgardMenu : public QMainWindow
{
    Q_OBJECT
    QRegExpValidator *ipVerificator;
    MapSelector mapSelector;
public:
    explicit MidgardMenu(QWidget *parent = 0);
    ~MidgardMenu();

private slots:
    void on_insertar_clicked();

    void on_borrar_clicked();

    void on_ver_clicked();

private:
    Ui::MidgardMenu *ui;
};

#endif // MIDGARDMENU_H
