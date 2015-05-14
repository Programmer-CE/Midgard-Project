#include "fitnessverificator.h"
#ifndef INDIVIDUO_H
#define INDIVIDUO_H

class Poblation;

/**
 * @brief La clase Individuo, es la que se encarga de abstraer a los individuos como tal
 * basicamente esta es una clase que abstrae los datos importantes de los individuos con respecto
 * a los algoritmos geneticos estos datos son el fitness y el control serial de los mismos
 * ademas es una clase que sigue el patron de disenio builder donde una de las partes
 * el fitness verificator es una parte ensamblable la cual puede cambiarse por cualquiera de
 * sus abstracciones
 */
class Individuo
{
    friend class Poblation;
    float _fitness;
    int _id;
    bool _isSelected;
    static int _Serial;
    FitnessVerificator *_fitnessverify;
public:
    /**
     * @brief Individuo Es el  constructor principal y basico de cada individuo seteando
     * su id al siguiente segun el serial, y setea el verificador de fitness a un puntero nulo
     */
    Individuo();
    /**
     * @brief fitness es el metodo que retorna al fitness mismo del indivduo
     * @return el fitness del individuo
     */
    float fitness() const;
    /**
     * @brief setFitness es el metodo que setea el fitness del objeto
     * @param fitness es el fitness del individuo
     */
    void setFitness(float fitness);
    /**
     * @brief getId obtiene el identificador del individuo
     * @return el identificador del individuo
     */
    int getId();

    /**
     * @brief fitnessverify obtiene una de las partes ensamblables del objeto el cual
     * es una abstraccion de cualquiera de los verificadores de fitness
     * @return el verificador de fitness del Individuo como tal
     */
    FitnessVerificator *fitnessverify() const;

    /**
     * @brief setFitnessverify setea el fitness el cual es ensamblable, se recomienda
     * que se cumpla el patron de disenio peso mosca para que todos los individuos de una
     * cierta poblacion compartan un mismo verificador de fitness para evitar memoryleaks.
     * @param fitnessverify el nuevo verificador de fitness del objeto
     */
    void setFitnessverify(FitnessVerificator *fitnessverify);
    virtual ~Individuo();
    bool isSelected() const;
    void setIsSelected(bool isSelected);
};

#endif // INDIVIDUO_H
