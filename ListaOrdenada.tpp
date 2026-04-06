/**
 * \file ListaOrdenada.tpp
 * \brief Este archivo contiene la implementaci&oacute;n de los m&eacute;todos de la plantilla ListaOrdenada.
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
 * \author Portugal Arreola, Marian Bethsab&eacute;
 * \date 02/04/2026
 */

//***********************************
// METODOS PUBLICOS
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

    int tam1 = this->ObtenerTam();
    int tam2 = otraLista.ObtenerTam();
    int i = 0; // indice que recorre la lista del objeto al que se le esta aplicando el método
    int j = 0; // Índice para otraLista

    while(i < tam1 && j < tam2){
        if (this->lista[i] <= otraLista.lista[j]) {
            listaNueva.lista.AgregarFinal(this->lista[i]);
            i++;
        }else{
            listaNueva.lista.AgregarFinal(otraLista.lista[j]);
            j++;
        }
    }

    // Si sobraron elementos en el ojeto *this, los metemos
    while(i < tam1){
        listaNueva.lista.AgregarFinal(this->lista[i]);
        i++;
    }

    // Si sobraron elementos en otraLista, los metemos
    while(j < tam2){
        listaNueva.lista.AgregarFinal(otraLista.lista[j]);
        j++;
    }

    return listaNueva;
}

//***********************************

template <typename T>
std::ostream& operator<<(std::ostream& salida, const ListaOrdenada<T>& listaOrd)
{
    listaOrd.Imprimir();
    return salida;
}
