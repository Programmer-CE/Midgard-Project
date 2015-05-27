#include "initialstats.h"
#include "logic/customgenetics/villagerfabric.h"
#include "logic/customgenetics/villagersverificator.h"
#include <qstring.h>
#include "list/DoubleList.h"
#ifndef RAZA_H
#define RAZA_H

class Raza
{
    UDoubleList<VillagersVerificator *>_Verificators;
    UDoubleList<VillagerFabric *>_Fabrics;
    QString name;
public:
    Raza();
    QString getName() const;
    void setName(const QString &value);
    void addVillagerVerificator(VillagersVerificator *);
    void addVillagerFabric(VillagerFabric *);
    VillagerFabric *getFrabric(int pIndex);
    VillagersVerificator *getVerificator(int pIndex);
    int lenghtFabric();
    int lenghtVerificator();
    virtual ~Raza();
};

#endif // RAZA_H
