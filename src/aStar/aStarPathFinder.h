#ifndef ASTARPATHFINDER_H
#define ASTARPATHFINDER_H
#include <iostream>
#include <string>
#include <math.h>
#include "aStarNode.h"
#include "ordinateList/doublelist.h"


const int n=60; // horizontal size of the map
const int m=60; // vertical size size of the map
int map[n][m];
int ClosedANodes[n][m]; // mapa de nodos ocupados
int OpenANodes[n][m]; // map dde nodos libres
int directionMap[n][m]; // map of directions
int directionsX[8]={1, 1, 0, -1, -1, -1, 0, 1};
int directionsY[8]={0, 1, 1, 1, 0, -1, -1, -1};



class APathFinder{
    DoubleList<ANode> pQueue[2];
    int QueueIndex; // pq index
    ANode* ANodoTmp1;
    ANode* AChildNode;
    int x, y, xdx, ydy;
    char c;
    void clearMaps();


public:
    APathFinder();
    ~APathFinder();
    std::string PathFinder( const int & xInitialCordenate, const int & yInitialCordenate,
                            const int & xGoalCordenate, const int & yGoalCordenate);
};
#endif // ASTARPATHFINDER_H
