#include "updater.h"
#include "ordinateList/doublelist.h"
#include "logic/customgenetics/villagerfabric.h"
#include "logic/customgenetics/villagercrosser.h"
#include "logic/customgenetics/villagerfinalstate.h"
#include "genetics/comparer.h"
#include "genetics/darwin.h"
#include <iostream>
#include "logic/customgenetics/midgardarwin.h"

MidgarDarwin *x;


bool Updater::execRand() const
{
    return _execRand;
}

void Updater::setExecRand(bool execRand)
{
    _execRand = execRand;
}
Updater::Updater(QObject *parent) :
    QThread(parent)
{
}

void print(DoubleList<Comparer<Individuo> > *);


void Updater::run()
{
    while(_execRand){
        if (vrand.lenght() < 100){
            for (int x = 0; x < 100 - vrand.lenght(); x++){
                vrand.genRand();
            }
        }
        msleep(50);
    }

    /*
    DoubleList<Comparer<Individuo> > *_lista = new DoubleList<Comparer<Individuo> >();
    Poblation * po = new Poblation();
    po->setDataList(_lista);
    VillagerFabric *vf = new VillagerFabric();
    VillagerCrosser *vc= new VillagerCrosser();
    VillagerFinalState *vfs = new VillagerFinalState();
    Villager * theVillager = 0;
    vc->setIndividuousFabric(vf);
    for (int x =0; x < 150; x++){
        theVillager = vf->create(0);
        theVillager->setGender(x%2 == 0);
        _lista->add(Comparer<Individuo>(theVillager));
    }
    print(_lista);
    x = new MidgarDarwin(vc,vfs,po,2000);
    x->evolve();
    print(po->getDataList());
}

int Updater::getLenghtM()
{
    return x->getPoblation()->getLenght();
}

void print(DoubleList<Comparer<Individuo> > *lista)
{
    IIterator<Comparer<Individuo> > *_iter = lista->getIterator();
    Villager *currentdata =0;
    float hight = 0;
    int index =0;
    cout << endl<<">>>>>> lenght: "<<lista->getLenght()<<"" << endl;
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
            << " v-m: " <<currentdata->maximunLife() << " gen: " << (currentdata->gender()?"hombre":"mujer") <<
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
    }
    delete _iter;
    */
}

