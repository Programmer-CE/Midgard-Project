#ifndef PQNODE_H
#define PQNODE_H
#include<stdio.h>
#include <iostream>


template<class T>
class PQNode{
    PQNode<T> *_nextNodo;// proximo nodo
    T _data;// dato del nodo
public:
    /**
     * constrcutor de la clase PQNode
     * @brief PQNode
     * @param ndata
     * ndata es el puntero T* dato a agregar
     */
    PQNode(T* ndata);
    /**
     * contructor de la clas PQNode
     * @brief PQNode
     * @param ndata
     * ndata es el valor T, el dato a agregar
     */
    PQNode(T ndata);
    /**
      * destructor de la clase PQNode
      * @brief PQNode
      */
    ~PQNode();
    /**
     * @brief getData
     * @return T dato del nodo
     */
    T getData();
    /**
     * @brief getNext
     * @return PQNode<T>* del siguiente noso
     */
    PQNode<T>* getNext();
    /**
     * @brief setNext
     * @param nnode
     * define el siguente nodo
     */
    void setNext(PQNode<T>* nnode);
};



template<class T>
PQNode<T>::PQNode(T *ndata){
    if (ndata)_data=*ndata;
}

template<class T>
PQNode<T>::PQNode(T ndata){
    _data=ndata;
}


template<class T>
T PQNode<T>::getData(){
    return _data;
}


template<class T>
PQNode<T> *PQNode<T>::getNext(){
    return _nextNodo;
}

template<class T>
void PQNode<T>::setNext(PQNode<T> *nnode)
{
    _nextNodo= nnode;
}

template<class T>
PQNode<T>::~PQNode(){}




#endif // PQNODE_H
