#include <iostream>
#include <string>
#include "aStarPathFinder.h"
#include "aStarNode.h"
#include "PriorityQueue.h"
#include "pqNode.h"


APathFinder::APathFinder(bool **pMatriz, int pWidth, int pHeight){
    QueueIndex=0;
    x = y = xDirectionx = yDirectiony= 0;
    map = pMatriz;
    n =  pHeight;
    m = pWidth;
    directionMap = generateMatrix<int>();
    OpenANodes = generateMatrix<bool>();
    ClosedANodes = generateMatrix<bool>();

}


// A* algoritmo (pathfinder)
Queue<PathPoint> *APathFinder::PathFinder( const int & xInitialCordenate, const int & yInitialCordenate,
                                     const int & xGoalCordenate, const int & yGoalCordenate){

    clearMaps();//resetea los mapas limpio y usado

    //se crea el nodo referente al inicio
    ANodoTmp1=new ANode(xInitialCordenate, yInitialCordenate, 0, 0);// de crea un todo tmp
    ANodoTmp1->updateDistanceF(xGoalCordenate, yGoalCordenate);// se actualizan su peso al destino
    pQueue[QueueIndex].push(*ANodoTmp1);//se agrega a la lista de nodos libres
    OpenANodes[x][y]=ANodoTmp1->getDistanceF(); //se agrega al map de nodos libres
    Queue<PathPoint> *toReturn = new Queue<PathPoint>();
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
            // se genera el path siguendo direcciones de atras hasta llegar a las cordenadas iniciales
            while(!(x==xInitialCordenate && y==yInitialCordenate))
            {
                int newDirect=directionMap[x][y];//se recuperan los moviemintos guardados

                //////////////////////////

                //poner lo de llenar el nodo con la cordenadas, cambiar los returns por la lista
                //de movimientos a realizar,

                //////////////////////////
                //se actualiza la variable xy para navegar en el direcctionMap
                //std::cout << "x: " << x << " y: " << y<< std::endl;
                x+=directionsX[newDirect];
                y+=directionsY[newDirect];
                toReturn->enqueue(PathPoint(x,y));
            }

            delete (ANodoTmp1);// se elimina el nodo temporal 1
            while(pQueue[QueueIndex].getLenght()!=0){// vacia lo restante en la lista
                pQueue[QueueIndex].pop();//elimina el primero
            }
            toReturn->enqueue(PathPoint(xGoalCordenate,yGoalCordenate));
            return toReturn;//retorna el path
        }
        // evalua los movimientos rectos y en diagonal
        for(int i=0;i<8;i++){// 8 de 8 posibilidades
            xDirectionx=x+directionsX[i];
            yDirectiony=y+directionsY[i];

            if(!(xDirectionx<0 || xDirectionx>n-1 || yDirectiony<0 || yDirectiony>m-1 || map[xDirectionx][yDirectiony]==1
                 || ClosedANodes[xDirectionx][yDirectiony]==1))
            {
                // genera los nodos hijos
                AChildNode=new ANode(xDirectionx,yDirectiony,ANodoTmp1->getDistanceG(),ANodoTmp1->getDistanceF());
                AChildNode->UpdateDistanceG(x);
                AChildNode->updateDistanceF(xGoalCordenate, yGoalCordenate);

                // si no esta en el map de possiciones libres lo agrega
                if(OpenANodes[xDirectionx][yDirectiony]==0)
                {
                    OpenANodes[xDirectionx][yDirectiony]=AChildNode->getDistanceF();
                    pQueue[QueueIndex].push(*AChildNode);// agrega al nodo hijo
                    // posicion del ANode padre
                    directionMap[xDirectionx][yDirectiony]=(i+8/2)%8;// 8 por que son 8 posibles direcciones
                }
                else if(OpenANodes[xDirectionx][yDirectiony]>AChildNode->getDistanceF())
                {
                    //actializa la F
                    OpenANodes[xDirectionx][yDirectiony]=AChildNode->getDistanceF();
                    // actualiza informacion del ANode padre
                    directionMap[xDirectionx][yDirectiony]=(i+8/2)%8;

                    // reemplaza el nodo
                    // pasando todo de una cola a otra
                    // ignorando el nodo que se reemplazara
                    while(!(pQueue[QueueIndex].top().getXPosition()==xDirectionx && pQueue[QueueIndex].top().getYPosition()==yDirectiony))
                    {
                        std::cout << "problems" << std::endl;
                        pQueue[1-QueueIndex].push(pQueue[QueueIndex].topPop());// pasa todo de un queue a otro
                    }
                    pQueue[QueueIndex].pop(); //se elimina el nodo deseado

                    // se vacia la cola mas larga a la mas pequeña
                    if(pQueue[QueueIndex].getLenght()>pQueue[1-QueueIndex].getLenght()){
                        QueueIndex=1-QueueIndex;
                    }

                    while(pQueue[QueueIndex].getLenght()!=0)// vacia el queue
                    {
                        pQueue[1-QueueIndex].push(pQueue[QueueIndex].top());
                        pQueue[QueueIndex].pop();
                    }
                    //como son dos queue la mejor opcion es meverse entre ellos con 1-el valor actual
                    QueueIndex=1-QueueIndex;
                    pQueue[QueueIndex].push(*AChildNode); // se agreaga el ANodo que es la mejor opcion
                }
                else delete(AChildNode);
            }
        }
        delete(ANodoTmp1);//elimina
    }
    return toReturn;// no se encontro path corecto al destino retorna una lista vacia, comprobar por fuera
}

void APathFinder::clearMaps(){// limpia y restablece valores default

    // vacia los mapas de nodos libres y usados, 0 en todas las entradas.
    for(int j=0;j<m;j++)//recorre en y
    {
        for(int i=0;i<n;i++)//recorre en x
        {
            OpenANodes[i][j]=0;
            ClosedANodes[i][j]=0;

        }
    }
}

/**

bool operator <(PQNode<ANode> a, PQNode<ANode> b){
    return a.getData().getDistanceF()<b.getData().getDistanceF();
}
*/
