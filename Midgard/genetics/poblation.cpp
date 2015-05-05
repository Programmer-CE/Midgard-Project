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
    Individuo *individuo = new Individuo();
    individuo->_id = pId;
    Comparer<Individuo> comparer(individuo);
    int pindex = _poblation->search(comparer);
    delete individuo;
    if (pindex == -1)individuo = 0;
    else individuo = _poblation->get(pindex).getData();
    return individuo;

}

bool Poblation::addIndividuous(Individuo *pIndividuous)
{
    return _poblation->add(Comparer<Individuo>(pIndividuous));
}

bool Poblation::removeIndividuousByIndex(int pIndex)
{
    return _poblation->remove(pIndex);
}

bool Poblation::removeIndividuousById(int pId)
{
    // una simple obtencion de datos
    Individuo *individuo = new Individuo();
    individuo->_id = pId;
    Comparer<Individuo> comparer(individuo);
    int pindex = _poblation->search(comparer);
    return _poblation->remove(pindex);
}

int Poblation::getLenght()
{
    return _poblation->getLenght();
}

IIterator<Comparer<Individuo> > *Poblation::getIterator()
{
    return _poblation->getIterator();
}

