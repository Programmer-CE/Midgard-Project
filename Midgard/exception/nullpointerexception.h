#include "exception.h"
#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H

/**
 * @brief Clase NullPointerException. Es la clase que representa un error al ingresar a un
 * puntero nulo
 *
 */
class NullPointerException:public Exception
{
public:
    /**
     * @brief Es el constructor por defecto
     *
     */
    NullPointerException();

    // Exception interface
public:
    /**
     * @brief Es el metodo que retorna en lenguaje natural una cadena de caracteres con
     * el error
     *
     * @return cadena de caracteres con el error en lenguaje natural
     */
    char *what() const;
};

#endif // NULLPOINTEREXCEPTION_H
