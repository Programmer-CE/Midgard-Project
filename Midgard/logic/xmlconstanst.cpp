#include "xmlconstanst.h"


QString XMLConstanst::name() const
{
    return _name;
}

void XMLConstanst::setName(const QString &name)
{
    _name = name;
}


int XMLConstanst::barbarianEddaDuration() const
{
    return _barbarianEddaDuration;
}

void XMLConstanst::setBarbarianEddaDuration(int barbarianEddaDuration)
{
    _barbarianEddaDuration = barbarianEddaDuration;
}

int XMLConstanst::superstitionEddaDuration() const
{
    return _superstitionEddaDuration;
}

void XMLConstanst::setSuperstitionEddaDuration(int superstitionEddaDuration)
{
    _superstitionEddaDuration = superstitionEddaDuration;
}

int XMLConstanst::scienceEddaDuration() const
{
    return _scienceEddaDuration;
}

void XMLConstanst::setScienceEddaDuration(int scienceEddaDuration)
{
    _scienceEddaDuration = scienceEddaDuration;
}

int XMLConstanst::supremacyEddaDuration() const
{
    return _supremacyEddaDuration;
}

void XMLConstanst::setSupremacyEddaDuration(int supremacyEddaDuration)
{
    _supremacyEddaDuration = supremacyEddaDuration;
}

int XMLConstanst::unionEddaDuration() const
{
    return _unionEddaDuration;
}

void XMLConstanst::setUnionEddaDuration(int unionEddaDuration)
{
    _unionEddaDuration = unionEddaDuration;
}

int XMLConstanst::initialPoblation() const
{
    return _initialPoblation;
}

void XMLConstanst::setInitialPoblation(int initialPoblation)
{
    _initialPoblation = initialPoblation;
}

QString XMLConstanst::nameOfMap() const
{
    return _nameOfMap;
}

void XMLConstanst::setNameOfMap(const QString &nameOfMap)
{
    _nameOfMap = nameOfMap;
}

int XMLConstanst::mapWidth() const
{
    return _mapWidth;
}

void XMLConstanst::setMapWidth(int mapWidth)
{
    _mapWidth = mapWidth;
}

int XMLConstanst::mapHeight() const
{
    return _mapHeight;
}

void XMLConstanst::setMapHeight(int mapHeight)
{
    _mapHeight = mapHeight;
}
XMLConstanst::XMLConstanst()
{
    
}

Raza *XMLConstanst::getRazaByName(QString pName)
{
    int x = 0;
    for (; x < _razas.getLenght(); x++){
        if (pName.compare(_razas.get(x)->getName()) == 0)break;
    }
    if (x == _razas.getLenght())return 0;
    return _razas.get(x);
}

Raza *XMLConstanst::getRazaByIndex(int pIndex)
{
    if (pIndex<0 || pIndex >= _razas.getLenght()) return 0;
    return _razas.get(pIndex);
}

int XMLConstanst::getRazaLenght()
{
    return _razas.getLenght();
}

void XMLConstanst::addRaza(Raza *pRaza)
{
    _razas.add(pRaza);
}

XMLConstanst::~XMLConstanst()
{
    while(!_razas.isEmpty())
    {
        Raza * element = _razas.get(0);
        delete element;
        _razas.remove(0);
    }
}
