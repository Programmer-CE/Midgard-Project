#include "individuo.h"


int Individuo::_Serial = 0;

int Individuo::getId()const
{
    return _id;
}

bool Individuo::isToDelete()
{
    return _toDelete;
}

void Individuo::setToDelete(bool toDelete)
{
    _toDelete = toDelete;
}


FitnessVerificator *Individuo::fitnessverify() const
{
    return _fitnessverify;
}

void Individuo::setFitnessverify(FitnessVerificator *fitnessverify)
{
    _fitnessverify = fitnessverify;
}

Individuo::~Individuo(){
}


bool Individuo::isSelected() const
{
    return _isSelected;
}

void Individuo::setIsSelected(bool isSelected)
{
    _isSelected = isSelected;
}
Individuo::Individuo()
{
    _id = _Serial++;
    _fitnessverify = 0;
    _fitness = 0;
}

float Individuo::fitness() const
{
    return _fitness;
}

void Individuo::setFitness(float fitness)
{
    _fitness = fitness;
}
