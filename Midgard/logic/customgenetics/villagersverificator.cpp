#include "villagersverificator.h"
#include "iostream"

int VillagersVerificator::maxlife() const
{
    return _maxlife;
}

void VillagersVerificator::setMaxlife(int maxlife)
{
    _maxlife = maxlife;
}

int VillagersVerificator::attack() const
{
    return _attack;
}

void VillagersVerificator::setAttack(int attack)
{
    _attack = attack;
}

int VillagersVerificator::defense() const
{
    return _defense;
}

void VillagersVerificator::setDefense(int defense)
{
    _defense = defense;
}

int VillagersVerificator::intelligence() const
{
    return _intelligence;
}

void VillagersVerificator::setIntelligence(int intelligence)
{
    _intelligence = intelligence;
}

int VillagersVerificator::blot() const
{
    return _blot;
}

void VillagersVerificator::setBlot(int blot)
{
    _blot = blot;
}

int VillagersVerificator::rune() const
{
    return _rune;
}

void VillagersVerificator::setRune(int rune)
{
    _rune = rune;
}

int VillagersVerificator::superstition() const
{
    return _superstition;
}

void VillagersVerificator::setSuperstition(int superstition)
{
    _superstition = superstition;
}

int VillagersVerificator::vitalEnergy() const
{
    return _vitalEnergy;
}

void VillagersVerificator::setVitalEnergy(int vitalEnergy)
{
    _vitalEnergy = vitalEnergy;
}

int VillagersVerificator::maxAge() const
{
    return _maxAge;
}

void VillagersVerificator::setMaxAge(int maxAge)
{
    _maxAge = maxAge;
}

int VillagersVerificator::magic() const
{
    return _magic;
}

void VillagersVerificator::setMagic(int magic)
{
    _magic = magic;
}

int VillagersVerificator::velocity() const
{
    return _velocity;
}

void VillagersVerificator::setVelocity(int velocity)
{
    _velocity = velocity;
}

QString VillagersVerificator::breed() const
{
    return _breed;
}

void VillagersVerificator::setBreed(const QString &breed)
{
    _breed = breed;
}

void VillagersVerificator::nextStage()
{
    //superstition upgrade
    if(_stage == 0){
        _blot = -_blot+1*2;
    }
    //science upgrade
    else if (_stage == 1){
        _intelligence *4;

    }
    //supremacy upgrade
    else if (_stage == 2){
        _attack = 1;
        _defense = 1;
        _blot = 1;
        _intelligence = 1;
        _magic = 1;
        _maxlife =1;
        _rune = 1;
        _superstition = 1;
        _velocity = 1;
        _vitalEnergy = 1;
    }
    _stage++;
}
VillagersVerificator::VillagersVerificator()
{
    _stage = 0;
}

float VillagersVerificator::verifyIndividuo(Individuo *pIndividuo)
{
    Villager * pVillager= (Villager*)pIndividuo;
    float prefitness = 0;
    float bone = 0;
    //prefitness += pVillager->ageToDeath();
    /**
    if(_Atkprom > pVillager->attack()){
        if (_Atkprom*0.2f > pVillager->attack()){
            prefitness += 0.2f* pVillager->attack();
        }
        else if (_Atkprom*0.4f > pVillager->attack()){
            prefitness += 0.4f* pVillager->attack();
        }
        else if (_Atkprom*0.6f > pVillager->attack()){
            prefitness += 0.6f* pVillager->attack();
        }
        else if (_Atkprom*0.8f > pVillager->attack()){
            prefitness += 0.8f* pVillager->attack();
        }
        else{
            prefitness += 0.9*pVillager->attack();
        }
    }
    else{
        if (_Atkprom < pVillager->attack()*0.2f){
            prefitness += 2*pVillager->attack();
            prefitness += 8*pVillager->attack();
        }
        else if (_Atkprom < pVillager->attack()*0.4f){
            prefitness += 6* pVillager->attack();
        }
        else if (_Atkprom < pVillager->attack()*0.6f){
            prefitness += 4* pVillager->attack();
        }
        else if (_Atkprom < pVillager->attack()*0.8f){
            prefitness += pVillager->defense();
        }
        else{
            prefitness += pVillager->attack();
        }
    }

    if(_Defenseprom > pVillager->defense()){
        if (_Defenseprom*0.2f > pVillager->defense()){
            prefitness += 0.2f* pVillager->defense();
        }
        else if (_Defenseprom*0.4f > pVillager->defense()){
            prefitness += 0.4f* pVillager->defense();
        }
        else if (_Defenseprom*0.6f > pVillager->defense()){
            prefitness += 0.6f* pVillager->defense();
        }
        else if (_Defenseprom*0.8f > pVillager->defense()){
            prefitness += 0.8f* pVillager->defense();
        }
        else{
            prefitness += 0.9f*pVillager->defense();
        }
    }
    else{
        if (_Defenseprom < pVillager->defense()*0.8f){
            prefitness += 2*pVillager->defense();
        }
        else if (_Defenseprom < pVillager->defense()*0.6f){
            prefitness += 4* pVillager->defense();
        }
        else if (_Defenseprom < pVillager->defense()*0.4f){
            prefitness += 6* pVillager->defense();
        }
        else if (_Defenseprom < pVillager->defense()*0.2f){
            prefitness += 8* pVillager->defense();
            prefitness += pVillager->attack();
        }
        else{
            prefitness += 9* pVillager->defense();
            prefitness += 2*pVillager->attack();
        }
    }
    if(_Blotprom > pVillager->blot()){
        if (_Blotprom*0.2f > pVillager->blot()){
            prefitness += 8* pVillager->blot();
        }
        else if (_Blotprom*0.4f > pVillager->blot()){
            prefitness += 6* pVillager->blot();
        }
        else if (_Blotprom*0.6f > pVillager->blot()){
            prefitness += 4* pVillager->blot();
        }
        else if (_Blotprom*0.8f > pVillager->blot()){
            prefitness += 2* pVillager->blot();
        }
        else{
            prefitness += pVillager->blot();
        }
    }
    else{
        if (_Blotprom < pVillager->blot()*0.8f){
            prefitness += 0.2f*pVillager->blot();
        }
        else if (_Blotprom < pVillager->blot()*0.6f){
            prefitness += 0.4f* pVillager->blot();
        }
        else if (_Blotprom < pVillager->blot()*0.4f){
            prefitness += 0.6f* pVillager->blot();
        }
        else if (_Blotprom < pVillager->blot()*0.2f){
            prefitness += 0.8f* pVillager->blot();
        }
        else{
            prefitness += 0.9* pVillager->blot();
        }
    }
    */
    prefitness += _attack*pVillager->attack();
    prefitness += _defense*pVillager->defense();
    prefitness -= _blot*pVillager->blot();
    prefitness += _intelligence*pVillager->intelligence();
    prefitness -= _magic*pVillager->magic();
    prefitness += _maxlife*pVillager->maximunLife();
    prefitness += _rune*pVillager->runes();
    prefitness += _superstition*pVillager->superstition();
    prefitness += _velocity*pVillager->velocity();
    prefitness -= _vitalEnergy*pVillager->vitalEnergy();
    return prefitness;
}

