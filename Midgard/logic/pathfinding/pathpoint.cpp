#include "pathpoint.h"


int PathPoint::y() const
{
    return _y;
}

void PathPoint::setY(int y)
{
    _y = y;
}
PathPoint::PathPoint()
{
    _y = _x = 0;
}

PathPoint::PathPoint(int pX, int pY)
{
    _y = pY;
    _x = pX;
}

int PathPoint::x() const
{
    return _x;
}

void PathPoint::setX(int x)
{
    _x = x;
}
