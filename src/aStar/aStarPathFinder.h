#ifndef ASTARPATHFINDER_H
#define ASTARPATHFINDER_H
#include <iostream>
#include <string>
#include <math.h>
#include "aStarNode.h"
#include "PriorityQueue.h"
#include "pqNode.h"


const int n=60; // dimencion horizontal
const int m=60; // dimencion vertical
int map[n][m];
int ClosedANodes[n][m]; // mapa de nodos a los que no se puede ir
int OpenANodes[n][m]; // mapa dde nodos a los que puede ir
int directionMap[n][m]; // mapa de direcciones
int directionsX[8]={1, 1, 0, -1, -1, -1, 0, 1};
int directionsY[8]={0, 1, 1, 1, 0, -1, -1, -1};



class APathFinder{
    PriorityQ<ANode> pQueue[2];
    int QueueIndex; // para diferenciar entre los queue
    ANode* ANodoTmp1;
    ANode* AChildNode;
    int x, y, xdx, ydy;
    char plusChar;
    /**
      elimina el contenido de los mapas de nodos libres y nodos ya vistos
     * @brief clearMaps
     */
    void clearMaps();


public:
    /**
      constructor de la clase APathFinder, inicializa el QueueIndex=0
     * @brief APathFinder
     */
    APathFinder();
    /**
     * @brief PathFinder
     * @param xInitialCordenate
     * cordenada  x en al que se encuentra
     * @param yInitialCordenate
     * cordenada y en la que se encuentra
     * @param xGoalCordenate
     * cordena x a la que quiere llegar
     * @param yGoalCordenate
     * cordena y a la que se quiere legar
     * @return String
     * retorna un string con el path a recorrer
     */
    std::string PathFinder( const int & xInitialCordenate, const int & yInitialCordenate,
                            const int & xGoalCordenate, const int & yGoalCordenate);
    /**
      destructor de la clase APathFinder
     * @brief ~APathFinder
     */
    virtual ~APathFinder(){}
};
#endif // ASTARPATHFINDER_H
