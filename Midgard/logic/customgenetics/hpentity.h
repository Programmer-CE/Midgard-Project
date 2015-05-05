#ifndef HPENTITY_H
#define HPENTITY_H

class HpEntity
{
    int _life;
    int _attack;
    int _velocity;
    int _defense;
    int _intelligence;
    int _magic;
    int _maximunLife;
public:
    HpEntity();
    virtual int magic() const;
    virtual void setMagic(int magic);
    virtual int intelligence() const;
    virtual void setIntelligence(int intelligence);
    virtual int defense() const;
    virtual void setDefense(int defense);
    virtual int velocity() const;
    virtual void setVelocity(int velocity);
    virtual int attack() const;
    virtual void setAttack(int attack);
    virtual int life() const;
    virtual void setLife(int life);
    virtual ~HpEntity(){}
    virtual int maximunLife() const;
    virtual void setMaximunLife(int maximunLife);
};

#endif // HPENTITY_H
