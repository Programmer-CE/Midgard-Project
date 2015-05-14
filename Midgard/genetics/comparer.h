#ifndef COMPARER_H
#define COMPARER_H


template<class E>
/**
 * @brief La clase Comparer es una clase que permie comparar punteros que tengan el metodo
 * int getId(). Generalmente se usa con las listas del paquete de listas cppdatastructure
 *  que puede encontrarse en
 * @link https://github.com/crisferlop/CPPDatastructure
 */
class Comparer
{
    E* _data;
public:
    /**
     * @brief Comparer metodo para que pueda usarse en las listas
     */
    Comparer();
    /**
     * @brief Comparer es el metodo incial que permite asignar el dato
     * @param pdata el dato a comparar
     */
    Comparer(E* pdata);
    /**
     * @brief getData obtiene el dato que compara
     * @return el dato que compara
     */
    E *getData();
    /**
     * @brief operator < es el operardor de comparacion si el dato que llama al operador
     * es menor que el dato del parametro entonces se retorna true en otro caso
     * se retorna false
     * @param toCompare el dato con el que piensa compararse
     * @return true si el dato es menor false si no es asi
     */
    bool operator<(const Comparer<E> &toCompare);
    /**
     * @brief operator > es el operardor de comparacion si el dato que llama al operador
     * es mayor que el dato del parametro entonces se retorna true en otro caso
     * se retorna false
     * @param toCompare el dato con el que piensa compararse
     * @return true si el dato es mayor false si no es asi
     */
    bool operator>(const Comparer<E> &toCompare);
    /**
     * @brief operator < es el operardor de comparacion si el dato que llama al operador
     * es diferente que el dato del parametro entonces se retorna true en otro caso
     * se retorna false
     * @param toCompare el dato con el que piensa compararse
     * @return true si el dato es diferente false si no es asi
     */
    bool operator!=(const Comparer<E> &toCompare);
};

template<class E>
Comparer<E>::Comparer(E* pdata)
{
    _data = pdata;
}

template<class E>
E *Comparer<E>::getData()
{
    return _data;
}

template<class E>
Comparer<E>::Comparer()
{
    _data = 0;
}



template<class E>
bool Comparer<E>::operator<(const Comparer<E> &toCompare)
{
    return *_data < *toCompare._data;
}
template<class E>
bool Comparer<E>::operator>(const Comparer<E> &toCompare)
{
    return *_data > *toCompare._data;
}
template<class E>
bool Comparer<E>::operator!=(const Comparer<E> &toCompare)
{
    return *_data != *toCompare._data;
}

#endif // COMPARER_H
