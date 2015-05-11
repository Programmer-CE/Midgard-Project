#ifndef PQNODE_H
#define PQNODE_H
#include<stdio.h>
#include <iostream>


template<class T>
class PQNode{
    PQNode<T> _nextNodo;
    T _data;
public:
    PQNode(T* ndata);
    PQNode(T ndata);
    ~PQNode();
    T getData();
    PQNode<T> getNext();
    void setNext(PQNode<T>* nnode);
};



#endif // PQNODE_H

template<class T>
PQNode<T>::PQNode(T *ndata){
    _data=*ndata;
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
PQNode<T> PQNode<T>:: getNext(){
    return *_nextNodo;
}

template<class T>
PQNode<T>::~PQNode(){}

