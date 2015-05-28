#ifndef RANDOM_H
#define RANDOM_H
#include "controlStructure/Queue.h"
class Random
{
    static bool _visited;
    char readComparable;//primer valor leido, equivale a un 0
    char readElemente;// valor leido
    static Queue<int> randoms;
    static int _lenght;
public:
    Random();
    virtual int random();
    void genRand();
    static int lenght();
    static void setLenght(int lenght);
};

#endif // RANDOM_H
