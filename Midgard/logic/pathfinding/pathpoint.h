#ifndef PATHPOINT_H
#define PATHPOINT_H

class PathPoint
{
    int _x;
    int _y;
public:
    PathPoint();
    PathPoint(int pX,int pY);
    int x() const;
    void setX(int x);
    int y() const;
    void setY(int y);
};

#endif // PATHPOINT_H
