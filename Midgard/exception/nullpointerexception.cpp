#include "nullpointerexception.h"

NullPointerException::NullPointerException()
{
}


char *NullPointerException::what() const
{
    return "puntero nulo";
}
