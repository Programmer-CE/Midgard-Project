#ifndef FITNESSVERIFICATOR_H
#define FITNESSVERIFICATOR_H


class Individuo;
class FitnessVerificator
{
public:
    virtual float verifyIndividuo(Individuo*) =0;
};

#endif // FITNESSVERIFICATOR_H
