/**
* \file ListaDoble.hpp
* \brief Este archivo contiene la definici&oacute;n de la plantilla de clase Lista (lista doblemente enlazada).
* \author S&aacute;nchez Montoy, Jes&uacute;s Axel
* \author Portugal Arreola, Marian Bethsab&eacute;
* \date 25/03/2026
* \code{.cpp}
#include <iostream>
#include "ListaDoble.hpp"

using namespace std;

// Función auxiliar para probar EliminarCondicion
bool esMultiploDe3(int valor) {
    return valor % 3 == 0;
}

int main() {

    try {
        Lista<int> miLista;

        miLista.AgregarFinal(10);
        miLista.AgregarFinal(20);
        miLista.AgregarInicio(5);
        miLista.AgregarEnPos(15, 2); // Inserta el 15 en el índice 2

        cout << "Lista despues de agregar elementos: " << miLista << endl;
        cout << "Total de elementos: " << miLista.ObtenerNumElem() << "\n\n";

        cout << "Primer elemento: " << miLista.ObtenerPrimero() << endl;
        cout << "Ultimo elemento: " << miLista.ObtenerUltimo() << "\n" << endl;

        cout << "Modificando el indice 2 (15 -> 99)...\n";
        miLista[2] = 99; // Usando el operador lvalue

        cout << "El valor en el indice 2 ahora es: " << miLista[2] << "\n"; // Usando operador rvalue
        cout << "Lista actual: " << miLista << endl;

        int buscar = 20;
        if (miLista.BuscarValor(buscar)) {
            cout << "\nEl valor " << buscar << " SI esta en la lista, en la posicion: " << miLista.BuscarPosicion(buscar) << "\n" << endl;
        }

        miLista.EliminarInicio();
        miLista.EliminarFinal();
        cout << "Lista tras borrar inicio y final: " << miLista << "\n" << endl; // Esperado: [ 10, 99 ]

        miLista.AgregarFinal(7);
        miLista.AgregarFinal(7);
        miLista.AgregarFinal(30); // Multiplo de 3
        miLista.AgregarFinal(7);
        miLista.AgregarFinal(9);  // Multiplo de 3

        cout << "Lista preparada para limpiar: " << miLista << endl;

        miLista.EliminarRepetidos();
        cout << "Tras EliminarRepetidos: " << miLista << endl;

        miLista.EliminarOcurrencias(7);
        cout << "Tras EliminarOcurrencias(7): " << miLista << endl;

        miLista.EliminarCondicion(esMultiploDe3);
        cout << "Tras Eliminar multiplos de 3: " << miLista << endl;

        Lista<int> listaReceptora;
        listaReceptora.AgregarFinal(100);
        listaReceptora.AgregarFinal(200);

        cout << endl;
        cout << "Lista Original: " << miLista << endl;
        cout << "Lista Receptora: " << listaReceptora << endl;

        cout << "\nIntercambiando listas...\n";
        miLista.Intercambiar(listaReceptora);
        cout << "Lista Original: " << miLista << endl;
        cout << "Lista Receptora: " << listaReceptora << endl;

        cout << "\nTransfiriendo todos los elementos de la Receptora a la Original...\n";
        listaReceptora.TransferirTodos(miLista);
        cout << "Lista Original: " << miLista << endl;
        cout << "Lista Receptora: " << listaReceptora << endl; // Debería estar vacía
        cout << "\n";

        cout << "Intentando acceder a un indice invalido (100)...\n";
        int valorImposible = miLista.ObtenerEnPos(100);
        cout << valorImposible;

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


#ifndef LISTADOBLE_HPP_INCLUDED
#define LISTADOBLE_HPP_INCLUDED


/**
* \brief Plantilla de clase Lista implementada con nodos doblemente enlazados.
*
* \tparam T Tipo de dato que almacenar&aacute;n los elementos de la lista.
*/
template <typename T>
class Lista {
public:
    /** \brief Constructor por default que inicializa la lista vac&iacute;a.
    */
    Lista();

    /** \brief Destructor por default que libera la memoria din&aacute;mica.
    */
    ~Lista();

    /** \brief Constructor de copias para inicializar una lista a partir de otra existente.
    * \param lista Referencia constante a la lista que se copiar&aacute;.
    */
    Lista(const Lista& lista);

    /** \brief Operador de asignaci&oacute;n sobrecargado.
    * \param lista Referencia constante a la lista que se va a igualar a la actual.
    * \return Una referencia a la lista actual (*this).
    */
    Lista& operator=(const Lista& lista);

    /** \brief Agrega un nuevo elemento al principio de la lista.
    * \param valor Dato de tipo T que se a&ntilde;adir&aacute;.
    * \return void
    * \throw ListaNoMemoria Lanza una excepci&oacute;n si falla la asignaci&oacute;n de memoria.
    */
    void AgregarInicio(T valor);

