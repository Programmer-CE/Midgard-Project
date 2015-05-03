#ifndef ASTARNODE_H
#define ASTARNODE_H
#include <iostream>
#include <math.h>


class ANode{

    int _xCurrentPosition;
    int _yCurrentPosition;
    int _distanceG;//distancia recorrida
    int _distanceF;// F=G+Heuristic

public:
    ANode(int xp, int yp, int d, int p);
    ~ANode();
    int getXPosition()const;
    int getYPosition()const;
    int getDistanceG()const;
    int getDistanceF()const;
    void updateDistanceF(const int & xDest, const int & yDest);
    void UpdateDistanceG(const int & i);
    const int & calculateHeuristic(const int & xDest, const int & yDest)const;//distancia faltante


};

#endif // ASTARNODE_H
