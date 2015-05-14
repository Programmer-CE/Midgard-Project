#include "random.h"
#include <cstdlib>
#include <ctime>
Random::Random()
{
}

int Random::random()
{
    return rand();
}
