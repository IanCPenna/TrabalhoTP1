#include <iostream>

#include <vector>
#include "dominios/senha.hpp"

#include "testesUnitarios/TUData.hpp"

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

    return 0;
}
