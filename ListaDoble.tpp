/**
* \file ListaDoble.tpp
* \brief Este archivo contiene la implementaci&oacute;n de los m&eacute;todos de la plantilla de clase Lista (lista doblemente enlazada).
* \author S&aacute;nchez Montoy, Jes&uacute;s Axel
* \author Portugal Arreola, Marian Bethsab&eacute;
* \date 25/03/2026
*/

#include <iostream>

//***********************************
// CONSTRUCTORES
//***********************************

template <typename T>
Lista<T>::Lista()
{
    numElem = 0;
    primero = nullptr;
    ultimo = nullptr;
}

//***********************************

template <typename T>
Lista<T>::~Lista()
{
    Vaciar();
}

//***********************************

template <typename T>
Lista<T>::Lista(const Lista& lista)
{
    numElem = 0;
    primero = nullptr;
    ultimo = nullptr;
    *this = lista;
}

//***********************************

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista& lista)
{
    if (this == &lista) return *this; // handle self assignment
    //assignment operator

    Vaciar();

    if (lista.EstaVacia()) {
        return *this;
    }

    Elemento *visitado = lista.primero;
    while (visitado != nullptr) {
        AgregarFinal(visitado->valor);
        visitado = visitado->siguiente;
    }

    return *this;
}

//***********************************

template <typename T>
void Lista<T>::AgregarInicio(T valor)
{
    try{
        Elemento *nuevo = new Elemento(valor);

        if(EstaVacia()){
            primero = nuevo;
            ultimo = nuevo;
        }else{
            nuevo->siguiente = primero;
            primero->anterior = nuevo;
            primero = nuevo;
        }

        ++numElem;
    }catch(const std::bad_alloc&){
        throw ListaNoMemoria();
    }
}

//***********************************

template <typename T>
void Lista<T>::AgregarFinal(T valor)
{
    try{
        Elemento *nuevo = new Elemento(valor);

        if(EstaVacia()){
            primero = nuevo;
            ultimo = nuevo;
        }else{
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;

            ultimo = nuevo;
        }

        numElem++;

    }catch(const std::bad_alloc&){
        throw ListaNoMemoria();
    }
}

//***********************************

template <typename T>
void Lista<T>::AgregarEnPos(T valor, int pos)
{
    if(pos < 0 || pos > numElem) throw ListaIndice();

    if(pos == 0) {
        AgregarInicio(valor);
        return;
    }

    if (pos == numElem) {
        AgregarFinal(valor);
        return;
    }

    Elemento *visitado;
    if (pos > numElem/2){
        visitado = ultimo;

        for (int i = numElem-1; i > pos; i--){
            visitado = visitado->anterior;
        }

    }else{
        visitado = primero;

        for (int i = 0; i < pos; i++){
            visitado = visitado->siguiente;
        }
    }

    try{
        Elemento *nuevo = new Elemento(valor, visitado->anterior, visitado);
        visitado->anterior->siguiente = nuevo;
        visitado->anterior = nuevo;
        numElem++;
    }catch(const std::bad_alloc&){
        throw ListaNoMemoria();
    }
}

//***********************************

template <typename T>
void Lista<T>::EliminarInicio()
{
    if(EstaVacia()){
        throw ListaVacia();
    }

    Elemento *porBorrar = primero;

    if(numElem == 1){
        primero = nullptr;
        ultimo = nullptr;

    }else{
        primero = primero->siguiente;
        primero->anterior = nullptr;
    }

    delete porBorrar;
    --numElem;
}

//***********************************

template <typename T>
void Lista<T>::EliminarFinal()
{
    if(EstaVacia()){
        throw ListaVacia();
    }

    Elemento *porBorrar = ultimo;

    if(numElem == 1){
        primero = nullptr;
        ultimo = nullptr;

    }else{
        ultimo = ultimo->anterior;
        ultimo->siguiente = nullptr;
    }

    delete porBorrar;
    --numElem;
}

//***********************************

template <typename T>
void Lista<T>::EliminarEnPos(int pos)
{
    if (pos < 0 || pos >= numElem) throw ListaIndice();

    if (EstaVacia()) throw ListaVacia();

    if (pos == 0){
        EliminarInicio();
        return;
    }

    if (pos == numElem-1){
        EliminarFinal();
        return;
    }

    Elemento *visitado;

    if (pos > numElem / 2){
        visitado = ultimo;
        for (int i = numElem - 1; i > pos; i--){
            visitado = visitado->anterior;
        }
    }else{
        visitado = primero;
        for (int i = 0; i < pos; i++){
            visitado = visitado->siguiente;
        }
    }

    visitado->anterior->siguiente = visitado->siguiente;
    visitado->siguiente->anterior = visitado->anterior;

    --numElem;

    delete visitado;
}

