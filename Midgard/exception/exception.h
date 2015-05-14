#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
public:
    Exception();
    virtual char* what()const = 0;
};

#endif // EXCEPTION_H
