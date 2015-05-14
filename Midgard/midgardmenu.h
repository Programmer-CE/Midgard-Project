#ifndef MIDGARDMENU_H
#define MIDGARDMENU_H

#include <QMainWindow>

namespace Ui {
class MidgardMenu;
}

class MidgardMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MidgardMenu(QWidget *parent = 0);
    ~MidgardMenu();

private:
    Ui::MidgardMenu *ui;
};

#endif // MIDGARDMENU_H
