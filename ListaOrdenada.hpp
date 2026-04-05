#ifndef LISTAORDENADA_HPP_INCLUDED
#define LISTAORDENADA_HPP_INCLUDED

#include "ListaDoble.hpp"

template <typename T>
class ListaOrdenada {
public:
//
//    ListaOrdenada(const ListaOrdenada& other);

//    ListaOrdenada& operator=(const ListaOrdenada& other);

    void Agregar(T valor);
    bool BuscarElem(T valor);
    void Vaciar();
    bool EstaVacia();
    int ObtenerTam();
    void ImprimirAsc();
    void ImprimirDesc();
    void Mezclar();

private:
    Lista<T> lista;
};

#include "ListaOrdenada.tpp"

#endif // LISTAORDENADA_HPP_INCLUDED
