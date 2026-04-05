#include <iostream>
#include <exception>

#include "ListaOrdenada.hpp"

using namespace std;

int main()
{
    ListaOrdenada<int> listita;
    listita.ImprimirAsc();

    cout << "\nAgregando 3" << endl;
    listita.Agregar(3);
    listita.ImprimirAsc();
    cout << "\nAgregando 4" << endl;
    listita.Agregar(4);
    listita.ImprimirAsc();
    cout << "\nAgregando 5" << endl;
    listita.Agregar(5);
    listita.ImprimirAsc();
    cout << "\nAgregando 2" << endl;
    listita.Agregar(2);
    listita.ImprimirAsc();
    cout << "\nAgregando 1" << endl;
    listita.Agregar(1);
    listita.ImprimirAsc();
    cout << "\nAgregando 2 otra vez" << endl;
    listita.Agregar(2);
    listita.ImprimirAsc();
    cout << "\nAgregando 2 otra vez" << endl;
    listita.Agregar(2);
    listita.ImprimirAsc();

    return 0;
}
