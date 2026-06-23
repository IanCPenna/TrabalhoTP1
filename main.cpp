#include <iostream>

#include "testesUnitarios/TUData.hpp"
#include "testesUnitarios/TUNome.hpp"
#include "testesUnitarios/TUPapel.hpp"
#include "testesUnitarios/TUTempo.hpp"
#include "testesUnitarios/TUTexto.hpp"

using namespace std;

int main()
{
    {
        TUData teste;
        cout << "Testando Classe Data... " << endl;
        if (teste.run() == teste.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }

    {
        TUNome teste;
        cout << "Testando Classe Nome... " << endl;
        if (teste.run() == teste.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }

    {
        TUPapel teste;
        cout << "Testando Classe Papel... " << endl;
        if (teste.run() == teste.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }

    {
        TUTempo teste;
        cout << "Testando Classe Tempo... " << endl;
        if (teste.run() == teste.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }

    {
        TUTexto teste;
        cout << "Testando Classe Texto... " << endl;
        if (teste.run() == teste.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }

    return 0;
}
