#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <stdlib.h>
#include "iostream"
#include "pqNode.h"

template<class T>
class PriorityQ{
private:
    PQNode<T>* _head;// primer valor
    int _lenght = 0;// largo de la lista
public:
    /**
      constructoe de la clase PriorityQ
     * @brief PriorityQ
     */
    PriorityQ();
    /**
      destructor de la clas PriorityQ
     * @brief ~PriorityQ
     */
    virtual ~PriorityQ(){}
    /**
     * @brief top
     * @return T del dato del primer nodo
     */
    T top();
    /**
     * @brief topPop
     * @return  T del dato del primer nodo y lo elimina
     */
    T topPop();
    /**
     * @brief pop
     * elimina el primer nodo
     */
    void pop();
    /**
     * @brief push
     * @param ndata
     * agrega eel valor T ndata a la lista
     */
    void push(T ndata);
    /**
     * @brief getLenght
     * @return int del largo del queue
     */
    int getLenght();
    /**
     * @brief isEmpty
     * @return bool si esta vacio
     */
    bool isEmpty();

};


template<class T>
PriorityQ<T>::PriorityQ(){_lenght = 0;_head = 0;}


template<class T>
T PriorityQ<T>::top(){
    if (!_head){
        throw isEmpty();
    }
    return _head->getData();
}

template<class T>
T PriorityQ<T>::topPop(){
    PQNode<T> *tmp=_head;
    pop();
    return tmp->getData();
}

template<class T>
void  PriorityQ<T>:: pop(){
    PQNode<T> *tmp = _head;
    _head=_head->getNext();
    delete tmp;
    _lenght--;
}

template<class T>
int PriorityQ<T>::getLenght(){
    return _lenght;
}

template<class T>
bool PriorityQ<T>::isEmpty(){
    return _lenght==0;
}

template<class T>
void PriorityQ<T>::push(T ndata) {
    PQNode<T> *newNode=new PQNode<T>(ndata);
    if (_lenght == 0){
        _head = newNode;
    }
    else{
        if (newNode->getData() < _head->getData()){
            newNode->setNext(_head);
            _head = newNode;
        }
        else{
            PQNode<T> *currentNode=_head->getNext();
            PQNode<T> *prevNode=_head;
            while(currentNode && currentNode->getData()< ndata){
                prevNode = currentNode;
                currentNode = currentNode->getNext();
            }

            prevNode->setNext(newNode);
            newNode->setNext(currentNode);
        }
    }
    _lenght++;

}
#endif // PRIORITYQUEUE_H
