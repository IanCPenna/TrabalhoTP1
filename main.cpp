#include <iostream>
#include <string>

// --- Testes unitarios (camada de dominio e entidade) ---
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

// --- Camadas de servico e apresentacao (sistema integrado) ---
#include "controladoras_servico.hpp"
#include "controladoras_apresentacao.hpp"

using namespace std;

/**
 * @brief Executa todos os testes unitarios de dominio e entidade.
 */
static void executarTestes() {
    cout << "#####################\n"
         << "#  Teste  Dominios  #\n"
         << "#####################\n\n";
    { TUData t;       cout << "Data...       " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUNome t;       cout << "Nome...       " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUPapel t;      cout << "Papel...      " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUTempo t;      cout << "Tempo...      " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUTexto t;      cout << "Texto...      " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUCodigo t;     cout << "Codigo...     " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUEstado t;     cout << "Estado...     " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUEmail t;      cout << "Email...      " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUPrioridade t; cout << "Prioridade... " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUSenha t;      cout << "Senha...      " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }

    cout << "\n#####################\n"
         << "#  Teste Entidades  #\n"
         << "#####################\n\n";
    { TUHistoriaUsuario t; cout << "HistoriaUsuario... " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUPlanoSprint t;     cout << "PlanoSprint...     " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUProjeto t;         cout << "Projeto...         " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
    { TUPessoa t;          cout << "Pessoa...          " << (t.run() == t.SUCESSO ? "SUCESSO" : "FALHA") << "\n"; }
}

/**
 * @brief Cadastra pessoas iniciais para viabilizar a autenticacao e os demais
 *        servicos (um mestre scrum e um proprietario de produto).
 */
static void semearDados(CntrLNPessoa& lnPessoa) {
    Pessoa mestre;
    Email e1; e1.setValor("admin@scrum.com");
    Nome n1; n1.setValor("Admin");
    Senha s1; s1.setValor("a1B2c3");
    Papel p1; p1.setValor("MESTRE SCRUM");
    mestre.setEmail(e1); mestre.setNome(n1); mestre.setSenha(s1); mestre.setPapel(p1);
    lnPessoa.criar(mestre);

    Pessoa dono;
    Email e2; e2.setValor("dono@scrum.com");
    Nome n2; n2.setValor("Dono");
    Senha s2; s2.setValor("a1B2c3");
    Papel p2; p2.setValor("PROPRIETARIO DE PRODUTO");
    dono.setEmail(e2); dono.setNome(n2); dono.setSenha(s2); dono.setPapel(p2);
    lnPessoa.criar(dono);
}

/**
 * @brief Le a opcao do menu principal. Retorna -1 em caso de fim de entrada.
 */
static int lerOpcaoPrincipal() {
    cout << "\n=========== Menu Principal ===========\n"
         << "1 - Pessoas\n2 - Projetos\n3 - Planos de Sprint\n"
         << "4 - Historias de Usuario\n0 - Sair\n"
         << "Opcao: ";
    string linha;
    if (!getline(cin, linha))
        return -1;
    try { return stoi(linha); } catch (...) { return -2; }
}

int main() {
    // 1. Executa os testes unitarios das camadas de dominio e entidade.
    executarTestes();

    // 2. Instancia e liga as camadas de servico e de apresentacao.
    CntrLNPessoa          lnPessoa;
    CntrLNProjeto         lnProjeto;
    CntrLNPlanoSprint     lnPlano;
    CntrLNHistoriaUsuario lnHistoria;

    lnProjeto.setCntrLNPessoa(&lnPessoa);
    lnPlano.setCntrLNProjeto(&lnProjeto);
    lnHistoria.setCntrLNProjeto(&lnProjeto);
    lnHistoria.setCntrLNPlanoSprint(&lnPlano);

    CntrIUAutenticacao    iuAutenticacao;
    CntrIUPessoa          iuPessoa;
    CntrIUProjeto         iuProjeto;
    CntrIUPlanoSprint     iuPlano;
    CntrIUHistoriaUsuario iuHistoria;

    iuAutenticacao.setCntrLNAutenticacao(&lnPessoa);
    iuPessoa.setCntrLNPessoa(&lnPessoa);
    iuProjeto.setCntrLNProjeto(&lnProjeto);
    iuPlano.setCntrLNPlanoSprint(&lnPlano);
    iuHistoria.setCntrLNHistoriaUsuario(&lnHistoria);

    semearDados(lnPessoa);

    cout << "\n\n#############################################\n"
         << "#   Sistema de Gestao de Projetos (Scrum)   #\n"
         << "#############################################\n"
         << "(contas iniciais: admin@scrum.com e dono@scrum.com, senha a1B2c3)\n";

    // 3. Autenticacao como porta de entrada.
    Email usuarioLogado;
    bool autenticado = false;
    while (!autenticado) {
        try {
            autenticado = iuAutenticacao.autenticar(&usuarioLogado);
            if (!autenticado)
                cout << "Credenciais invalidas. Tente novamente.\n";
        } catch (const runtime_error&) {
            cout << "Erro de sistema na autenticacao.\n";
            return 1;
        }
        if (!cin) { // fim de entrada durante a autenticacao
            cout << "\nEncerrando.\n";
            return 0;
        }
    }
    cout << "\nAutenticado como: " << usuarioLogado.getValor() << "\n";

    // 4. Menu principal: acesso aos servicos apos autenticado.
    int opcao;
    do {
        opcao = lerOpcaoPrincipal();
        switch (opcao) {
            case 1: iuPessoa.executar(usuarioLogado);   break;
            case 2: iuProjeto.executar(usuarioLogado);  break;
            case 3: iuPlano.executar(usuarioLogado);    break;
            case 4: iuHistoria.executar(usuarioLogado); break;
            case 0:
            case -1: cout << "\nEncerrando o sistema.\n"; break;
            default: cout << "Opcao invalida.\n"; break;
        }
    } while (opcao != 0 && opcao != -1);

    return 0;
}
