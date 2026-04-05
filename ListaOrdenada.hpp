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
    bool BuscarElem(T valor) const;
    void Vaciar();
    bool EstaVacia() const;
    int ObtenerTam() const;
    void ImprimirAsc() const;
    void ImprimirDesc() const;
    ListaOrdenada<T> Mezclar(ListaOrdenada<T> lista2);

private:
    Lista<T> lista;
};

#include "ListaOrdenada.tpp"

#endif // LISTAORDENADA_HPP_INCLUDED
