/**
 * \file main.cpp
 * \brief Este archivo contiene la ejecuci&oacute;n principal y el men&uacute; interactivo para probar la clase ListaOrdenada.
 * \author S&aacute;nchez Montoy, Jes&uacute;s Axel
 * \author Portugal Arreola, Marian Bethsab&eacute;
 * \date 02/04/2026
 * \code{.cpp}
 * #include <iostream>
 *
 * #include "ListaOrdenada.hpp"

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

#include <iostream>
#include <cstdlib>
#include <ctime>

#include  "CapturaSegura.hpp"
#include "ListaOrdenada.hpp"

using namespace std;

/**
 * \brief Opciones del men&uacute; principal de la Lista Ordenada.
 */
enum Opciones_principales {
    AGREGAR = 1,        ///< Opci&oacute;n para agregar un valor (manteniendo el orden).
    ELIMINAR,           ///< Opci&oacute;n para eliminar la primera ocurrencia de un valor.
    BUSCAR,             ///< Opci&oacute;n para comprobar si un valor existe.
    VACIAR,             ///< Opci&oacute;n para eliminar todos los elementos.
    ESTAVACIA,          ///< Opci&oacute;n para saber si la lista no tiene elementos.
    TAMANO,             ///< Opci&oacute;n para conocer la cantidad de elementos.
    IMPRIMIR,           ///< Opci&oacute;n para imprimir la lista (orden ascendente).
    IMPRIMIRINVERSA,    ///< Opci&oacute;n para imprimir la lista (orden descendente).
    MEZCLAR,            ///< Opci&oacute;n para fusionar dos listas ordenadas.
    SALIR               ///< Opci&oacute;n para salir del programa.
};

/** \brief Funci&oacute;n principal que ejecuta el men&uacute; interactivo del programa.
 * \return Un n&uacute;mero entero que indica el estado de terminaci&oacute;n del programa (0 si fue exitoso).
 */
int main()
{
    int opcion = -1;
    ListaOrdenada<int> lista;
    int valor;

    srand(time(NULL));

    do{
        cout << "==================================" << endl;
        cout << "Tarea 6. Lista ordenada compuesta" << endl;
        cout << "==================================" << endl << endl;

        cout << "Lista: " << lista << endl << endl;

        cout << "Opciones:" << endl;
        cout << "\t" << AGREGAR << ") Agregar un elemento." << endl;
        cout << "\t" << ELIMINAR << ") Eliminar un elemento." << endl;
        cout << "\t" << BUSCAR << ") Buscar un elemento." << endl;
        cout << "\t" << VACIAR << ") Vaciar la lista." << endl;
        cout << "\t" << ESTAVACIA << ") Conocer si la lista est\240 vac\241a." << endl;
        cout << "\t" << TAMANO << ") Conocer el tama\244o de la lista." << endl;
        cout << "\t" << IMPRIMIR << ") Imprimir la lista en forma ascendente." << endl;
        cout << "\t" << IMPRIMIRINVERSA << ") Imprimir la lista en forma descendente." << endl;
        cout << "\t" << MEZCLAR << ") Mezclar dos listas." << endl;
        cout << "\t" << SALIR << ") Salir del programa." << endl;

        do{
            CapturarNumero(opcion, "Elige una opci\242n: ");
        }while(opcion > SALIR || opcion < AGREGAR);

        if(opcion == SALIR) continue;

        try{
            switch(opcion){

                case AGREGAR:
                    cout << "- - - - -" << endl;
                    CapturarNumero(valor, "Valor a agregar: ");
                    lista.Agregar(valor);
                    cout << "El elemento " << valor << " se agregado exitosamente." << endl;
                break;

                case ELIMINAR:
                    cout << "- - - - -" << endl;
                    CapturarNumero(valor, "Valor a eliminar: ");
                    if (lista.Eliminar(valor)) {
                        cout << "El elemento " << valor << " fue eliminado correctamente." << endl;
                    } else {
                        cout << "El elemento " << valor << " no se encontr\242 en la lista." << endl;
                    }
                break;

                case BUSCAR:
                    cout << "- - - - -" << endl;
                    CapturarNumero(valor, "Valor a buscar: ");
                    cout << "El elemento " << valor << " est\240 en la lista: " << (lista.BuscarElem(valor) ? "True" : "False") << endl;
                break;

                case VACIAR:
                    cout << "- - - - -" << endl;
                    lista.Vaciar();
                    cout << "La lista se ha vaciado exitosamente." << endl;
                break;

                case ESTAVACIA:
                    cout << "- - - - -" << endl;
                    cout << "La lista est\240 vac\241a: " << (lista.EstaVacia() ? "True" : "False") << endl;
                break;

                case TAMANO:
                    cout << "- - - - -" << endl;
                    cout << "El tamaño de la lista es de: " << lista.ObtenerTam() << endl;
                break;

                case IMPRIMIR:
                    cout << "- - - - -" << endl;
                    cout << "Lista en forma ascendente:" << endl;
                    lista.Imprimir();
                    cout << endl;
                break;

                case IMPRIMIRINVERSA:
                    cout << "- - - - -" << endl;
                    cout << "Lista en forma descendente:" << endl;
                    lista.ImprimirReversa();
                    cout << endl;
                break;

                case MEZCLAR: {
                    ListaOrdenada<int> lista2;

                    cout << "- - - - -" << endl;
                    cout << "-> Se va a crear otra lista con 10 elementos aleatorios del -10 al 10" << endl;

                    // Ciclo para llenar la segunda lista
                    for(int i = 0; i < 10; i++){
                        lista2.Agregar(rand() % 21 - 10);
                    }

                    // Imprimimos el antes
                    cout << "\nLista 1: " << lista << endl;
                    cout << "Lista 2: " << lista2 << endl;

                    ListaOrdenada<int> listaMezclada = lista.Mezclar(lista2);

                    cout << "Lista mezclada: " <<listaMezclada << endl;
                    break;
                }
            }

        }catch(const char* mensaje){
            cerr << "Error: " << mensaje << endl;
        }catch(const exception &error){
            cerr << "Error: " << error.what() << endl;
        }catch(...){
            cerr << "El programa tuvo un error inesperado." << endl;
        }

        cout << endl;
        system ("pause");
        system("CLS");
    }while(opcion != SALIR);

    cout << "\nEl programa ha terminado." << endl;

    system("pause");
    return 0;
}
