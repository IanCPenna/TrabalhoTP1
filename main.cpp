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
 * @brief Le a opcao de um menu. Retorna -1 em caso de fim de entrada (EOF).
 */
static int lerOpcao(const string& menu) {
    cout << menu << "Opcao: ";
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
    lnHistoria.setCntrLNPessoa(&lnPessoa);

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

    cout << "\n\n#############################################\n"
         << "#   Sistema de Gestao de Projetos (Scrum)   #\n"
         << "#############################################\n";

    const string menuInicial =
        "\n=========== Tela Inicial ===========\n"
        "1 - Entrar\n2 - Criar conta\n0 - Sair\n";
    const string menuPrincipal =
        "\n=========== Menu Principal ===========\n"
        "1 - Pessoas\n2 - Projetos\n3 - Planos de Sprint\n"
        "4 - Historias de Usuario\n0 - Sair (logout)\n";

    // 3. Tela inicial: o usuario pode criar conta (cadastro) ou entrar (login).
    int opcaoInicial;
    do {
        opcaoInicial = lerOpcao(menuInicial);

        if (opcaoInicial == 1) {
            // 3a. Autenticacao como porta de entrada para os servicos.
            Email usuarioLogado;
            bool autenticado = false;
            try {
                autenticado = iuAutenticacao.autenticar(&usuarioLogado);
            } catch (const runtime_error&) {
                cout << "Erro de sistema na autenticacao.\n";
                continue;
            }
            if (!autenticado) {
                cout << "Credenciais invalidas.\n";
                continue;
            }
            // Recupera o papel do usuario autenticado (define suas permissoes).
            Pessoa pessoaLogada;
            pessoaLogada.setEmail(usuarioLogado);
            lnPessoa.ler(&pessoaLogada);
            Papel papelLogado = pessoaLogada.getPapel();
            cout << "\nAutenticado como: " << usuarioLogado.getValor()
                 << " (" << papelLogado.getValor() << ")\n";

            // 4. Menu principal: servicos disponiveis apos autenticado.
            //    Operacoes restritas por papel lancam runtime_error, capturado aqui.
            int opcao;
            do {
                opcao = lerOpcao(menuPrincipal);
                try {
                    switch (opcao) {
                        case 1: iuPessoa.executar(papelLogado);   break;
                        case 2: iuProjeto.executar(papelLogado);  break;
                        case 3: iuPlano.executar(papelLogado);    break;
                        case 4: iuHistoria.executar(papelLogado); break;
                        case 0:
                        case -1: cout << "\nLogout.\n"; break;
                        default: cout << "Opcao invalida.\n"; break;
                    }
                } catch (const runtime_error& excecao) {
                    cout << excecao.what() << "\n";
                }
            } while (opcao != 0 && opcao != -1);

        } else if (opcaoInicial == 2) {
            // 3b. Criacao de conta: qualquer email valido pode se cadastrar.
            iuPessoa.cadastrar();
        } else if (opcaoInicial == 0 || opcaoInicial == -1) {
            cout << "\nEncerrando o sistema.\n";
        } else {
            cout << "Opcao invalida.\n";
        }
    } while (opcaoInicial != 0 && opcaoInicial != -1);

    return 0;
}