//***********************************

template <typename T>
bool Lista<T>::BuscarValor(T valor) const
{
    Elemento *visitado = primero;

    while (visitado !=nullptr && visitado->valor != valor){
        visitado = visitado->siguiente;
    }

    return visitado !=nullptr;
}

//***********************************

template <typename T>
int Lista<T>::BuscarPosicion(T valor) const
{
    Elemento *visitado = primero;

    int pos = 0;

    while (visitado != nullptr && visitado->valor != valor){
        visitado = visitado->siguiente;
        ++pos;
    }

    return visitado != nullptr ? pos : -1;
}

//***********************************

template <typename T>
bool Lista<T>::EstaVacia() const
{
    if (numElem == 0){
        return true;
    }
    return false;
}

//***********************************

template <typename T>
T Lista<T>::ObtenerPrimero() const
{
    if (EstaVacia()) throw ListaVacia();

    return primero->valor;
}

//***********************************

template <typename T>
T Lista<T>::ObtenerUltimo() const
{
    if (EstaVacia()) throw ListaVacia();
    return ultimo->valor;
}

//***********************************

template <typename T>
T Lista<T>::ObtenerEnPos(int pos) const
{
    return (*this)[pos];
}

//***********************************

template <typename T>
void Lista<T>::ModificarEnPos(T valor, int pos)
{
    (*this)[pos] = valor;
}

//***********************************

template <typename T>
int Lista<T>::ObtenerNumElem() const
{
    return numElem;
}

//***********************************

template <typename T>
void Lista<T>::Vaciar()
{
    while (!EstaVacia()){
        EliminarInicio();
    }
}

//***********************************

template <typename T>
void Lista<T>::Imprimir() const
{
    if(EstaVacia()){
        std::cout << "[ ]";
        return;
    }

    Elemento *visitado = primero;
    std::cout << "[ ";

    while(visitado != nullptr){
        std::cout << visitado->valor << ", ";
        visitado = visitado->siguiente;
    }

    if(!EstaVacia()) std::cout << "\b\b ]";
}

//***********************************

template <typename T>
void Lista<T>::ImprimirReversa() const
{
    if(EstaVacia()){
        std::cout << "[ ]" << std::endl;
        return;
    }

    Elemento *visitado = ultimo;
    std::cout << "[ ";

    while(visitado != nullptr){
        std::cout << visitado->valor << ", ";
        visitado = visitado->anterior;
    }

    if(!EstaVacia()) std::cout << "\b\b ]";
}

//***********************************
// OPERADORES SOBRECARGADOS
//***********************************

template <typename T>
std::ostream& operator<<(std::ostream& salida, const Lista<T>& lista)
{
    lista.Imprimir();
    return salida;
}

//***********************************

template <typename T>
T &Lista<T>::operator[](int pos)
{
    if(pos < 0 || pos >= numElem) throw ListaIndice();

    Elemento *visitado;

    if (pos > numElem / 2) {
        visitado = ultimo;
        for (int i = numElem - 1; i > pos; --i) {
            visitado = visitado->anterior;
        }
    }else {
        visitado = primero;
        for (int i = 0; i < pos; ++i) {
            visitado = visitado->siguiente;
        }
    }

    return visitado->valor;
}

//***********************************

template <typename T>
T Lista<T>::operator[](int pos) const
{
    if (pos < 0 || pos >= numElem) throw ListaIndice();
    if (EstaVacia()) throw ListaVacia();

    if (pos == 0) {
        return ObtenerPrimero();
    }
    if (pos == numElem-1) {
        return ObtenerUltimo();
    }

    Elemento *visitado;

    if (pos > numElem / 2){
        visitado = ultimo;
        for (int i = numElem - 1; i > pos; i--){
            visitado = visitado->anterior;
        }
    }else{
        visitado = primero;
        for (int i = 0; i < pos; i++){
            visitado = visitado->siguiente;
        }
    }

    return visitado->valor;
}

//***********************************
template <typename T>
void Lista<T>::EliminarOcurrencias(T valor)
{
    if (EstaVacia()) throw ListaVacia();

    Elemento *visitado = primero;
    int indice = 0;

    while(visitado != nullptr){
        Elemento *siguienteNodo = visitado->siguiente;

        if (visitado->valor == valor){
            (*this).EliminarEnPos(indice);
            --indice;
        }

        visitado = siguienteNodo;
        ++indice;
    }
}

