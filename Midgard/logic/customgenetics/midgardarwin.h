#include "genetics/darwin.h"
#include "genetics/poblation.h"
#ifndef MIDGARDARWIN_H
#define MIDGARDARWIN_H

class MidgarDarwin:public Darwin
{
public:
    MidgarDarwin(Crosser *pCrosser, FinalStateVerificator *pEndOfAlgorithm, Poblation *pPoblation, int pGenerationTop);

    // Darwin interface
protected:
    void removeIndividuous();
    float calculateTotalFitness();
    void select();
};

#endif // MIDGARDARWIN_H
