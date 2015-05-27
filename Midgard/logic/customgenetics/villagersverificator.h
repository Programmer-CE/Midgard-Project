#include "genetics/fitnessverificator.h"
#include "villager.h"

#include <qstring.h>
#ifndef VILLAGERSVERIFICATOR_H
#define VILLAGERSVERIFICATOR_H

class VillagersVerificator:public FitnessVerificator
{
    int _maxlife;
    int _attack;
    int _magic;
    int _defense;
    int _velocity;
    int _intelligence;
    int _blot;
    int _rune;
    int _superstition;
    int _vitalEnergy;
    int _maxAge;
    QString _breed;
    int _stage;
public:
    VillagersVerificator();
    int _Atkprom,_Defenseprom, _Blotprom;
    // FitnessVerificator interface
public:
    float verifyIndividuo(Individuo *);
    virtual ~VillagersVerificator(){

    }

    int maxlife() const;
    void setMaxlife(int maxlife);
    int attack() const;
    void setAttack(int attack);
    int defense() const;
    void setDefense(int defense);
    int intelligence() const;
    void setIntelligence(int intelligence);
    int blot() const;
    void setBlot(int blot);
    int rune() const;
    void setRune(int rune);
    int superstition() const;
    void setSuperstition(int superstition);
    int vitalEnergy() const;
    void setVitalEnergy(int vitalEnergy);
    int maxAge() const;
    void setMaxAge(int maxAge);
    int magic() const;
    void setMagic(int magic);
    int velocity() const;
    void setVelocity(int velocity);
    QString breed() const;
    void setBreed(const QString &breed);
    void nextStage();
};

#endif // VILLAGERSVERIFICATOR_H
