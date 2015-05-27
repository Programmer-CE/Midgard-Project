#include <string>
#ifndef INITIALSTATS_H
#define INITIALSTATS_H

class InitialStats
{
    int _maximunLife; /**< TODO */
    int _attack; /**< TODO */
    int _magic; /**< TODO */
    int _defense; /**< TODO */
    int _velocity; /**< TODO */
    int _intelligence; /**< TODO */
    std::string _breed;
    int _type;
    int _ageToDeath;
    int _age;
    int _vitalEnergy;
    int _blot;
    int _runes;
    int _superstition;
public:
    InitialStats();
    int life() const;
    void setLife(int life);
    int attack() const;
    void setAttack(int attack);
    int velocity() const;
    void setVelocity(int velocity);
    int defense() const;
    void setDefense(int defense);
    int intelligence() const;
    void setIntelligence(int intelligence);
    int magic() const;
    void setMagic(int magic);
    int maximunLife() const;
    void setMaximunLife(int maximunLife);
    int type() const;
    void setType(int type);
    int ageToDeath() const;
    void setAgeToDeath(int ageToDeath);
    int age() const;
    void setAge(int age);
    int vitalEnergy() const;
    void setVitalEnergy(int vitalEnergy);
    int blot() const;
    void setBlot(int blot);
    int runes() const;
    void setRunes(int runes);
    int superstition() const;
    void setSuperstition(int superstition);
};

#endif // INITIALSTATS_H
