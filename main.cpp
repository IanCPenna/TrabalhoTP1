#include <iostream>

#include "testesUnitarios/TUData.hpp"
#include "testesUnitarios/TUCodigo.hpp"
#include "testesUnitarios/TUEstado.hpp"
#include "testesUnitarios/TUNome.hpp"
#include "testesUnitarios/TUPapel.hpp"
#include "testesUnitarios/TUTempo.hpp"
#include "testesUnitarios/TUTexto.hpp"
#include "testesUnitarios/TUHistoriaUsuario.hpp"
#include "testesUnitarios/TUPlanoSprint.hpp"

using namespace std;

int main()
{

    cout    << "#####################\n"
            << "#  Teste  Dominios  #\n"
            << "#####################\n\n";

    {
        TUData teste;
        cout << "Testando Dominio Data... " << endl;
        if (teste.run() == teste.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }

    {
        TUNome teste;
        cout << "Testando Dominio Nome... " << endl;
        if (teste.run() == teste.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }

    {
        TUPapel teste;
        cout << "Testando Dominio Papel... " << endl;
        if (teste.run() == teste.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }

    {
        TUTempo teste;
        cout << "Testando Dominio Tempo... " << endl;
        if (teste.run() == teste.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }

    {
        TUTexto teste;
        cout << "Testando Dominio Texto... " << endl;
        if (teste.run() == teste.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }
    {
        TUCodigo testeCodigo;
        cout << "Testando Classe Codigo... " << endl;
        if (testeCodigo.run() == testeCodigo.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }
    {
        TUEstado testeEstado;
        cout << "Testando Classe Estado... " << endl;
        if (testeEstado.run() == testeEstado.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }


    cout    << "#####################\n"
            << "#  Teste Entidades  #\n"
            << "#####################\n\n";


    {
        TUHistoriaUsuario testeHisUs;
        cout << "Testando Entidade Historia de Usuario... " << endl;
        if (testeHisUs.run() == testeHisUs.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }

    {
        TUPlanoSprint testePlaSp;
        cout << "Testando Entidade Plano Sprint... " << endl;
        if (testePlaSp.run() == testePlaSp.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }



    return 0;
}
