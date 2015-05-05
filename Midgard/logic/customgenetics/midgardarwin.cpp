#include "midgardarwin.h"
#include "ordinateList/doublelist.h"
#include <iostream>
using namespace std;

MidgarDarwin::MidgarDarwin(Crosser *pCrosser, FinalStateVerificator *pEndOfAlgorithm, Poblation *pPoblation, int pGenerationTop):
    Darwin(pCrosser,pEndOfAlgorithm, pPoblation,pGenerationTop)
{

}

void MidgarDarwin::removeIndividuous()
{
    DoubleList<int> _individuos;
    Poblation *poblation = getPoblation();
    IIterator<Comparer<Individuo> > *_iterator = poblation->getIterator();
    for (int x=0;x<poblation->getLenght();x++){
        if (!_iterator->getNext().getData()->isSelected()){
            _individuos.add(x);
        }
    }
    delete _iterator;
    _iterator = 0;
    IIterator<int> *_iterator2 = _individuos.getIterator();
    int toSave = 0;
    Individuo* tmp = 0;
    float _maxOfMin = 0;
    // la operacion se hace en dos "fors" para que disminuir el peso de la operacion
    for (int x =0; x < _individuos.getLenght();x++){
        //cout << "remove madafaka"<<endl;
        tmp = _poblacion->getIndividuousByIndex(_iterator2->getCurrent());
        if (_maxOfMin < tmp->fitness()){
            _maxOfMin = tmp->fitness();
            toSave = x;
        }
    }
    delete _iterator2;
    _iterator2 = _individuos.getIterator();
    tmp = 0;
    // la operacion se hace en dos "fors" para que disminuir el peso de la operacion
    for (int x =0; x < _individuos.getLenght();x++){
        //cout << "remove madafaka"<<endl;
        if (x != toSave){
            tmp = _poblacion->getIndividuousByIndex(_iterator2->getCurrent());
            _poblacion->removeIndividuousByIndex(_iterator2->getNext());
            delete tmp;
        }
    }
    delete _iterator2;
}

float MidgarDarwin::calculateTotalFitness()
{
    Poblation *poblation = getPoblation();
    IIterator<Comparer<Individuo> > *_iterator = poblation->getIterator();
    FitnessVerificator* verificator = 0;
    float currentFitness = 0;
    float totalFitness = 0;
    for (int x = 0; x < poblation->getLenght(); x++){
        verificator = _iterator->getCurrent().getData()->fitnessverify();
        currentFitness = verificator->verifyIndividuo(_iterator->getCurrent().getData());
        _iterator->getNext().getData()->setFitness(currentFitness);
        totalFitness +=currentFitness;
    }
    delete _iterator;
    /**
    _iterator = poblation->getIterator();
    for (int x = 0; x < poblation->getLenght(); x++){
        currentFitness = _iterator->getCurrent().getData()->fitness();
        _iterator->getNext().getData()->setFitness(currentFitness/totalFitness);
    }
    delete _iterator;
    */
    return totalFitness;

}

void MidgarDarwin::select()
{
    float overSelect = 0;
    float pivot = 0;
    float min;
    Poblation *poblation = getPoblation();
    IIterator<Comparer<Individuo> > *_iterator = poblation->getIterator();
    // busca el mayor
    for(int x = 0; x < poblation->getLenght();x++){
        pivot = _iterator->getNext().getData()->fitness();
        if (pivot > overSelect)overSelect = pivot;
    }
    delete _iterator;
    _iterator = poblation->getIterator();
    pivot = overSelect;
    // busca el menor
    for(int x = 0; x < poblation->getLenght();x++){
        min = _iterator->getNext().getData()->fitness();
        if (min < pivot)pivot= min;
    }
    delete _iterator;
    // el que sea mayor o igual al valor overSelect sera seleccionado
    overSelect -=pivot;
    _iterator = poblation->getIterator();
    Individuo* individuo = 0;
    int selecteds = 0;
    for(int x = 0; x < poblation->getLenght();x++){
        individuo =_iterator->getNext().getData();
        if (individuo->fitness() < overSelect){// || poblation->getLenght()*0.7 < selecteds){
            individuo->setIsSelected(false);

        }
        else if (individuo->fitness() > overSelect){
            individuo->setIsSelected(true);
            selecteds++;
        }
    }
}
