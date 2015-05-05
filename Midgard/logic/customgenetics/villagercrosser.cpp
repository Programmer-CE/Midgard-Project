#include "villagercrosser.h"
#include "logic/random.h"

unsigned int VillagerCrosser::getMask(int pPivot, bool insertOnLeft)
{
    unsigned int mask = -1;
    return insertOnLeft?mask>>pPivot:mask<<pPivot;

}

int VillagerCrosser::mixInts(int cromosomaA, int cromosomaB, int mascara)
{
    unsigned int othermask=-1;
    othermask = othermask^ mascara;
    int toReturn = ((cromosomaA&mascara) | (cromosomaB&othermask));
    return toReturn;
}

VillagerCrosser::VillagerCrosser()
{
}


Individuo *VillagerCrosser::cross(Individuo *pParent, Poblation *pPoblation)
{
    Random vrandom;
    vrandom;
    int splitCaracterist = (vrandom.random()%sizeof(int))*2;
    Villager *aBaby = (Villager*)getIndividuousFabric()->create(((Villager*)pParent)->type());
    unsigned int mask = -1;
    bool insetOnLeft = (vrandom.random()%100)+1 > 50;
    mask = getMask(splitCaracterist,insetOnLeft);
    IIterator<Comparer<Individuo> > *_iterator = pPoblation->getIterator();
    Villager *pOtherParent = 0;
    int reproduct = vrandom.random()%100;
    bool selected = false;
    for (int x = 0; x < pPoblation->getLenght();x++){
        pOtherParent = (Villager*)_iterator->getNext().getData();
        if (((Villager*)pParent)->gender() ^ pOtherParent->gender()){
            // si es mayor al valor de reproduccion con un individuo bueno
            // se reproducira con un individuo bueno
            // en otro caso se reproducira con un individuo malo
            if (reproduct > 15)if(pOtherParent->isSelected()){selected = true; break;}
            else if(!pOtherParent->isSelected()){selected = true;break;}
        }
    }
    int x = 0;
    if (!selected){
        do{
            pOtherParent = (Villager*)pPoblation->getIndividuousByIndex(x++);
        }while(pOtherParent->getId() == ((Villager*)pParent)->getId() || !(pOtherParent->gender() ^ ((Villager*)pParent)->gender()) && x < pPoblation->getLenght());
    }
    delete _iterator;
    if (x != pPoblation->getLenght()){
        aBaby->setAgeToDeath(mixInts(((Villager*)pParent)->ageToDeath(),pOtherParent->ageToDeath(),mask));
        aBaby->setAttack(mixInts(((Villager*)pParent)->attack(),pOtherParent->attack(),mask));
        aBaby->setBlot(mixInts(((Villager*)pParent)->blot(),pOtherParent->blot(),mask));
        aBaby->setDefense(mixInts(((Villager*)pParent)->defense(),pOtherParent->defense(),mask));
        aBaby->setIntelligence(mixInts(((Villager*)pParent)->intelligence(),pOtherParent->intelligence(),mask));
        aBaby->setMagic(mixInts(((Villager*)pParent)->magic(),pOtherParent->magic(),mask));
        aBaby->setMaximunLife(mixInts(((Villager*)pParent)->maximunLife(),pOtherParent->maximunLife(),mask));
        aBaby->setRunes(mixInts(((Villager*)pParent)->runes(),pOtherParent->runes(),mask));
        aBaby->setSuperstition(mixInts(((Villager*)pParent)->superstition(),pOtherParent->superstition(),mask));
        aBaby->setVelocity(mixInts(((Villager*)pParent)->velocity(),pOtherParent->velocity(),mask));
        aBaby->setVitalEnergy(mixInts(((Villager*)pParent)->vitalEnergy(),pOtherParent->vitalEnergy(),mask));
        return aBaby;
    }
    else{
        return 0;
    }

}
