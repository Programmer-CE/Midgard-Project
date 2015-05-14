#include "darwin.h"
#include "exception/nullpointerexception.h"
#include "list/IIterator.h"
#include <iostream>
Darwin::Darwin(Crosser *pCrosser, FinalStateVerificator *pEndOfAlgorithm, Poblation *pPoblation, int pGenerationTop)
{
    if (pCrosser && pEndOfAlgorithm && pPoblation && pGenerationTop > 0){
        _crosser = pCrosser;
        _finalStateVerificator = pEndOfAlgorithm;
        _poblacion = pPoblation;
        _generationTop = pGenerationTop;
    }
    else{
        throw NullPointerException();
    }

}

void Darwin::evolve()
{
    for(int generation = 0; generation < _generationTop && !_finalStateVerificator->verifyFinalStatus(); generation++){
        evolveStep();
    }
}

void Darwin::evolveStep()
{
    _fitness = calculateTotalFitness();
    select();
    IIterator<Comparer<Individuo> > *_iterator = _poblacion->getIterator();
    DoubleList<Comparer<Individuo> > *nuevaGeneracion =  new DoubleList<Comparer<Individuo> >();
    for (int individuo = 0; individuo < _poblacion->getLenght(); individuo++){
        if(_iterator->getCurrent().getData()->isSelected()){
            Individuo *parent = searchIndividuoToMatch(_iterator->getCurrent().getData());
            if (parent){
                Individuo *child = _crosser->cross(parent,_iterator->getCurrent().getData());
                nuevaGeneracion->add(Comparer<Individuo>(child));
            }
            else{
            }
        }
        _iterator->getNext();
    }
    _newGenerationLenght = nuevaGeneracion->getLenght();
    //agrega a los individuos buenos de la nueva generacion
    delete _iterator;
    _iterator = nuevaGeneracion->getIterator();
    for (int x = 0; x < nuevaGeneracion->getLenght();x++){
        getPoblation()->addIndividuous(_iterator->getNext().getData());
    }
    delete nuevaGeneracion;
    delete _iterator;
    // remueve los individuos malos de la vieja generacion
    removeIndividuous();

}

Poblation *Darwin::getPoblation()
{
    return _poblacion;
}

Darwin::~Darwin()
{

}

