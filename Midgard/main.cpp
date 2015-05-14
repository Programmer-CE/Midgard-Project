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
    /*
    DoubleList<Comparer<Individuo> > *_lista = new DoubleList<Comparer<Individuo> >();
    Poblation * po = new Poblation();
    po->setDataList(_lista);
    VillagerFabric *vf = new VillagerFabric();
    VillagerCrosser *vc= new VillagerCrosser();
    VillagerFinalState *vfs = new VillagerFinalState();
    Villager * theVillager = 0;
    vc->setIndividuousFabric(vf);
    for (int x =0; x < 20; x++){
        theVillager = vf->create(0);
        theVillager->setGender(x%2 == 0);
        _lista->add(Comparer<Individuo>(theVillager));
    }
    print(_lista);
    MidgarDarwin *x = new MidgarDarwin(vc,vfs,po,200);
    x->evolve();
    /**
    for (int m =0; m < 20; m++){
        x->evolveStep();
        print(po->getDataList());
    }
    print(po->getDataList());
    */
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
        //currentdata = (Villager*)lista->get(index).getData();
        cout << "--------------------------------------------------------------------------" << endl;
             //<< "ind: " << x;
        //if (currentdata->isSelected())cout << " s ";
        //else cout << " n ";
        //cout  << " e-m: " << currentdata->ageToDeath() <<
        cout << " atk: " << currentdata->attack() << " def: " << currentdata->defense()
             <<" blot: " << currentdata->blot() << " fit " << currentdata->fitness()
            << " e-m: " << currentdata->ageToDeath() <<" vel: " << currentdata->velocity()
            << " v-m: " <<currentdata->maximunLife()<<

            " rns: "<< currentdata->runes() << " sprtn: " << currentdata->superstition()
             << " int: " << currentdata->intelligence() <<
               " mag:"<< currentdata->magic()
             << endl <<
                "------------------------------------------------------------------------------" << endl;
        cout << "##############################################################" << endl;
        /*
        if (currentdata->fitness() > hight){
            hight = currentdata->fitness();
            index = x;
        }
        */
    }
    delete _iter;
}
