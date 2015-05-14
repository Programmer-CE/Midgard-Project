#include "villagerfabric.h"
#include "logic/random.h"
VillagerFabric::VillagerFabric()
{
    verificator = new VillagersVerificator();
}


Villager *VillagerFabric::create(int pType)
{
    Random vrand;
    Villager *toReturn = new Villager();
    toReturn->setAge(0);
    toReturn->setAgeToDeath(vrand.random()%100);
    toReturn->setAttack(vrand.random()%200);
    toReturn->setBlot(vrand.random()%100);
    toReturn->setDefense(vrand.random()%100);
    toReturn->setExperience(0);
    toReturn->setGender(vrand.random()%2);
    toReturn->setIntelligence(vrand.random()%100);
    toReturn->setIsSelected(0);
    toReturn->setMagic(vrand.random()%100);
    toReturn->setMaximunLife(vrand.random()%400);
    toReturn->setRunes(vrand.random()%100);
    toReturn->setSuperstition(vrand.random()%100);
    toReturn->setVelocity(vrand.random()%100);
    toReturn->setVitalEnergy(vrand.random()%100);
    toReturn->setType(pType);
    toReturn->setFitnessverify(verificator);
    return toReturn;

}
