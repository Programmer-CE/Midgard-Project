#include "genetics/crosser.h"
#include "villager.h"
#include "logic/random.h"
#ifndef VILLAGERCROSSER_H
#define VILLAGERCROSSER_H

class VillagerCrosser:public Crosser
{
    Random _random;
    unsigned int mask;
    int mixInts(int cromosomaA,int cromosomaB, int mascara);
    void makeMask();
public:
    VillagerCrosser();
    // Crosser interface
public:
    Individuo *cross(Individuo *pParent, Individuo *pPoblation);
};

#endif // VILLAGERCROSSER_H
