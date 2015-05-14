#ifndef FINALSTATEVERIFICATOR_H
#define FINALSTATEVERIFICATOR_H

/**
 * @brief La clase FinalStateVerificator es la que se encarga de realizar el trabajo se verificar
 * si ya se ha llegado al final del algoritmo genetico claramente es una clase estructural y
 * debe implementarse los metodos a usar
 */
class FinalStateVerificator
{
public:
    /**
     * @brief verifyFinalStatus verifica si el agoritmo genetico llega a su fin, claro esta
     * es solo un metodo estructural, y debe ser implementado por el programador
     * en alguna clase hija
     */
    virtual bool verifyFinalStatus() = 0;
    virtual ~FinalStateVerificator(){}
};

#endif // FINALSTATEVERIFICATOR_H
