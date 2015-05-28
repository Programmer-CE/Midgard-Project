#ifndef ASTARPATHFINDER_H
#define ASTARPATHFINDER_H
#include <iostream>
#include <string>
#include "aStarNode.h"
#include "PriorityQueue.h"
#include "pqNode.h"
#include "controlStructure/Queue.h"
#include "pathpoint.h"


/*
const int n=60; // dimencion horizontal
const int m=60; // dimencion vertical
bool map[n][m];
bool ClosedANodes[n][m]; // mapa de nodos a los que no se puede ir
bool OpenANodes[n][m]; // mapa dde nodos a los que puede ir
int directionMap[n][m]; // mapa de direcciones, almacena los movimientos
*/

class APathFinder{
    PriorityQ<ANode> pQueue[2];
    int QueueIndex; // para diferenciar entre los queue
    ANode* ANodoTmp1;
    ANode* AChildNode;
    int x, y, xDirectionx, yDirectiony;//para manejar los movimientos por el los mapas
    char plusChar;// char para crear el path
    int directionsX[8]={1, 1, 0, -1, -1, -1, 0, 1};//para generar todos las posibles convinaciones de movimientos xy
    int directionsY[8]={0, 1, 1, 1, 0, -1, -1, -1};
    int n=60; // dimencion horizontal
    int m=60; // dimencion vertical
    bool **map;
    bool **ClosedANodes; // mapa de nodos a los que no se puede ir
    bool **OpenANodes; // mapa dde nodos a los que puede ir
    int **directionMap; // mapa de direcciones, almacena los movimientos
    /**
      elimina el contenido de los mapas de nodos libres y nodos ya vistos
     * @brief clearMaps
     */
    void clearMaps();
    template <class E>
    E **generateMatrix();
public:
    /**
      constructor de la clase APathFinder, inicializa el QueueIndex=0
     * @brief APathFinder
     */
    APathFinder(bool** pMatriz, int pWidth, int pHeight);
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
    Queue<PathPoint> *PathFinder( const int & xInitialCordenate, const int & yInitialCordenate,
                            const int & xGoalCordenate, const int & yGoalCordenate);
    /**
      destructor de la clase APathFinder
     * @brief ~APathFinder
     */
    virtual ~APathFinder(){}
};


template <class E>
E **APathFinder::generateMatrix()
{
    E **tmp = new E*[n];
    for (int x =0; x < n; x++){
        tmp[x] = new E[m];
        for (int y=0; y < m; y++){
            tmp[x][y] = 0;
        }
    }
    return tmp;
}
#endif // ASTARPATHFINDER_H
