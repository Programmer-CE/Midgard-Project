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
            nuevaGeneracion->add(Comparer<Individuo>(_crosser->cross(_iterator->getNext().getData(),getPoblation())));
        }
    }
    // remueve los individuos malos de la vieja generacion
    removeIndividuous();
    delete _iterator;
    _iterator = nuevaGeneracion->getIterator();
    for (int x = 0; x < nuevaGeneracion->getLenght();x++){
        _poblacion->addIndividuous(_iterator->getNext().getData());
    }
    delete nuevaGeneracion;
    delete _iterator;
}

Poblation *Darwin::getPoblation()
{
    return _poblacion;
}

Darwin::~Darwin()
{

}

