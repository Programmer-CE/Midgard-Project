#include "hpentity.h"


int HpEntity::magic() const
{
    return _magic;
}

void HpEntity::setMagic(int magic)
{
    _magic = magic;
}

int HpEntity::intelligence() const
{
    return _intelligence;
}

void HpEntity::setIntelligence(int intelligence)
{
    _intelligence = intelligence;
}

int HpEntity::defense() const
{
    return _defense;
}

void HpEntity::setDefense(int defense)
{
    _defense = defense;
}

int HpEntity::velocity() const
{
    return _velocity;
}

void HpEntity::setVelocity(int velocity)
{
    _velocity = velocity;
}

int HpEntity::attack() const
{
    return _attack;
}

void HpEntity::setAttack(int attack)
{
    _attack = attack;
}

int HpEntity::life() const
{
    return _life;
}

void HpEntity::setLife(int life)
{
    _life = life;
}

int HpEntity::maximunLife() const
{
    return _maximunLife;
}

void HpEntity::setMaximunLife(int maximunLife)
{
    _maximunLife = maximunLife;
}
HpEntity::HpEntity()
{
}
