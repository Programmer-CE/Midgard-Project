#include "exception.h"
#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

class NullPointerException:public Exception
{
public:
    NullPointerException();

    // Exception interface
public:
    char *what() const;
};

#endif // NULLPOINTEREXCEPTION_H
