#include "finalstateverificator.h"
#include "poblation.h"
#include "crosser.h"
#ifndef DARWIN_H
#define DARWIN_H

/**
 * @brief La clase Darwin es la clase que se encarga de la evolucion de los individuos,
 * calculando su fitness, reproduciendolos, haciendo control de poblacion, seleccionando
 * quienes se reproduncen.
 */
class Darwin
{

public:
    /**
     * @brief Darwin Es el constructor lo unico que hace es setear datos
     * @param pCrosser es un puntero al objeto de cruzamiento
     * @param pEndOfAlgorithm es el que se encarga de verificar el final del algoritmo
     * @param pPoblation es la poblacion inicial creada por el usuario
     * @param pGenerationTop es la cantidad maxima de generaciones a crear por el metodo
     * Darwin.evolve() esto no cuenta para el metodo Darwin.evolveStep()
     * @throw NullPointerException si alguno de los datos es nulo
     */
    Darwin(Crosser * pCrosser, FinalStateVerificator *pEndOfAlgorithm, Poblation *pPoblation, int pGenerationTop);
    /**
     * @brief evolve es un bucle que genera Individuos los cruza (Crosser), hasta llegar a
     * un maximo de generaciones o hasta que la verificacion termine
     */
    virtual void evolve();
    /**
     * @brief evolveStep hace un paso de evolucion o sea una sola generacion de datos.
     */
    virtual void evolveStep();
    /**
     * @brief getPoblation obtiene la poblacion de individuos
     * @return
     */
    virtual Poblation *getPoblation();
    /**
     * @brief ~Darwin
     */
    virtual ~Darwin();
protected:
    Crosser *_crosser;
    FinalStateVerificator *_finalStateVerificator;
    Poblation *_poblacion;
    int _generationTop;
    int _newGenerationLenght;
    float _fitness;
    /**
     * @brief removeIndividuous remueve los individuos que son malos de la antigua generacion,
     * debe de ser implementado.
     */
    virtual void removeIndividuous() = 0;
    /**
     * @brief calculateTotalFitness calcula el fitness total y el de cada individuo, debe
     * ser implementado
     * @return
     */
    virtual float calculateTotalFitness() = 0;


    /**
     * @brief searchIndividuoToMatch, busca un individuo para copular
     * @param pParent es el individuo al cual se le buscara pareja
     * @return la pareja del individuo
     */
    virtual Individuo *searchIndividuoToMatch(Individuo *pParent) = 0;

    virtual void select() = 0;
};

#endif // DARWIN_H
