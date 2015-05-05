#include "midgardmenu.h"
#include <QApplication>
#include <iostream>
#include "ordinateList/doublelist.h"
#include "logic/customgenetics/villagerfabric.h"
#include "logic/customgenetics/midgardarwin.h"
#include "logic/customgenetics/villagercrosser.h"
#include "logic/customgenetics/villagerfinalstate.h"
#include "genetics/comparer.h"
#include "genetics/darwin.h"
using namespace std;
void print(DoubleList<Comparer<Individuo> > *);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MidgardMenu w;
    w.show();
    DoubleList<Comparer<Individuo> > *_lista = new DoubleList<Comparer<Individuo> >();
    Poblation * po = new Poblation();
    po->setDataList(_lista);
    VillagerFabric *vf = new VillagerFabric();
    VillagerCrosser *vc= new VillagerCrosser();
    VillagerFinalState *vfs = new VillagerFinalState();
    vc->setIndividuousFabric(vf);
    for (int x =0; x < 10; x++){
        _lista->add(Comparer<Individuo>(vf->create(0)));
    }
    //print(_lista);
    MidgarDarwin *x = new MidgarDarwin(vc,vfs,po,10);
    x->evolveStep();
    print(_lista);
    x->evolve();
    print(_lista);
    return a.exec();
}
void print(DoubleList<Comparer<Individuo> > *lista)
{
    IIterator<Comparer<Individuo> > *_iter = lista->getIterator();
    Villager *currentdata =0;
    float hight = 0;
    int index =0;
    cout << "##### lenght: "<<lista->getLenght()<<"##################################################" << endl;
    for (int x =0; x < lista->getLenght(); x++){
        currentdata = (Villager*)lista->get(x).getData();
        if (currentdata->fitness() > hight){
            hight = currentdata->fitness();
            index = x;
        }
    }
    currentdata = (Villager*)lista->get(index).getData();
    cout << "--------------------------------------------------------------------------" << endl
         << "ind: " << index;
    if (currentdata->isSelected())cout << " s ";
    else cout << " n ";
    cout << "fit " << currentdata->fitness() << " e-m: " << currentdata->ageToDeath() <<
            " atk: " << currentdata->attack()
         << " def: " << currentdata->defense() << " vel: " << currentdata->velocity()
         << " v-m: " <<currentdata->maximunLife()<<
            " blot: " << currentdata->blot() <<
         " rns: "<< currentdata->runes() << " sprtn: " << currentdata->superstition()
          << " int: " << currentdata->intelligence() <<
            " mag:"<< currentdata->magic() << endl
            << "------------------------------------------------------------------------------" << endl;
    cout << "##############################################################" << endl;
    delete _iter;
}
