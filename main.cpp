#include <iostream>

#include <vector>
#include "dominios/senha.hpp"

#include "testesUnitarios/TUData.hpp"
#include "testesUnitarios/TUCodigo.hpp"
#include "testesUnitarios/TUEstado.hpp"

using namespace std;

int main()
{
    TUData testeData;
    cout << "Testando Classe Data... " << endl;
    if (testeData.run() == testeData.SUCESSO) {
        cout << "SUCESSO!\n" << endl;
    } else {
        cout << "FALHA!\n" << endl;
    }

    TUCodigo testeCodigo;
    cout << "Testando Classe Codigo... " << endl;
    if (testeCodigo.run() == testeCodigo.SUCESSO) {
        cout << "SUCESSO!\n" << endl;
    } else {
        cout << "FALHA!\n" << endl;
    }

    TUEstado testeEstado;
    cout << "Testando Classe Estado... " << endl;
    if (testeEstado.run() == testeEstado.SUCESSO) {
        cout << "SUCESSO!\n" << endl;
    } else {
        cout << "FALHA!\n" << endl;
    }

    return 0;
}
