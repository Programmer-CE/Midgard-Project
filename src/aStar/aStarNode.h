#ifndef ASTARNODE_H
#define ASTARNODE_H
#include <iostream>
#include <math.h>


class ANode{

    int _xCurrentPosition;// posicion x actual
    int _yCurrentPosition;// posiciion y actual
    int _distanceG;//distancia recorrida
    int _distanceF;// F=G+Heuristic

public:
    /**contrutor de a clase ANode, inicializa valores en 0
     * @brief ANode
     */
    ANode(){_xCurrentPosition = 0; _yCurrentPosition = 0; _distanceF = 0; _distanceG = 0;}
    /**
     * @brief ANode
     * @param xpos
     * posicion en x
     * @param ypos
     * posision en y
     * @param G
     * distancia recorrida desde el inicio hasta la posicion actual
     * @param F
     * "costo" del proximo nodo hasta la meta.
     */
    ANode(int xpos, int ypos, int G, int F);
    /**
      *destructor de la clase ANode
      *@brief ~ANode
      */
    ~ANode();
    /**
     * @brief getXPosition
     * @return int de la posicion en x
     */
    int getXPosition()const;
    /**
     * @brief getYPosition
     * @return int de la posiccion en y
     */
    int getYPosition()const;
    /**
     * @brief getDistanceG
     * @return ind de la distancia recorrida
     */
    int getDistanceG()const;
    /**
     * @brief getDistanceF
     * @return int del costo de un nodo a la meta
     */
    int getDistanceF()const;
    /**
     * @brief updateDistanceF
     * @param xDest
     * actulualiza la posicion x del destino
     * @param yDest
     * actualiza la posicion y del detino
     */
    void updateDistanceF(const int & xDest, const int & yDest);
    void UpdateDistanceG(const int & i);
    /**
     * @brief calculateHeuristic
     * @param xDest
     * @param yDest
     * @return
     */
    const int & calculateHeuristic(const int & xDest, const int & yDest)const;//distancia faltante

    bool operator <(const ANode & othernode);
    bool operator >(const ANode & othernode);

};

#endif // ASTARNODE_H
