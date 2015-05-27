#include "villagercrosser.h"
#include "logic/random.h"
#include "iostream"

int VillagerCrosser::mixInts(int cromosomaA, int cromosomaB, int mascara)
{
    unsigned int othermask=-1;
    othermask = othermask^ mascara;
    int toReturn = ((cromosomaA&mascara) | (cromosomaB&othermask));
    return toReturn;
}

void VillagerCrosser::makeMask()
{
    /*
    mask=0;
    for (int x =0; x < sizeof(int)*4; x++){
        mask = mask << 2;
        mask++;
    }
    */
    Random vrand;
    if (vrand.random() %100 > 50){
        mask=0;
        for (int x =0; x < sizeof(int)*4; x++){
            mask = mask << 2;
            mask++;
        }
    }
    else{
        mask = -1;
        mask  = mask << vrand.random()%(sizeof(int)*2);
    }
}

VillagerCrosser::VillagerCrosser()
{
}


Individuo *VillagerCrosser::cross(Individuo *pParent, Individuo *pOtherParent)
{
    Villager *pParentCasted = ((Villager*)pParent);
    Villager *pOtherParentCasted = ((Villager*)pOtherParent);
    Villager *aBaby = (Villager*)getIndividuousFabric()->create(pParentCasted->type());
    makeMask();
    aBaby->setAgeToDeath(mixInts(pParentCasted->ageToDeath(),pOtherParentCasted->ageToDeath(),mask));
    makeMask();
    aBaby->setAttack(mixInts(pParentCasted->attack(),pOtherParentCasted->attack(),mask));
    makeMask();
    aBaby->setBlot(mixInts(pParentCasted->blot(),pOtherParentCasted->blot(),mask));
    makeMask();
    aBaby->setDefense(mixInts(pParentCasted->defense(),pOtherParentCasted->defense(),mask));
    makeMask();
    aBaby->setIntelligence(mixInts(pParentCasted->intelligence(),pOtherParentCasted->intelligence(),mask));
    makeMask();
    aBaby->setMagic(mixInts(pParentCasted->magic(),pOtherParentCasted->magic(),mask));
    makeMask();
    aBaby->setMaximunLife(mixInts(pParentCasted->maximunLife(),pOtherParentCasted->maximunLife(),mask));
    makeMask();
    aBaby->setRunes(mixInts(pParentCasted->runes(),pOtherParentCasted->runes(),mask));
    makeMask();
    aBaby->setSuperstition(mixInts(pParentCasted->superstition(),pOtherParentCasted->superstition(),mask));
    makeMask();
    aBaby->setVelocity(mixInts(pParentCasted->velocity(),pOtherParentCasted->velocity(),mask));
    makeMask();
    aBaby->setVitalEnergy(mixInts(pParentCasted->vitalEnergy(),pOtherParentCasted->vitalEnergy(),mask));
    return aBaby;
}
