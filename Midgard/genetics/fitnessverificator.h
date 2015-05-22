#ifndef FITNESSVERIFICATOR_H
#define FITNESSVERIFICATOR_H


class Individuo;
/**
 * @brief Clase FitnessVerificator es la que se encarga de verificar el fitness de un
 * Individuo
 *
 */
class FitnessVerificator
{
public:
    /**
     * @brief Es el metodo con el cual se verifica el fitness de un Individuo
     *
     * @param pIndividuo es el individuo al cual se le aplicara la funcion de fitness
     * @return el fitness calculado
     */
    virtual float verifyIndividuo(Individuo *pIndividuo) =0;
};

#endif // FITNESSVERIFICATOR_H
