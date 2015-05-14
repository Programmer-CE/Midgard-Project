#include "hpentity.h"
#include "genetics/individuo.h"
#include <string>
#include <iostream>
#ifndef VILLAGER_H
#define VILLAGER_H


using namespace std;
class Villager:public Individuo,public HpEntity
{
    int _ageToDeath;
    int _age;
    int _experience;
    int _vitalEnergy;
    int _blot;
    int _runes;
    int _superstition;
    // true si es hombre false si es mujer
    bool _gender;
    int _poblationId;
    string _breed;
    int _type;
    int _x;
    int _y;
public:
    Villager();
    int ageToDeath() const;
    void setAgeToDeath(int ageToDeath);
    int age() const;
    void setAge(int age);
    int experience() const;
    void setExperience(int experience);
    int vitalEnergy() const;
    void setVitalEnergy(int vitalEnergy);
    int blot() const;
    void setBlot(int blot);
    int runes() const;
    void setRunes(int runes);
    int superstition() const;
    void setSuperstition(int superstition);
    bool gender() const;
    void setGender(bool gender);
    int poblationId() const;
    void setPoblationId(int poblationId);
    string breed() const;
    void setBreed(const string &breed);
    int x() const;
    void setX(int x);
    int y() const;
    void setY(int y);
    virtual ~Villager(){}
    int type() const;
    void setType(int type);
};

#endif // VILLAGER_H
