#ifndef LISTAORDENADA_HPP_INCLUDED
#define LISTAORDENADA_HPP_INCLUDED

#include "ListaDoble.hpp"

template <typename T>
class ListaOrdenada {
public:

    void Agregar(T valor);
    bool Eliminar(T valor);

    bool BuscarElem(T valor) const;

    void Vaciar();
    bool EstaVacia() const;

    int ObtenerTam() const;

    void Imprimir() const;
    void ImprimirReversa() const;

    ListaOrdenada<T> Mezclar(ListaOrdenada<T> otraLista);

private:
    Lista<T> lista;
};

template <typename T>
std::ostream& operator<<(std::ostream& salida, const ListaOrdenada<T>& listaOrd);

#include "ListaOrdenada.tpp"

#endif // LISTAORDENADA_HPP_INCLUDED
