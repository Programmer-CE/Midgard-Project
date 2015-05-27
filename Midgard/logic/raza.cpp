#include "raza.h"


QString Raza::getName() const
{
    return name;
}

void Raza::setName(const QString &value)
{
    name = value;
}

void Raza::addVillagerVerificator(VillagersVerificator *toAdd)
{
    _Verificators.add(toAdd);
}

void Raza::addVillagerFabric(VillagerFabric *toAdd)
{
    _Fabrics.add(toAdd);
}

VillagerFabric *Raza::getFrabric(int pIndex)
{

    return _Fabrics.get(pIndex);
}

VillagersVerificator *Raza::getVerificator(int pIndex)
{
    return _Verificators.get(pIndex);
}

int Raza::lenghtFabric()
{
    return _Fabrics.getLenght();
}

int Raza::lenghtVerificator()
{
    return _Verificators.getLenght();
}

Raza::~Raza()
{
    VillagersVerificator *ver;
    while(!_Verificators.isEmpty()){
        ver = _Verificators.get(0);
        delete ver;
        _Verificators.remove(0);
    }
    VillagerFabric *fab;
    while(!_Fabrics.isEmpty()){
        fab = _Fabrics.get(0);
        delete fab;
        _Fabrics.remove(0);
    }
}

Raza::Raza()
{
}
