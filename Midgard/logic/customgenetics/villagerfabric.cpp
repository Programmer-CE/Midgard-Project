#include "villagerfabric.h"
#include "logic/random.h"

int VillagerFabric::maximunLife() const
{
    return _maximunLife;
}

void VillagerFabric::setMaximunLife(int maximunLife)
{
    _maximunLife = maximunLife;
}

int VillagerFabric::attack() const
{
    return _attack;
}

void VillagerFabric::setAttack(int attack)
{
    _attack = attack;
}

int VillagerFabric::magic() const
{
    return _magic;
}

void VillagerFabric::setMagic(int magic)
{
    _magic = magic;
}

int VillagerFabric::defense() const
{
    return _defense;
}

void VillagerFabric::setDefense(int defense)
{
    _defense = defense;
}

int VillagerFabric::velocity() const
{
    return _velocity;
}

void VillagerFabric::setVelocity(int velocity)
{
    _velocity = velocity;
}

int VillagerFabric::intelligence() const
{
    return _intelligence;
}

void VillagerFabric::setIntelligence(int intelligence)
{
    _intelligence = intelligence;
}

std::string VillagerFabric::breed() const
{
    return _breed;
}

void VillagerFabric::setBreed(const std::string &breed)
{
    _breed = breed;
}

int VillagerFabric::type() const
{
    return _type;
}

void VillagerFabric::setType(int type)
{
    _type = type;
}


int VillagerFabric::vitalEnergy() const
{
    return _vitalEnergy;
}

void VillagerFabric::setVitalEnergy(int vitalEnergy)
{
    _vitalEnergy = vitalEnergy;
}

int VillagerFabric::blot() const
{
    return _blot;
}

void VillagerFabric::setBlot(int blot)
{
    _blot = blot;
}

int VillagerFabric::runes() const
{
    return _runes;
}

void VillagerFabric::setRunes(int runes)
{
    _runes = runes;
}

int VillagerFabric::superstition() const
{
    return _superstition;
}

void VillagerFabric::setSuperstition(int superstition)
{
    _superstition = superstition;
}
VillagerFabric::VillagerFabric()
{
    verificator = 0;
}

VillagerFabric::VillagerFabric(VillagersVerificator *pVerificator)
{
    verificator = pVerificator;
}
VillagersVerificator *VillagerFabric::getVerificator() const
{
    return verificator;
}

void VillagerFabric::setVerificator(VillagersVerificator *value)
{
    verificator = value;
}



Villager *VillagerFabric::create(int pType)
{
    Random vrand;
    Villager *toReturn = new Villager();
    toReturn->setAge(0);
    toReturn->setAgeToDeath(vrand.random()%100);
    toReturn->setAttack(vrand.random()%attack());
    toReturn->setBlot(vrand.random()%blot());
    toReturn->setDefense(vrand.random()%defense());
    toReturn->setExperience(0);
    toReturn->setGender(vrand.random()%2);
    toReturn->setIntelligence(vrand.random()%intelligence());
    toReturn->setIsSelected(0);
    toReturn->setMagic(vrand.random()%magic());
    toReturn->setMaximunLife(vrand.random()%maximunLife());
    toReturn->setRunes(vrand.random()%runes());
    toReturn->setSuperstition(vrand.random()%superstition());
    toReturn->setVelocity(vrand.random()%velocity());
    toReturn->setVitalEnergy(vrand.random()%vitalEnergy());
    toReturn->setType(pType);
    toReturn->setFitnessverify(verificator);
    return toReturn;

}


VillagerFabric *VillagerFabric::clone()
{
    VillagerFabric *newFabric = new VillagerFabric();
    *newFabric = *this;
    return newFabric;
}
