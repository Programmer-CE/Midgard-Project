#include "genetics/darwin.h"
#include "genetics/poblation.h"
#ifndef MIDGARDARWIN_H
#define MIDGARDARWIN_H

class MidgarDarwin:public Darwin
{
    void sortPoblationByFitness();
public:
    MidgarDarwin(Crosser *pCrosser, FinalStateVerificator *pEndOfAlgorithm, Poblation *pPoblation, int pGenerationTop);
    float promedio;
    float atkprom,defprom,blotprom;
    // Darwin interface
protected:
    void removeIndividuous();
    float calculateTotalFitness();
    void select();
    Individuo *searchIndividuoToMatch(Individuo *pParent);
};

#endif // MIDGARDARWIN_H
