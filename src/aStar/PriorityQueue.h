#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <stdlib.h>
#include <iostream>
#include <pqNode.h>

template<class T>
class PriorityQ{
private:
    PQNode<T>* _head;
    int _lenght;
public:
    PriorityQ();
    ~PriorityQ();
    T top();
    T topPop();
    void pop();
    void push(T* ndata);
    int getLenght();
    bool isEmpty();

};

#endif // PRIORITYQUEUE_H




template<class T>
T PriorityQ<T>::top(){
    return *_head;


}

template<class T>
T PriorityQ<T>::topPop(){
    PQNode<T> *tmp=_head;
    pop();
    return *tmp;
}

template<class T>
void  PriorityQ<T>:: pop(){
    this->_head=this->_head->getNext();





}

template<class T>
int PriorityQ<T>::getLenght(){
    return this->_lenght;
}

template<class T>
bool PriorityQ<T>::isEmpty(){
    return this->_lenght=0;
}

template<class T>
void PriorityQ<T>::push(T* ndata) {
    PQNode<T> newNode=new PQNode(ndata);
    if (_lenght==0)
        _head = newNode;
    else{

        PQNode<T> *tmpNodeAct=_head;
        PQNode<T> *tmpNodePrev=nullptr;
        for (int i = 0; i < _lenght; ++i) {
            if (*(tmpNodeAct->getData().getDistanceF())<*(newNode->getData().getDistanceF())){
                if (tmpNodePrev == nullptr) {
                    newNode->next = _head;
                    _head = newNode;
                }
                else{
                    tmpNodePrev->next = newNode;
                    newNode->next = tmpNodeAct;
                }
                break;
            }
            tmpNodePrev = tmpNodeAct;
            tmpNodeAct = tmpNodeAct->getNextNode();
        }
        tmpNodePrev->next=newNode;
    }
    _lenght++;
}


