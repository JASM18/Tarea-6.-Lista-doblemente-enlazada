/**
 * \file ListaOrdenada.hpp
 * \brief Este archivo contiene la definici&oacute;n de la plantilla ListaOrdenada, la cual utiliza composici&oacute;n con la clase Lista para mantener sus elementos ordenados autom&aacute;ticamente.
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
 * \author Portugal Arreola, Marian Bethsab&eacute;
 * \date 05/04/2026
 * \code{.cpp}
#include <iostream>

#include "ListaOrdenada.hpp"

using namespace std;

int main()
{

    try{
        ListaOrdenada<int> lista1, lista2;

        cout << "Agregando el 50, -12 y el 30 a la lista..." << endl;
        lista1.Agregar(50);
        lista1.Agregar(-12);
        lista1.Agregar(30);

        cout << "lista: " << lista1 << endl;

        cout << "\n¿El 30 esta en la Lista?: " << (lista1.BuscarElem(30) ? "Si" : "No") << endl;

        lista1.Eliminar(30);
        cout << "\nLista 1 despues de eliminar el 30: " << lista1 << endl;

        cout << "\n->Creando una segunda lista con 20, 60 y 40..." << endl;
        lista2.Agregar(20);
        lista2.Agregar(60);
        lista2.Agregar(40);
        cout << "Lista 2: " << lista2 << endl;

        cout << "\nMezclando listas..." << endl;
        ListaOrdenada<int> listaMezclada = lista1.Mezclar(lista2);

        cout << "Lista 1: " << lista1 << endl;
        cout << "Lista 2: " << lista2 << endl;
        cout << "Lista mezclada: " << listaMezclada << endl;

        cout << "\Lista mezclada al reves: ";
        listaMezclada.ImprimirReversa();

    }catch(const char* mensaje){
        cerr << "Error: " << mensaje << endl;
    }catch(const exception &error){
        cerr << "Error: " << error.what() << endl;
    }catch(...){
        cerr << "El programa tuvo un error inesperado." << endl;
    }

    system("pause");
    return 0;
}
 * \endcode
 */

#ifndef LISTAORDENADA_HPP_INCLUDED
#define LISTAORDENADA_HPP_INCLUDED

#include "ListaDoble.hpp"

/**
 * \brief Plantilla de clase que representa una lista cuyos elementos se mantienen ordenados ascendentemente al momento de la inserci&oacute;n.
 * Utiliza el principio de composici&oacute;n incluyendo un objeto Lista doblemente enlazada internamente.
 *
 * \tparam T Tipo de dato que almacenar&aacute;n los elementos. Debe soportar operadores relacionales (como < y <=).
 */
template <typename T>
class ListaOrdenada {
public:

    /** \brief Agrega un elemento a la lista manteni&eacute;ndola ordenada en forma ascendente.
     * \param valor Dato de tipo T a insertar.
     * \return void
     */
    void Agregar(T valor);

    /** \brief Elimina la primera ocurrencia de un valor espec&iacute;fico en la lista.
     * \param valor Dato de tipo T que se desea eliminar.
     * \return true si el elemento fue encontrado y eliminado con &eacute;xito, false si no se encontr&oacute;.
     */
    bool Eliminar(T valor);

    /** \brief Busca si un elemento espec&iacute;fico existe dentro de la lista ordenada.
     * \param valor Dato a buscar.
     * \return true si el valor se encuentra en la lista, false en caso contrario.
     */
    bool BuscarElem(T valor) const;

    /** \brief Vac&iacute;a completamente la lista eliminando todos sus elementos.
     * \return void
     */
    void Vaciar();

    /** \brief Consulta si la lista se encuentra vac&iacute;a.
     * \return true si la lista no contiene ning&uacute;n elemento, false si contiene al menos uno.
     */
    bool EstaVacia() const;

    /** \brief Obtiene la cantidad de elementos almacenados actualmente en la lista.
     * \return Un n&uacute;mero entero que representa el tama&ntilde;o de la lista.
     */
    int ObtenerTam() const;

    /** \brief Imprime los elementos de la lista en su orden ascendente natural.
     * \return void
     */
    void Imprimir() const;

    /** \brief Imprime los elementos de la lista en orden descendente.
     * \return void
     */
    void ImprimirReversa() const;

    /** \brief Mezcla los elementos de la lista actual con otra ListaOrdenada, retornando una nueva lista combinada y ordenada.
     * \param otraLista Objeto ListaOrdenada con el cual se fusionar&aacute; la lista actual.
     * \return Un nuevo objeto ListaOrdenada<T> que contiene los elementos de ambas listas ordenados ascendentemente.
     */
    ListaOrdenada<T> Mezclar(ListaOrdenada<T> otraLista);

private:
    Lista<T> lista;             ///< Atributo de la clase: Una lista doblemente enlazada encargada del almacenamiento f&iacute;sico.
};

/** \brief Sobrecarga del operador de inserci&oacute;n para imprimir directamente el objeto ListaOrdenada.
 * \tparam T Tipo de dato de la lista.
 * \param salida Flujo de salida.
 * \param listaOrd Referencia constante al objeto ListaOrdenada a imprimir.
 * \return Referencia al flujo de salida.
 */
template <typename T>
std::ostream& operator<<(std::ostream& salida, const ListaOrdenada<T>& listaOrd);

#include "ListaOrdenada.tpp"

#endif // LISTAORDENADA_HPP_INCLUDED
