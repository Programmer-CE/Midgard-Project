#include "villager.h"


int Villager::ageToDeath() const
{
    return _ageToDeath;
}

void Villager::setAgeToDeath(int ageToDeath)
{
    _ageToDeath = ageToDeath;
}

int Villager::age() const
{
    return _age;
}

void Villager::setAge(int age)
{
    _age = age;
}

int Villager::experience() const
{
    return _experience;
}

void Villager::setExperience(int experience)
{
    _experience = experience;
}

int Villager::vitalEnergy() const
{
    return _vitalEnergy;
}

void Villager::setVitalEnergy(int vitalEnergy)
{
    _vitalEnergy = vitalEnergy;
}

int Villager::blot() const
{
    return _blot;
}

void Villager::setBlot(int blot)
{
    _blot = blot;
}

int Villager::runes() const
{
    return _runes;
}

void Villager::setRunes(int runes)
{
    _runes = runes;
}

int Villager::superstition() const
{
    return _superstition;
}

void Villager::setSuperstition(int superstition)
{
    _superstition = superstition;
}

bool Villager::gender() const
{
    return _gender;
}

void Villager::setGender(bool gender)
{
    _gender = gender;
}

int Villager::poblationId() const
{
    return _poblationId;
}

void Villager::setPoblationId(int poblationId)
{
    _poblationId = poblationId;
}

string Villager::breed() const
{
    return _breed;
}

void Villager::setBreed(const string &breed)
{
    _breed = breed;
}

int Villager::x() const
{
    return _x;
}

void Villager::setX(int x)
{
    _x = x;
}

int Villager::y() const
{
    return _y;
}

void Villager::setY(int y)
{
    _y = y;
}

int Villager::type() const
{
    return _type;
}

void Villager::setType(int type)
{
    _type = type;
}

bool Villager::operator <(const Individuo &v)
{
    const Villager *ptr = ((const Villager*) &v);

    /**
    if (attack() < ptr->attack())return true;
    else if (attack() == ptr->attack()){
        if (defense() < ptr->defense())return true;
        else if (defense() == ptr->defense())return blot() > ptr->blot();
    }
    return false;
    */
    return fitness() < v.fitness();
}

bool Villager::operator >(const Individuo &v)
{
    /*
    const Villager *ptr = ((const Villager*) &v);
    if (attack() > ptr->attack())return true;
    else if (attack() == ptr->attack()){
        if (defense() > ptr->defense())return true;
        else if (defense() == ptr->defense())return blot() < ptr->blot();
    }
    return false;
    */
    return fitness() > v.fitness();
}

bool Villager::operator !=(const Individuo &v)
{
    return getId() != v.getId();
}

bool Villager::ubicated() const
{
    return _ubicated;
}

void Villager::setUbicated(bool ubicated)
{
    _ubicated = ubicated;
}
Villager::Villager()
{
    _x = _y = 0;
    _ubicated = false;
}
