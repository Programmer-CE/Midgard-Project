#include "poblation.h"

Poblation::Poblation()
{
    _poblation = 0;
}

void Poblation::setDataList(DoubleList<Comparer<Individuo> > *pPoblation)
{
    _poblation = pPoblation;
}

DoubleList<Comparer<Individuo> > *Poblation::getDataList()
{
    return _poblation;
}


Individuo *Poblation::getIndividuousByIndex(int pIndex)
{
    if (pIndex < 0 || pIndex >=_poblation->getLenght())return 0;
    else return _poblation->get(pIndex).getData();
}

Individuo *Poblation::getIndividuousById(int pId)
{
    // una simple obtencion de datos
    IIterator<Comparer<Individuo> > *iterator = _poblation->getIterator();
    int x;
    for (x = 0; x < _poblation->getLenght();x++){
        if (iterator->getCurrent().getData()->getId() == pId){
            break;
        }
        iterator->getNext();
    }
    Individuo * individuo;
    if (x == _poblation->getLenght()){
        individuo = 0;
    }
    else individuo = iterator->getCurrent().getData();
    delete iterator;
    return individuo;

}

void Poblation::addIndividuous(Individuo *pIndividuous)
{
    _poblation->add(Comparer<Individuo>(pIndividuous));
}

bool Poblation::removeIndividuousByIndex(int pIndex)
{
    return _poblation->remove(pIndex);
}

bool Poblation::removeIndividuousById(int pId)
{
    // una simple obtencion de datos
    IIterator<Comparer<Individuo> > *iterator = _poblation->getIterator();
    int x =0;
    for (x = 0; x < _poblation->getLenght();x++){
        if (iterator->getCurrent().getData()->getId() == pId){
            break;
        }
        iterator->getNext();
    }
    delete iterator;
    return _poblation->remove(x);
}

int Poblation::getLenght()
{
    return _poblation->getLenght();
}

IIterator<Comparer<Individuo> > *Poblation::getIterator()
{
    return _poblation->getIterator();
}