//***********************************
template <typename T>
void Lista<T>::EliminarCondicion(bool (*condicion)(T))
{
    if (EstaVacia()) throw ListaVacia();

    Elemento *visitado = primero;

    while (visitado != nullptr) {
        Elemento *siguienteNodo = visitado->siguiente;

        // Evaluamos la condición
        if (condicion(visitado->valor)){

            if (visitado == primero){
                primero = visitado->siguiente;

                if (primero != nullptr){
                    primero->anterior = nullptr;
                }else{
                    ultimo = nullptr;
                }

            }else if (visitado == ultimo){
                ultimo = visitado->anterior;

                if (ultimo != nullptr){
                    ultimo->siguiente = nullptr;
                }else{
                    primero = nullptr;
                }

            }else{
                visitado->anterior->siguiente = visitado->siguiente;
                visitado->siguiente->anterior = visitado->anterior;
            }

            delete visitado;
            numElem--;
        }

        visitado = siguienteNodo;
    }
}

//***********************************
template <typename T>
void Lista<T>::EliminarRepetidos()
{
    if (EstaVacia()) throw ListaVacia();

    Elemento *visitado = primero;
    int indice = 0;

    while (visitado != nullptr){

        Elemento *aux = visitado->siguiente;
        int indiceAux = indice + 1;

        while (aux != nullptr){
            Elemento *siguienteAux = aux->siguiente;

            if (aux->valor == visitado->valor){
                (*this).EliminarEnPos(indiceAux);
                --indiceAux;
            }

            aux = siguienteAux;
            ++indiceAux;
        }

        visitado = visitado->siguiente;
        ++indice;
    }
}

//***********************************
template <typename T>
void Lista<T>::Intercambiar(Lista<T>& otra)
{
    Elemento *tempPrimero = primero;
    primero = otra.primero;
    otra.primero = tempPrimero;

    Elemento *tempUltimo = ultimo;
    ultimo = otra.ultimo;
    otra.ultimo = tempUltimo;

    int tempNum = numElem;
    numElem = otra.numElem;
    otra.numElem = tempNum;
}

//***********************************
template <typename T>
void Lista<T>::TransferirEnRango(Lista<T>& lista, int posInicio, int posFin)
{
    if (posInicio < 0 || posFin >= numElem || posInicio > posFin) throw ListaIndice();

    if (this == &lista) return;

    //Desconectamos el rango de la lista original

    Elemento *Inicio = primero;

    for (int i = 0; i < posInicio; ++i){
        Inicio = Inicio->siguiente;
    }

    Elemento *Fin = Inicio;

    for (int i = posInicio; i < posFin; ++i){
        Fin = Fin->siguiente;
    }

    int cantTransf = posFin - posInicio + 1;

    if (Inicio->anterior != nullptr){
        Inicio->anterior->siguiente = Fin->siguiente;
    }else{
        primero =  Fin->siguiente;
    }

    if (Fin->siguiente != nullptr){
        Fin->siguiente->anterior = Inicio->anterior;
    }else{
        ultimo = Inicio->anterior;
    }

    numElem -= cantTransf;

    //Ahora conectamos con la lista receptora

    Inicio->anterior = lista.ultimo;
    Fin->siguiente = nullptr;

    if (lista.EstaVacia()){
        lista.primero = Inicio;
    }else{
        lista.ultimo->siguiente = Inicio;
    }

    lista.ultimo = Fin;
    lista.numElem += cantTransf;
}

//***********************************

template <typename T>
void Lista<T>::TransferirDesde(Lista<T>& lista, int posInicio)
{
    if (EstaVacia()) throw ListaVacia();

    TransferirEnRango(lista, posInicio, numElem - 1);
}

//***********************************

template <typename T>
void Lista<T>::TransferirTodos(Lista<T>& lista)
{
    if (EstaVacia()) throw ListaVacia();

    TransferirEnRango(lista, 0, numElem - 1);
}

//***********************************
// Constructor de Elemento
//***********************************

template <typename T>
Lista<T>::Elemento::Elemento(T v, Elemento *ant /*=nullptr*/, Elemento *sig /*=nullptr*/) : valor(v), anterior(ant), siguiente(sig) {}

//***********************************
// Implementaci�n de las clases excepciones
//***********************************

template <typename T>
Lista<T>::ListaVacia::ListaVacia() throw() {}

//***********************************

template <typename T>
Lista<T>::ListaNoMemoria::ListaNoMemoria() throw(){}

//***********************************

template <typename T>
Lista<T>::ListaIndice::ListaIndice() throw(){}

//***********************************

template <typename T>
const char *Lista<T>::ListaVacia::what() const throw()
{
    return "La lista se encuentra vac\241a.";
}

//***********************************

template <typename T>
const char *Lista<T>::ListaNoMemoria::what() const throw()
{
    return "No hay memoria disponible.";
}

//***********************************

template <typename T>
const char *Lista<T>::ListaIndice::what() const throw()
{
    return "\326ndice fuera de rango.";
}
