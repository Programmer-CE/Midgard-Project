#include "crosser.h"

Crosser::Crosser()
{
    _fabric = 0;
}

void Crosser::setIndividuousFabric(IndividuousFabric *pFabric)
{
    _fabric = pFabric;
}

IndividuousFabric *Crosser::getIndividuousFabric() const
{
    return _fabric;
}
