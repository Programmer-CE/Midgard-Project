#include "raza.h"
#include "list/DoubleList.h"
#ifndef XMLCONSTANST_H
#define XMLCONSTANST_H

class XMLConstanst
{
    UDoubleList<Raza*> _razas;
    QString _name;
    QString _nameOfMap;
    int _barbarianEddaDuration;
    int _superstitionEddaDuration;
    int _scienceEddaDuration;
    int _supremacyEddaDuration;
    int _unionEddaDuration;
    int _initialPoblation;
    int _mapWidth;
    int _mapHeight;
public:
    XMLConstanst();
    Raza *getRazaByName(QString pName);
    Raza *getRazaByIndex(int pIndex);
    int getRazaLenght();
    void addRaza(Raza*);
    virtual ~XMLConstanst();
    QString name() const;
    void setName(const QString &name);
    int barbarianEddaDuration() const;
    void setBarbarianEddaDuration(int barbarianEddaDuration);
    int superstitionEddaDuration() const;
    void setSuperstitionEddaDuration(int superstitionEddaDuration);
    int scienceEddaDuration() const;
    void setScienceEddaDuration(int scienceEddaDuration);
    int supremacyEddaDuration() const;
    void setSupremacyEddaDuration(int supremacyEddaDuration);
    int unionEddaDuration() const;
    void setUnionEddaDuration(int unionEddaDuration);
    int initialPoblation() const;
    void setInitialPoblation(int initialPoblation);
    QString nameOfMap() const;
    void setNameOfMap(const QString &nameOfMap);
    int mapWidth() const;
    void setMapWidth(int mapWidth);
    int mapHeight() const;
    void setMapHeight(int mapHeight);
};

#endif // XMLCONSTANST_H
