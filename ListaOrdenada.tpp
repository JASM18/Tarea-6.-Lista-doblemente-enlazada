#include <iostream>

//***********************************
// CONSTRUCTORES
//***********************************

//ListaOrdenada::ListaOrdenada(const ListaOrdenada& otra)
//{
//    //copy ctor
//}

//ListaOrdenada& ListaOrdenada::operator=(const ListaOrdenada& rhs)
//{
//    if (this == &rhs) return *this; // handle self assignment
//    //assignment operator
//    return *this;
//}

//***********************************
// MÉTODOS PUBLICOS
//***********************************

template <typename T>
void ListaOrdenada<T>::Agregar(T valor)
{
    //recorrer la lista
    //encontrar elemento mayor y agregarlo detras de el
    //si esta vacia agregar directamente
    //si no hay elemento mayor agregarlo al ultimo

    if (EstaVacia()){
        lista.AgregarInicio(valor);
        return;
    }

    int tam = lista.ObtenerNumElem();
    int i = 0;

    while (i < tam){
        if (valor < lista[i]){
            lista.AgregarEnPos(valor, i);
            return;
        }

        i++;
    }

    lista.AgregarFinal(valor);
}

template <typename T>
bool ListaOrdenada<T>::BuscarElem(T valor)
{

}

template <typename T>
void ListaOrdenada<T>::Vaciar()
{
    lista.Vaciar();
}

template <typename T>
bool ListaOrdenada<T>::EstaVacia()
{
    return lista.EstaVacia();
}

template <typename T>
int ListaOrdenada<T>::ObtenerTam()
{
    return lista.ObtenerNumElem;
}

template <typename T>
void ListaOrdenada<T>::ImprimirAsc()
{
    lista.Imprimir();
}

template <typename T>
void ListaOrdenada<T>::ImprimirDesc()
{
    lista.ImprimirReversa();
}

template <typename T>
void ListaOrdenada<T>::Mezclar()
{

}