    /** \brief Agrega un nuevo elemento al final de la lista.
    * \param valor Dato de tipo T que se a&ntilde;adir&aacute;.
    * \return void
    * \throw ListaNoMemoria Lanza una excepci&oacute;n si falla la asignaci&oacute;n de memoria.
    */
    void AgregarFinal(T valor);

    /** \brief Agrega un elemento a la lista en cierta posici&oacute;n.
    * \param valor Dato de tipo T que se a&ntilde;adir&aacute;.
    * \param pos &Iacute;ndice entero donde se insertar&aacute; el elemento.
    * \return void
    * \throw ListaIndice Lanza una excepci&oacute;n si la posici&oacute;n est&aacute; fuera de rango.
    * \throw ListaNoMemoria Lanza una excepci&oacute;n si falla la asignaci&oacute;n de memoria.
    */
    void AgregarEnPos(T valor, int pos);

    /** \brief Elimina el elemento al inicio de la lista.
    * \return void
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista no contiene elementos.
    */
    void EliminarInicio();

    /** \brief Elimina el elemento al final de la lista.
    * \return void
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista no contiene elementos.
    */
    void EliminarFinal();

    /** \brief Elimina un elemento de la lista en cierta posici&oacute;n.
    * \param pos &Iacute;ndice entero del elemento que se desea eliminar.
    * \return void
    * \throw ListaIndice Lanza una excepci&oacute;n si la posici&oacute;n est&aacute; fuera de rango.
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista est&aacute; vac&iacute;a.
    */
    void EliminarEnPos(int pos);

    /** \brief Busca si un valor espec&iacute;fico est&aacute; en la lista.
    * \param valor Dato a buscar en la lista.
    * \return true si el valor es encontrado, false en caso contrario.
    */
    bool BuscarValor(T valor) const;

    /** \brief Busca la primera posici&oacute;n de un valor en la lista.
    * \param valor Dato cuya posici&oacute;n se desea encontrar.
    * \return N&uacute;mero entero que representa la posici&oacute;n donde se encuentra el dato, o -1 si no existe.
    */
    int BuscarPosicion(T valor) const;

    /** \brief Conocer si la lista est&aacute; vac&iacute;a.
    * \return true si la lista no tiene elementos, false si contiene al menos uno.
    */
    bool EstaVacia() const;

    /** \brief Obtiene el primer elemento de la lista.
    * \return El valor almacenado en el primer nodo.
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista est&aacute; vac&iacute;a.
    */
    T ObtenerPrimero() const;

    /** \brief Obtiene el &uacute;ltimo elemento de la lista.
    * \return El valor del &uacute;ltimo elemento.
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista est&aacute; vac&iacute;a.
    */
    T ObtenerUltimo() const;

    /** \brief Obtiene el elemento de la lista en cierta posici&oacute;n..
    * \param pos Posici&oacute;n del elemento el cual se desea extraer el valor.
    * \return El valor almacenado en dicha posici&oacute;n.
    */
    T ObtenerEnPos(int pos) const;

    /** \brief Modifica el elemento de la lista en cierta posici&oacute;n.
    * \param valor Nuevo dato que reemplazar&aacute; al actual.
    * \param pos Poici&oacute;n que se desea modificar.
    * \return void
    */
    void ModificarEnPos(T valor, int pos);

    /** \brief Obtener el n&uacute;mero de elementos de la lista.
    * \return Entero con la cantidad de elementos de la lista.
    */
    int ObtenerNumElem() const;

    /** \brief Vac&iacute;a la lista, eliminando todos sus elementos y liberando la memoria.
    * \return void
    */
    void Vaciar();

    /** \brief Imprime los elementos de la lista.
    * \return void
    */
    void Imprimir() const;

    /** \brief Imprime los elementos de la lista en reversa.
    * \return void
    */
    void ImprimirReversa() const;

    /** \brief Sobrecarga del operador de corchetes (lvalue) para acceder y modificar un elemento.
    * \param pos Posici&oacute;n a acceder.
    * \return Referencia al dato almacenado en la posici&oacute;n indicada.
    * \throw ListaIndice Lanza una excepci&oacute;n si la posici&oacute;n es inv&aacute;lida.
    */
    T &operator[](int pos); //devuelve una referencia, no debe ser constante

    /** \brief Sobrecarga del operador de sub&iacute;ndices (rvalue) para obtener una copia de un elemento.
    * \param pos Posici&oacute;n a acceder.
    * \return Copia del dato almacenado en la posici&oacute;n indicada.
    * \throw ListaIndice Lanza una excepci&oacute;n si la posici&oacute;n es inv&aacute;lida.
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista est&aacute; vac&iacute;a.
    */
    T operator[](int pos) const; //devuelve valor, debe ser constante

    /** \brief Elimina todas las ocurrencias de cierto elemento en la lista.
    * \param valor El dato que ser&aacute; eliminado de todas las posiciones donde se encuentre.
    * \return void
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista est&aacute; vac&iacute;a.
    */
    void EliminarOcurrencias(T valor);

