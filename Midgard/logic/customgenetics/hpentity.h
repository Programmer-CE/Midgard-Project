#ifndef HPENTITY_H
#define HPENTITY_H

/**
 * @brief Clase HpEntity es la clase que se encarga de representar a una entidad con
 * estadisticas como lo son las la vida, ataque, velocidad, entre otras caracteristicas
 *
 */
class HpEntity
{
    int _life; /**< TODO */
    int _attack; /**< TODO */
    int _velocity; /**< TODO */
    int _defense; /**< TODO */
    int _intelligence; /**< TODO */
    int _magic; /**< TODO */
    int _maximunLife; /**< TODO */
public:
    /**
     * @brief
     *
     */
    HpEntity();
    /**
     * @brief
     *
     * @return int
     */
    virtual int magic() const;
    /**
     * @brief
     *
     * @param magic
     */
    virtual void setMagic(int magic);
    /**
     * @brief
     *
     * @return int
     */
    virtual int intelligence() const;
    /**
     * @brief
     *
     * @param intelligence
     */
    virtual void setIntelligence(int intelligence);
    /**
     * @brief
     *
     * @return int
     */
    virtual int defense() const;
    /**
     * @brief
     *
     * @param defense
     */
    virtual void setDefense(int defense);
    /**
     * @brief
     *
     * @return int
     */
    virtual int velocity() const;
    /**
     * @brief
     *
     * @param velocity
     */
    virtual void setVelocity(int velocity);
    /**
     * @brief
     *
     * @return int
     */
    virtual int attack() const;
    /**
     * @brief
     *
     * @param attack
     */
    virtual void setAttack(int attack);
    /**
     * @brief
     *
     * @return int
     */
    virtual int life() const;
    /**
     * @brief
     *
     * @param life
     */
    virtual void setLife(int life);
    /**
     * @brief
     *
     */
    virtual ~HpEntity(){}
    /**
     * @brief
     *
     * @return int
     */
    virtual int maximunLife() const;
    /**
     * @brief
     *
     * @param maximunLife
     */
    virtual void setMaximunLife(int maximunLife);
};

#endif // HPENTITY_H
