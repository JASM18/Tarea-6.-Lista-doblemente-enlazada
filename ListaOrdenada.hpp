#ifndef LISTAORDENADA_HPP_INCLUDED
#define LISTAORDENADA_HPP_INCLUDED

#include "ListaDoble.hpp"

class ListaOrdenada {
public:
    ListaOrdenada();

    ~ListaOrdenada();

    ListaOrdenada(const ListaOrdenada& other);

    ListaOrdenada& operator=(const ListaOrdenada& other);

private:

};

#include "ListaOrdenada.tpp"

#endif // LISTAORDENADA_HPP_INCLUDED
