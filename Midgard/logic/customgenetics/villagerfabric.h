#ifndef VILLAGERFABRIC_H
#define VILLAGERFABRIC_H
#include "genetics/individuousfabric.h"
#include "villager.h"
#include "villagersverificator.h"
class VillagerFabric:public IndividuousFabric
{
public:
    VillagerFabric();
    VillagersVerificator * verificator;

    // IndividuousFabric interface
public:
    virtual Villager *create(int pType);
};

#endif // VILLAGERFABRIC_H
