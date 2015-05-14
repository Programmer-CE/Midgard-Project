#include "genetics/finalstateverificator.h"
#ifndef VILLAGERFINALSTATE_H
#define VILLAGERFINALSTATE_H

class VillagerFinalState:public FinalStateVerificator
{
public:
    VillagerFinalState();

    // FinalStateVerificator interface
public:
    bool verifyFinalStatus();
};

#endif // VILLAGERFINALSTATE_H
