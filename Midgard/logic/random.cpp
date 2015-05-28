#include "random.h"
#include <cstdlib>
#include <ctime>
#include <SerialStream.h>
#include <unistd.h>
#include <iostream>

Queue<int> Random::randoms = Queue<int>();
int Random::_lenght = 0;

LibSerial::SerialStream serial_port("/dev/ttyACM1",std::ios_base::in | std::ios_base::out);
bool Random::_visited = false;

int Random::lenght()
{
    return _lenght;
}

void Random::setLenght(int lenght)
{
    _lenght = lenght;
}
Random::Random()
{
    if (!_visited){
        std::cout << "Visited" << std::endl;
        serial_port.SetBaudRate(LibSerial::SerialStreamBuf::BAUD_9600);
        serial_port.SetCharSize( LibSerial::SerialStreamBuf::CHAR_SIZE_8);
        sleep(10);
        Random::_visited = true;
        _lenght = 0;
    }
}

int Random::random()
{
    if (randoms.isEmpty()){
        return rand();
    }
    _lenght --;
    return Random::randoms.dequeue();
}

void Random::genRand()
{
    //std::cout << "rand" << std::endl;
    int toReturn= 0;
    serial_port >> readElemente;//lee el primer elemento
        readComparable=readElemente;//coloca el valor que sera para los 0

    for(int i = 0; i < 2*sizeof(int); i++){
        serial_port >> readElemente;

        if (readElemente==readComparable){//si el vaor es igual readComprable agrega un  0
            toReturn  = toReturn << 1;

        }
        else{//si el valor no corresponde al de readCompareble agrega un 1 1
            toReturn  =toReturn << 1;
            toReturn++;
        }
    }
    _lenght++;
    randoms.enqueue(std::abs(toReturn));// retorna el int%100, para que los valores este entre 0 y 100
}