    /** \brief Elimina todo elemento que cumpla con cierta condici&oacute;n.
    * \param condicion Puntero a una funci&oacute;n que recibe un tipo T y regresa un booleano evaluando la condici&oacute;n.
    * \return void
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista est&aacute; vac&iacute;a.
    */
    void EliminarCondicion(bool (*condicion)(T));

    /** \brief Elimina todo elemento repetido, dejando solo la primera ocurrencia.
    * \return void
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista est&aacute; vac&iacute;a.
    */
    void EliminarRepetidos();

    /** \brief Intercambia todos los elementos de la lista actual con otra lista recibida.
    * \param otra Referencia a la lista con la que se intercambiar&aacute;.
    * \return void
    */
    void Intercambiar(Lista<T>& otra);

    /** \brief Transfiere elementos de una lista a otra (al final de la otra lista) desde una posici&oacute;n hasta otra.
    * \param receptora Lista donde se a&ntilde;adir&aacute;n los elementos.
    * \param posInicio &Iacute;ndice donde comienza el rango a transferir.
    * \param posFin &Iacute;ndice donde termina el rango a transferir.
    * \return void
    * \throw ListaIndice Lanza una excepci&oacute;n si el rango proporcionado es inv&aacute;lido.
    */
    void TransferirEnRango(Lista<T>& receptora, int posInicio, int posFin);

    /** \brief Transfiere los elementos a partir de cierta posici&oacute;n hacia otra lista.
    * \param receptora Lista donde se a&ntilde;adir&aacute;n los elementos.
    * \param posInicio &Iacute;ndice a partir del cual se transferir&aacute;n todos los siguientes elementos.
    * \return void
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista est&aacute; vac&iacute;a.
    */
    void TransferirDesde(Lista<T>& receptora, int posInicio);

    /** \brief Transfiere todos los elementos de la lista actual hacia el final de otra lista.
    * \param receptora Lista donde se a&ntilde;adir&aacute;n todos los elementos.
    * \return void
    * \throw ListaVacia Lanza una excepci&oacute;n si la lista est&aacute; vac&iacute;a.
    */
    void TransferirTodos(Lista<T>& receptora);

    /**
     * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando se intenta acceder o extraer de una cola vac&iacute;a.
     */
    class ListaVacia : public std::exception {
    public:
        /** \brief Constructor por default de la excepci&oacute;n ColaVacia.
         */
        ListaVacia() throw();

        /** \brief Devuelve una descripci&oacute;n del error al intentar operar con una lista vac&iacute;a.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

    /**
    * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando ocurren fallos de reserva de memoria.
    */
    class ListaNoMemoria : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n ListaNoMemoria.
         */
        ListaNoMemoria() throw();

        /** \brief Devuelve una descripci&oacute;n del error cuando no haya memoria disponible.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

    /**
    * \brief Descripci&oacute;n de la clase/struct: Excepci&oacute;n lanzada cuando el cliente intenta acceder a indices no disponibles
    */
    class ListaIndice : public std::exception {
    public:
        /** \brief Constructor por defecto de la excepci&oacute;n ListaNoMemoria.
         */
        ListaIndice() throw();

        /** \brief Devuelve una descripci&oacute;n del error cuando el cliente intente acceder a indices no disponibles.
         *
         * \return Cadena de caracteres con el mensaje de error.
         */
        virtual const char *what() const throw();
    };

private:
    int numElem = 0;        ///< Cantidad de elementos guardados en la lista.

    /**
    * \brief Descripci&oacute;n de la clase/struct: Estructura interna para representar un nodo doblemente enlazado.
    */
    struct Elemento {
        T valor;                            ///< Dato almacenado en el nodo.
        Elemento *anterior, *siguiente;     ///< Punteros a los elementos anterior y siguiente.

        /** \brief Constructor de la estructura Elemento.
        * \param v Dato a almacenar.
        * \param ant Puntero al elemento anterior.
        * \param sig Puntero al elemento siguiente.
        */
        Elemento(T v, Elemento *ant = nullptr, Elemento *sig = nullptr);
    };

    Elemento *primero = nullptr;            ///< Puntero al primer elemento de la lista.
    Elemento *ultimo = nullptr;             ///< Puntero al &uacute;ltimo elemento de la lista.
};

/** \brief Sobrecarga del operador de inserci&oacute;n para imprimir la lista.
* \tparam T Tipo de dato de la lista.
* \param salida Flujo de salida.
* \param lista Lista que se va a imprimir.
* \return Referencia al flujo de salida modificado.
*/
template <typename T>
std::ostream& operator<<(std::ostream& salida, const Lista<T>& lista);
#include "ListaDoble.tpp"

#endif // LISTADOBLE_HPP_INCLUDED
