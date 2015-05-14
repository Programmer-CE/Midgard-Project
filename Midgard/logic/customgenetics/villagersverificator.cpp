#include "villagersverificator.h"

VillagersVerificator::VillagersVerificator()
{
}

float VillagersVerificator::verifyIndividuo(Individuo *pIndividuo)
{
    Villager * pVillager= (Villager*)pIndividuo;
    float prefitness = 0;
    //prefitness += pVillager->ageToDeath();
    if(_Atkprom > pVillager->attack())prefitness += 0.5f* pVillager->attack();
    else prefitness += 3*pVillager->attack();
    if (_Defenseprom > pVillager->defense())prefitness += 0.5f*pVillager->defense();
    else prefitness += 3*pVillager->defense();
    if (pVillager->blot()*0.3 > _Blotprom)prefitness -=pVillager->blot();
    else prefitness += pVillager->blot();
    prefitness -= 1*pVillager->intelligence();
    prefitness += 1*pVillager->magic();
    prefitness += 1*pVillager->maximunLife();
    prefitness += 1*pVillager->runes();
    prefitness += 1*pVillager->superstition();
    prefitness += 1*pVillager->velocity();
    prefitness -= 1*pVillager->vitalEnergy();
    return prefitness;
}

