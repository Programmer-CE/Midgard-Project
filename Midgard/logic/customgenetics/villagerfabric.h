#ifndef VILLAGERFABRIC_H
#define VILLAGERFABRIC_H
#include "genetics/individuousfabric.h"
#include "villager.h"
#include "villagersverificator.h"
class VillagerFabric:public IndividuousFabric
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
    VillagerFabric();
    VillagerFabric(VillagersVerificator *pVerificator);
    VillagersVerificator *verificator;


    // IndividuousFabric interface
public:
    virtual Villager *create(int pType);
    int maximunLife() const;
    void setMaximunLife(int maximunLife);
    int attack() const;
    void setAttack(int attack);
    int magic() const;
    void setMagic(int magic);
    int defense() const;
    void setDefense(int defense);
    int velocity() const;
    void setVelocity(int velocity);
    int intelligence() const;
    void setIntelligence(int intelligence);
    std::string breed() const;
    void setBreed(const std::string &breed);
    int type() const;
    void setType(int type);
    int vitalEnergy() const;
    void setVitalEnergy(int vitalEnergy);
    int blot() const;
    void setBlot(int blot);
    int runes() const;
    void setRunes(int runes);
    int superstition() const;
    void setSuperstition(int superstition);
    VillagersVerificator *getVerificator() const;
    void setVerificator(VillagersVerificator *value);
    //retorna una instancia nueva memoria dinamica
    VillagerFabric *clone();
};



#endif // VILLAGERFABRIC_H
