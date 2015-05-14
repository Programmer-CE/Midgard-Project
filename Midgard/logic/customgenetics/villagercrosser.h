#include "genetics/crosser.h"
#include "villager.h"
#include "logic/random.h"
#ifndef VILLAGERCROSSER_H
#define VILLAGERCROSSER_H

class VillagerCrosser:public Crosser
{
    Random _random;
    unsigned int getMask(int pPivot, bool insertOnLeft);
    int mixInts(int cromosomaA,int cromosomaB, int mascara);
public:
    VillagerCrosser();
    // Crosser interface
public:
    Individuo *cross(Individuo *pParent, Poblation *pPoblation);
};

#endif // VILLAGERCROSSER_H
