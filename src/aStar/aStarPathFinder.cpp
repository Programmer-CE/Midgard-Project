#include <iostream>
#include <string>
#include <math.h>
#include "aStarPathFinder.h"
#include "aStarNode.h"
#include "PriorityQueue.h"
#include <pqNode.h>


APathFinder::APathFinder(){
    QueueIndex=0;
}


// A* algorithm (pathfinder)
std::string APathFinder::PathFinder( const int & xInitialCordenate, const int & yInitialCordenate,
                                     const int & xGoalCordenate, const int & yGoalCordenate){

    clearMaps();//resetea los mapas limpio y usado

    //se crea el nodo referente al inicio
    ANodoTmp1=new ANode(xInitialCordenate, yInitialCordenate, 0, 0);// de crea un todo tmp
    ANodoTmp1->updateDistanceF(xGoalCordenate, yGoalCordenate);// se actualizan su peso al destino
    pQueue[QueueIndex].push(*ANodoTmp1);//se agrega a la lista de nodos libres
    OpenANodes[x][y]=ANodoTmp1->getDistanceF(); //se agrega al map de nodos libres


    while(pQueue[QueueIndex].getLenght()!=0){// mientras el queue contenga elementos
        
        ANodoTmp1=new ANode(pQueue[QueueIndex].top().getXPosition(),pQueue[QueueIndex].top().getYPosition(),
                            pQueue[QueueIndex].top().getDistanceG(),pQueue[QueueIndex].top().getDistanceF());

        x=ANodoTmp1->getXPosition();//toma la posicion x del ANodoTmp1
        y=ANodoTmp1->getYPosition();//toma la posicion y del ANodoTmp1
        pQueue[QueueIndex].pop(); // se qeuita de la lista de nodos libres
        OpenANodes[x][y]=0;// se desmarca del map de nodos libres
        ClosedANodes[x][y]=1;//se marca en el map de nodos cerrados

        // condicion de parada al cuando ya se encuentra en el nodo final
        if(x==xGoalCordenate && y==yGoalCordenate)
        {
            // se genera el path siguendo direcciones
            std::string aStarPath="";
            while(!(x==xInitialCordenate && y==yInitialCordenate))
            {
                int j=directionMap[x][y];
                plusChar='0'+(j+8/2)%8;
                aStarPath=plusChar+aStarPath;
                x+=directionsX[j];
                y+=directionsY[j];
            }

            delete (ANodoTmp1);
            while(pQueue[QueueIndex].getLenght()!=0){// vacia lo restante en la lista
                pQueue[QueueIndex].pop();
            }
            return aStarPath;//retorna el path
        }

        // evalua los movimientos rectos y en diagonal
        for(int i=0;i<8;i++){// 8 de 8 posibilidades
            xdx=x+directionsX[i]; ydy=y+directionsY[i];

            if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || map[xdx][ydy]==1
                 || ClosedANodes[xdx][ydy]==1))
            {
                // genera los nodos hijos
                AChildNode=new ANode( xdx, ydy, ANodoTmp1->getDistanceG(),
                                      ANodoTmp1->getDistanceF());
                AChildNode->UpdateDistanceG(x);
                AChildNode->updateDistanceF(xGoalCordenate, yGoalCordenate);

                // si n o esta en el map de possiciones libres lo agrega
                if(OpenANodes[xdx][ydy]==0)
                {
                    OpenANodes[xdx][ydy]=AChildNode->getDistanceF();
                    pQueue[QueueIndex].push(*AChildNode);// agrega al nodo hijo
                    // posicion del ANode padre
                    directionMap[xdx][ydy]=(i+8/2)%8;// 8 por que son 8 posibles direcciones
                }
                else if(OpenANodes[xdx][ydy]>AChildNode->getDistanceF())
                {
                    //actializa la F
                    OpenANodes[xdx][ydy]=AChildNode->getDistanceF();
                    // actualiza informacion del ANode padre
                    directionMap[xdx][ydy]=(i+8/2)%8;

                    // reemplaza el nodo
                    // pasando todo de una cola a otra
                    // ignorando el nodo que se reemplazara
                    while(!(pQueue[QueueIndex].top().getXPosition()==xdx &&
                            pQueue[QueueIndex].top().getYPosition()==ydy))
                    {
                        pQueue[1-QueueIndex].push(pQueue[QueueIndex].top());
                        pQueue[QueueIndex].pop();
                    }
                    pQueue[QueueIndex].pop(); //se elimina el nodo deseado

                    // se vacia la cola mas larga a la mas pequeña
                    if(pQueue[QueueIndex].getLenght()>pQueue[1-QueueIndex].getLenght()){
                        QueueIndex=1-QueueIndex;
                    }

                    while(pQueue[QueueIndex].getLenght()!=0)
                    {
                        pQueue[1-QueueIndex].push(pQueue[QueueIndex].top());
                        pQueue[QueueIndex].pop();
                    }
                    QueueIndex=1-QueueIndex;
                    pQueue[QueueIndex].push(*AChildNode); // se agreaga el ANodo que es la mejor opcion
                }
                else delete(AChildNode);
            }
        }
        delete(ANodoTmp1);
    }
    return "";// no se encontro path corecto al destino
}

void APathFinder::clearMaps(){

    // vacia los mapas de nodos libres y usados
    for(int j=0;j<m;j++)//recorre en y
    {
        for(int i=0;i<n;i++)//recorre en x
        {
            ClosedANodes[i][j]=0;
            OpenANodes[i][j]=0;
        }
    }
}



