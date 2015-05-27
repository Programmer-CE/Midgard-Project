#include "individuo.h"
#include "poblation.h"
#include "individuousfabric.h"
#ifndef CROSSER_H
#define CROSSER_H

/**
 * @brief La clase Crosser es la que se encarga de los cruzamientos claro esta
 * debe ser implementado el metodo de cruzamiento pues puede variar segun cada problema
 */
class Crosser
{
    IndividuousFabric *_fabric;
public:
    /**
     * @brief Crosser inicializa el puntero a la fabrica en cero
     */
    Crosser();
    /**
     * @brief cross realiza el cruzamiento claro esta debe ser implementado
     * para el cruzamiento se pasan los parametros necesarios, el individuo que desea reproducirse
     * la poblacion donde buscara un individuo con el cual reproducirse
     * @param pParent el individuo a cruzarse
     * @param pPoblation la poblacion donde se le buscara pareja al individuo
     * @return un nuevo individuo el cual se creara en memoria dinamica por lo cual se
     * requiere que el programador lo elimine despues en algun metodo ajeno o externo
     * a la clase Darwin o en el metodo
     * @link Darwin.removeIndividuous()
     */
    virtual Individuo* cross(Individuo *pParent, Individuo *pPoblation) = 0;
    /**
     * @brief ~Crosser liberador de memoria virtual
     */
    virtual ~Crosser(){delete _fabric;}
    /**
     * @brief setIndividuousFabric setea la fabrica que va a crear al individuo
     * @param pFabric el puntero a la fabrica
     */
    void setIndividuousFabric(IndividuousFabric * pFabric);
    /**
     * @brief getIndividuousFabric obtiene la fabrica
     * @return la fabrica de individuo
     */
    IndividuousFabric *getIndividuousFabric()const;
};

#endif // CROSSER_H
