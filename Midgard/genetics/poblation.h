#include "individuo.h"
#include "comparer.h"
#include "ordinateList/doublelist.h"
#ifndef POBLATION_H
#define POBLATION_H


/**
 * @brief La clase Poblation, es una clase que solamente contiene a los Individuo
 * se encarga de regular el acceso a los mismos al eliminar, agregar obtener a los inviduos
 *
 */
class Poblation
{
    DoubleList<Comparer<Individuo> > *_poblation;
public:
    Poblation();
    void setDataList(DoubleList<Comparer<Individuo> > *pPoblation);
    DoubleList<Comparer<Individuo> > *getDataList();
    /**
     * @brief getIndividuousByIndex Obtiene un individuo en el indice citado
     * si el indice es incorrecto lanzara un puntero a nulo
     * @param pIndex es el indice de busqueda
     * @return retorna nulo si el indice es incorrecto, o sea esta fuera de rango
     * en el caso se que el indice sea correcto retorna un individuo
     */
    Individuo *getIndividuousByIndex(int pIndex);
    /**
     * @brief getIndividuousById Obtiene un individuo por el id citado
     * si el id es incorrecto lanzara un puntero a nulo
     * @param pId es el identificador de busqueda
     * @return retorna nulo si el id es incorrecto, o sea no se encontro en la
     * lista en el caso se que el id sea correcto retorna el individuo con el
     * individuo
     */
    Individuo *getIndividuousById(int pId);
    /**
     * @brief addIndividuous
     * @param pIndividuous
     * @return
     */
    void addIndividuous(Individuo* pIndividuous);
    /**
     * @brief removeIndividuousByIndex remueve un Individuo por el indice de busqueda
     * en el caso de que el indice de busqueda sea incorrecto retornara false
     * @param pIndex es el indice de busqueda
     * @return true si el Individuo se encontro y se borro false si esto no ocurre
     */
    bool removeIndividuousByIndex(int pIndex);
    /**
     * @brief removeIndividuousById remueve un Individuo por su id si el individuo
     * no se encuentra se retorna false
     * @param pId el identificador del Individuo
     * @return true si el Individuo se encontro y se borro false si esto no ocurre
     */
    bool removeIndividuousById(int pId);

    /**
     * @brief getLenght Obtiene la cantidad de individuos
     * @return la cantidad de individuos o sea el largo de la lista
     */
    int getLenght();
    /**
     * @brief getIterator retorna un iterador para los individuo
     * @return un iterador del individuo
     */
    IIterator<Comparer<Individuo> > *getIterator();
};

#endif // POBLATION_H
