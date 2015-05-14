#include "villagersverificator.h"

VillagersVerificator::VillagersVerificator()
{
}

float VillagersVerificator::verifyIndividuo(Individuo *pIndividuo)
{
    Villager * pVillager= (Villager*)pIndividuo;
    float prefitness = 0;
    //prefitness += pVillager->ageToDeath();
    prefitness += 1*pVillager->attack();
    //prefitness -= 1*pVillager->blot();
    //prefitness += 1*pVillager->defense();
    //prefitness -= 1*pVillager->intelligence();
    //prefitness += 1*pVillager->magic();
    //prefitness += 1*pVillager->maximunLife();
    //prefitness -= 1*pVillager->runes();
    //prefitness -= 1*pVillager->superstition();
    //prefitness += 1*pVillager->velocity();
    //prefitness -= 1*pVillager->vitalEnergy();
    return prefitness;
}

