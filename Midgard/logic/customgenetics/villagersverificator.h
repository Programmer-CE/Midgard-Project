#include "genetics/fitnessverificator.h"
#include "villager.h"
#ifndef VILLAGERSVERIFICATOR_H
#define VILLAGERSVERIFICATOR_H

class VillagersVerificator:public FitnessVerificator
{
public:
    VillagersVerificator();
    int _Atkprom,_Defenseprom, _Blotprom;
    // FitnessVerificator interface
public:
    float verifyIndividuo(Individuo *);
    virtual ~VillagersVerificator(){

    }

};

#endif // VILLAGERSVERIFICATOR_H
