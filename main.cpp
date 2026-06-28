#include <iostream>
#include "testesUnitarios/TUData.hpp"
#include "testesUnitarios/TUCodigo.hpp"
#include "testesUnitarios/TUEstado.hpp"
#include "testesUnitarios/TUNome.hpp"
#include "testesUnitarios/TUPapel.hpp"
#include "testesUnitarios/TUTempo.hpp"
#include "testesUnitarios/TUTexto.hpp"
#include "testesUnitarios/TUEmail.hpp"
#include "testesUnitarios/TUPrioridade.hpp"
#include "testesUnitarios/TUSenha.hpp"
#include "testesUnitarios/TUHistoriaUsuario.hpp"
#include "testesUnitarios/TUPlanoSprint.hpp"
#include "testesUnitarios/TUProjeto.hpp"
#include "testesUnitarios/TUPessoa.hpp"
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
        cout << "Testando Dominio Codigo... " << endl;
        if (testeCodigo.run() == testeCodigo.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }
    {
        TUEstado testeEstado;
        cout << "Testando Dominio Estado... " << endl;
        if (testeEstado.run() == testeEstado.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }
    {
        TUEmail testeEmail;
        cout << "Testando Dominio Email... " << endl;
        if (testeEmail.run() == testeEmail.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }
    {
        TUPrioridade testePrioridade;
        cout << "Testando Dominio Prioridade... " << endl;
        if (testePrioridade.run() == testePrioridade.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }
    {
        TUSenha testeSenha;
        cout << "Testando Dominio Senha... " << endl;
        if (testeSenha.run() == testeSenha.SUCESSO) {
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
    {
        TUProjeto testeProjeto;
        cout << "Testando Entidade Projeto... " << endl;
        if (testeProjeto.run() == testeProjeto.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }
    {
        TUPessoa testePessoa;
        cout << "Testando Entidade Pessoa... " << endl;
        if (testePessoa.run() == testePessoa.SUCESSO) {
            cout << "SUCESSO!\n" << endl;
        } else {
            cout << "FALHA!\n" << endl;
        }
    }
    return 0;
}
