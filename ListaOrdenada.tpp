
//***********************************
// M�TODOS PUBLICOS
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

//***********************************

template <typename T>
bool ListaOrdenada<T>::Eliminar(T valor)
{
    int pos = lista.BuscarPosicion(valor); // Busca la primera ocurrencia

    if (pos != -1) {
        lista.EliminarEnPos(pos);
        return true;
    }

    return false; // No lo encontró
}

//***********************************
template <typename T>
bool ListaOrdenada<T>::BuscarElem(T valor) const
{
    return lista.BuscarValor(valor);
}

//***********************************

template <typename T>
void ListaOrdenada<T>::Vaciar()
{
    lista.Vaciar();
}

//***********************************

template <typename T>
bool ListaOrdenada<T>::EstaVacia() const
{
    return lista.EstaVacia();
}

//***********************************

template <typename T>
int ListaOrdenada<T>::ObtenerTam() const
{
    return lista.ObtenerNumElem();
}

//***********************************

template <typename T>
void ListaOrdenada<T>::Imprimir() const
{
    lista.Imprimir();
}

//***********************************

template <typename T>
void ListaOrdenada<T>::ImprimirReversa() const
{
    lista.ImprimirReversa();
}
//***********************************

template <typename T>
ListaOrdenada<T> ListaOrdenada<T>::Mezclar(ListaOrdenada<T> otraLista)
{
    ListaOrdenada<T> listaNueva;

    // AQUÍ HAZ TODO EL COCHINERO

    return listaNueva;
}

//***********************************

template <typename T>
std::ostream& operator<<(std::ostream& salida, const ListaOrdenada<T>& listaOrd)
{
    listaOrd.Imprimir();
    return salida;
}