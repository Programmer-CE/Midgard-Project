#ifndef EXCEPTION_H
#define EXCEPTION_H

/**
 * @brief Clase Exception es la abstraccion de un error para ser lanzado
 *
 */
class Exception
{
public:
    /**
     * @brief Es el constructor por defecto
     *
     */
    Exception();
    /**
     * @brief what Retorna una cadena de caracteres con el error en lenguaje natural
     *
     * @return una cadena de caracteres que puede buen ser impresa
     */
    virtual char* what()const = 0;
};

#endif // EXCEPTION_H
