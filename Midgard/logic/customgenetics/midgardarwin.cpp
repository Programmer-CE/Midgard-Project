#include "midgardarwin.h"
#include "ordinateList/doublelist.h"
#include <iostream>
#include "villager.h"
#include "logic/random.h"
#include "villagersverificator.h"
using namespace std;

void MidgarDarwin::sortPoblationByFitness()
{
    DoubleList<Comparer<Individuo> > * mylist =  new DoubleList<Comparer<Individuo> >;
    DoubleList<Comparer<Individuo> > *poblacion = getPoblation()->getDataList();
    Comparer<Individuo> ind(0);
    int x = poblacion->getLenght()-1;
    while(poblacion->getLenght() != 0){
        ind = poblacion->get(0);
        poblacion->remove(0);
        mylist->add(ind);
    }
    _poblacion->setDataList(mylist);
    delete poblacion;
}

MidgarDarwin::MidgarDarwin(Crosser *pCrosser, FinalStateVerificator *pEndOfAlgorithm, Poblation *pPoblation, int pGenerationTop):
    Darwin(pCrosser,pEndOfAlgorithm, pPoblation,pGenerationTop)
{

}

void MidgarDarwin::removeIndividuous()
{
    sortPoblationByFitness();
    Poblation *poblation = getPoblation();
    Villager* tmp = 0;
    Random vrand;
    int g = vrand.random()%2;
    int protect = 0;
    if (_newGenerationLenght != 0 ){
        protect = vrand.random()%_newGenerationLenght;
        if (g)protect = -1;
        int deletes = 0;
        for (int x = poblation->getLenght()-1; x >-1 ;x--){
            tmp = (Villager*)poblation->getIndividuousByIndex(x);
            if (deletes == _newGenerationLenght)break;
            if (tmp->fitness() < promedio){
                if(protect != x){
                    poblation->removeIndividuousByIndex(x);
                    delete tmp;
                }
                deletes++;
            }
        }
    }
}

float MidgarDarwin::calculateTotalFitness()
{
    Poblation *poblation = getPoblation();
    IIterator<Comparer<Individuo> > *_iterator = poblation->getIterator();
    FitnessVerificator* verificator = _iterator->getCurrent().getData()->fitnessverify();
    float currentFitness = 0;
    float totalFitness = 0;
    float pivot = 0;
    atkprom = 0;
    pivot =0;
    /*
    for(int x = 0; x < poblation->getLenght();x++){
        pivot = ((Villager*)_iterator->getNext().getData())->attack();
        atkprom += pivot;
    }
    delete _iterator;
    atkprom /=poblation->getLenght();
    _iterator = poblation->getIterator();
    defprom = 0;
    pivot =0;
    for(int x = 0; x < poblation->getLenght();x++){
        pivot = ((Villager*)_iterator->getNext().getData())->defense();
        atkprom += pivot;
    }
    defprom /=poblation->getLenght();
    delete _iterator;
    _iterator = poblation->getIterator();
    blotprom = 0;
    pivot =0;
    for(int x = 0; x < poblation->getLenght();x++){
        pivot = ((Villager*)_iterator->getNext().getData())->blot();
        atkprom += pivot;
    }
    blotprom /=poblation->getLenght();
    ((VillagersVerificator*)verificator)->_Atkprom = atkprom;
    ((VillagersVerificator*)verificator)->_Defenseprom = defprom;
    ((VillagersVerificator*)verificator)->_Blotprom = blotprom;
    _iterator = poblation->getIterator();
    */
    for (int x = 0; x < poblation->getLenght(); x++){
        verificator = _iterator->getCurrent().getData()->fitnessverify();
        currentFitness = verificator->verifyIndividuo(_iterator->getCurrent().getData());
        _iterator->getNext().getData()->setFitness(currentFitness);
        totalFitness +=currentFitness;
    }
    delete _iterator;
    return totalFitness;

}

void MidgarDarwin::select()
{
    promedio = 0;
    float pivot = 0;
    Poblation *poblation = getPoblation();
    IIterator<Comparer<Individuo> > *_iterator = poblation->getIterator();
    // busca el promedio de individuos
    for(int x = 0; x < poblation->getLenght();x++){
        pivot = _iterator->getNext().getData()->fitness();
        promedio += pivot;
    }
    promedio /= poblation->getLenght();
    delete _iterator;
    _iterator = 0;
    _iterator = poblation->getIterator();
    Individuo* individuo = 0;
    int selecteds = 0;
    for(int x = 0; x < poblation->getLenght();x++){
        individuo =_iterator->getNext().getData();
        if (individuo->fitness() < promedio){// || poblation->getLenght()*0.7 < selecteds){
            individuo->setIsSelected(false);

        }
        else if (individuo->fitness() >= promedio){
            individuo->setIsSelected(true);
            selecteds++;
        }
    }
    delete _iterator;

}


Individuo *MidgarDarwin::searchIndividuoToMatch(Individuo *pParent)
{
    Poblation *pPoblation = getPoblation();
    Random vrandom;
    IIterator<Comparer<Individuo> > *_iterator = pPoblation->getIterator();
    Villager *pOtherParent = 0;
    DoubleList<int> _indexes;
    for (int x = 0; x < pPoblation->getLenght();x++){
        pOtherParent = (Villager*)_iterator->getNext().getData();
        if (((Villager*)pParent)->gender() ^ pOtherParent->gender()){
            _indexes.add(x);
        }
    }
    delete _iterator;
    if (_indexes.getLenght() !=0)pOtherParent = (Villager *)pPoblation->getIndividuousByIndex(_indexes.get(vrandom.random()%_indexes.getLenght()));
    else pOtherParent = 0;
    return pOtherParent;
}

MidgarDarwin::~MidgarDarwin()
{
    //std::cout << "darwin delete: " << _poblacion->getLenght() <<std::endl;
    while(_poblacion->getLenght() !=0){
        delete _poblacion->getIndividuousByIndex(0);
        _poblacion->removeIndividuousByIndex(0);
    }
    delete _poblacion;
    delete _crosser;
}
