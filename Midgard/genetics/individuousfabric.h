#include "individuo.h"
#ifndef INDIVIDUOUSFABRIC_H
#define INDIVIDUOUSFABRIC_H

/**
 * @brief La clase IndividuousFabric se encarga de crear individuos
 */
class IndividuousFabric
{
public:
    /**
     * @brief create crea un individuo segun el tipo que se pida, claro esta este metodo debe
     * debe ser implementado por una clase hija
     * @param pType el tipo de dato que desea crearse
     * @return el nuevo individuo, claro esta, el individuo es creado en memoria dinamica y es
     * responsabilidad del programador liberar la memoria.
     */
    virtual Individuo *create(int pType) = 0;
};

#endif // INDIVIDUOUSFABRIC_H
