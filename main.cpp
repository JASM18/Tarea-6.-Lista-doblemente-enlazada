#include <iostream>
#include <cstdlib>
#include <ctime>

#include  "CapturaSegura.hpp"
#include "ListaOrdenada.hpp"

using namespace std;

enum Opciones_principales {
    AGREGAR = 1,
    ELIMINAR,
    BUSCAR,
    VACIAR,
    ESTAVACIA,
    TAMANO,
    IMPRIMIR,
    IMPRIMIRINVERSA,
    MEZCLAR,
    SALIR                   ///< Opci&oacute;n para salir del programa.
};

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
        cout << "\t" << TAMANO << ") Conocer el tamaño de la lista." << endl;
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
                        cout << "El elemento " << valor << " no se encontro en la lista." << endl;
                    }
                break;

                case BUSCAR:
                    cout << "- - - - -" << endl;
                    CapturarNumero(valor, "Valor a buscar: ");
                    cout << "El elemento " << valor << " esta en la lista: " << (lista.BuscarElem(valor) ? "True" : "False") << endl;
                break;

                case VACIAR:
                    cout << "- - - - -" << endl;
                    lista.Vaciar();
                    cout << "La lista se ha vaciado exitosamente." << endl;
                break;

                case ESTAVACIA:
                    cout << "- - - - -" << endl;
                    cout << "La lista esta vacia: " << (lista.EstaVacia() ? "True" : "False") << endl;
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
