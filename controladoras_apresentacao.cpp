#include "controladoras_apresentacao.hpp"

#include <iostream>
#include <string>
#include <list>

using namespace std;

// ===========================================================================
//  Funcoes auxiliares de leitura (entrada padrao com validacao de formato).
// ===========================================================================

/**
 * @brief Le uma linha da entrada padrao.
 * @return false em caso de fim de entrada (EOF), encerrando a interacao.
 */
static bool lerLinha(const string& rotulo, string& destino) {
    cout << rotulo;
    return static_cast<bool>(getline(cin, destino));
}

/**
 * @brief Le um valor de dominio textual, repetindo enquanto o formato for invalido.
 * @return false em caso de fim de entrada.
 */
template <class TDominio>
static bool lerDominio(const string& rotulo, TDominio& dominio) {
    while (true) {
        string linha;
        if (!lerLinha(rotulo, linha))
            return false;
        try {
            dominio.setValor(linha);
            return true;
        } catch (const invalid_argument& excecao) {
            cout << "  [formato invalido] " << excecao.what() << endl;
        }
    }
}

/**
 * @brief Le um valor de dominio Tempo (inteiro de 1 a 365).
 * @return false em caso de fim de entrada.
 */
static bool lerTempo(const string& rotulo, Tempo& tempo) {
    while (true) {
        string linha;
        if (!lerLinha(rotulo, linha))
            return false;
        try {
            tempo.setValor(stoi(linha));
            return true;
        } catch (const invalid_argument&) {
            cout << "  [formato invalido] informe um numero inteiro de 1 a 365." << endl;
        } catch (const out_of_range&) {
            cout << "  [formato invalido] informe um numero inteiro de 1 a 365." << endl;
        }
    }
}

/**
 * @brief Le a opcao de menu escolhida pelo usuario.
 * @return o numero da opcao, ou -1 em caso de fim de entrada.
 */
static int lerOpcao(const string& rotulo) {
    string linha;
    if (!lerLinha(rotulo, linha))
        return -1;
    try {
        return stoi(linha);
    } catch (...) {
        return -2; // opcao invalida
    }
}

// ===========================================================================
//  CntrIUAutenticacao
// ===========================================================================

bool CntrIUAutenticacao::autenticar(Email* emailAutenticado) {
    Email email;
    Senha senha;

    cout << "\n--- Autenticacao ---\n";
    if (!lerDominio("Email: ", email))
        return false;
    if (!lerDominio("Senha: ", senha))
        return false;

    bool ok = cntrLNAutenticacao->autenticar(email, senha);
    if (ok)
        *emailAutenticado = email;
    return ok;
}

// ===========================================================================
//  CntrIUPessoa
// ===========================================================================

static void apresentarPessoa(const Pessoa& p) {
    cout << "  Email: " << p.getEmail().getValor() << "\n"
         << "  Nome : " << p.getNome().getValor() << "\n"
         << "  Papel: " << p.getPapel().getValor() << "\n";
}

void CntrIUPessoa::cadastrar() {
    Pessoa pessoa;
    Email email; Nome nome; Senha senha; Papel papel;
    cout << "\n--- Criar conta ---\n";
    if (!lerDominio("Email: ", email)) return;
    if (!lerDominio("Nome: ", nome)) return;
    if (!lerDominio("Senha: ", senha)) return;
    if (!lerDominio("Papel (DESENVOLVEDOR / MESTRE SCRUM / PROPRIETARIO DE PRODUTO): ", papel)) return;
    pessoa.setEmail(email); pessoa.setNome(nome);
    pessoa.setSenha(senha); pessoa.setPapel(papel);
    cout << (cntrLNPessoa->criar(pessoa) ? "Conta criada com sucesso. Faca login para entrar.\n"
                                         : "Falha: ja existe pessoa com este email.\n");
}

void CntrIUPessoa::executar(const Email&) {
    int opcao;
    do {
        cout << "\n=== Pessoa ===\n"
             << "1 - Criar\n2 - Ler\n3 - Atualizar\n4 - Excluir\n5 - Listar\n0 - Voltar\n";
        opcao = lerOpcao("Opcao: ");

        if (opcao == 1) {
            cadastrar();
        } else if (opcao == 2) {
            Pessoa pessoa; Email email;
            if (!lerDominio("Email da pessoa: ", email)) return;
            pessoa.setEmail(email);
            if (cntrLNPessoa->ler(&pessoa)) apresentarPessoa(pessoa);
            else cout << "Pessoa nao encontrada.\n";
        } else if (opcao == 3) {
            Pessoa pessoa; Email email;
            if (!lerDominio("Email da pessoa a atualizar: ", email)) return;
            pessoa.setEmail(email);
            if (!cntrLNPessoa->ler(&pessoa)) { cout << "Pessoa nao encontrada.\n"; continue; }
            Nome nome; Senha senha; Papel papel;
            if (!lerDominio("Novo nome: ", nome)) return;
            if (!lerDominio("Nova senha: ", senha)) return;
            if (!lerDominio("Novo papel: ", papel)) return;
            pessoa.setNome(nome); pessoa.setSenha(senha); pessoa.setPapel(papel);
            cout << (cntrLNPessoa->atualizar(pessoa) ? "Pessoa atualizada.\n" : "Falha ao atualizar.\n");
        } else if (opcao == 4) {
            Email email;
            if (!lerDominio("Email da pessoa a excluir: ", email)) return;
            cout << (cntrLNPessoa->excluir(email) ? "Pessoa excluida.\n" : "Pessoa nao encontrada.\n");
        } else if (opcao == 5) {
            list<Pessoa> pessoas = cntrLNPessoa->listar();
            cout << "Total: " << pessoas.size() << "\n";
            for (list<Pessoa>::iterator it = pessoas.begin(); it != pessoas.end(); ++it)
                cout << "  - " << it->getEmail().getValor() << " (" << it->getNome().getValor() << ")\n";
        } else if (opcao == -1) {
            return;
        }
    } while (opcao != 0);
}

// ===========================================================================
//  CntrIUProjeto
// ===========================================================================

static void apresentarProjeto(const Projeto& p) {
    cout << "  Codigo : " << p.getCodigo().getValor() << "\n"
         << "  Nome   : " << p.getNome().getValor() << "\n"
         << "  Inicio : " << p.getInicio().getValor() << "\n"
         << "  Termino: " << p.getTermino().getValor() << "\n";
}

void CntrIUProjeto::executar(const Email&) {
    int opcao;
    do {
        cout << "\n=== Projeto ===\n"
             << "1 - Criar\n2 - Ler\n3 - Atualizar\n4 - Excluir\n5 - Listar\n"
             << "6 - Listar por pessoa\n0 - Voltar\n";
        opcao = lerOpcao("Opcao: ");

        if (opcao == 1) {
            Projeto projeto;
            Codigo codigo; Nome nome; Data inicio, termino; Email proprietario, mestre;
            if (!lerDominio("Codigo: ", codigo)) return;
            if (!lerDominio("Nome: ", nome)) return;
            if (!lerDominio("Inicio (DD/MM/AAAA): ", inicio)) return;
            if (!lerDominio("Termino (DD/MM/AAAA): ", termino)) return;
            if (!lerDominio("Email do proprietario de produto: ", proprietario)) return;
            if (!lerDominio("Email do mestre scrum: ", mestre)) return;
            projeto.setCodigo(codigo); projeto.setNome(nome);
            projeto.setInicio(inicio); projeto.setTermino(termino);
            cout << (cntrLNProjeto->criar(projeto, proprietario, mestre)
                     ? "Projeto criado com sucesso.\n"
                     : "Falha: codigo ja existe ou pessoas/papeis invalidos.\n");
        } else if (opcao == 2) {
            Projeto projeto; Codigo codigo;
            if (!lerDominio("Codigo do projeto: ", codigo)) return;
            projeto.setCodigo(codigo);
            if (cntrLNProjeto->ler(&projeto)) apresentarProjeto(projeto);
            else cout << "Projeto nao encontrado.\n";
        } else if (opcao == 3) {
            Projeto projeto; Codigo codigo;
            if (!lerDominio("Codigo do projeto a atualizar: ", codigo)) return;
            projeto.setCodigo(codigo);
            if (!cntrLNProjeto->ler(&projeto)) { cout << "Projeto nao encontrado.\n"; continue; }
            Nome nome; Data inicio, termino;
            if (!lerDominio("Novo nome: ", nome)) return;
            if (!lerDominio("Novo inicio (DD/MM/AAAA): ", inicio)) return;
            if (!lerDominio("Novo termino (DD/MM/AAAA): ", termino)) return;
            projeto.setNome(nome); projeto.setInicio(inicio); projeto.setTermino(termino);
            cout << (cntrLNProjeto->atualizar(projeto) ? "Projeto atualizado.\n" : "Falha ao atualizar.\n");
        } else if (opcao == 4) {
            Codigo codigo;
            if (!lerDominio("Codigo do projeto a excluir: ", codigo)) return;
            cout << (cntrLNProjeto->excluir(codigo) ? "Projeto excluido.\n" : "Projeto nao encontrado.\n");
        } else if (opcao == 5) {
            list<Projeto> projetos = cntrLNProjeto->listar();
            cout << "Total: " << projetos.size() << "\n";
            for (list<Projeto>::iterator it = projetos.begin(); it != projetos.end(); ++it)
                cout << "  - " << it->getCodigo().getValor() << " (" << it->getNome().getValor() << ")\n";
        } else if (opcao == 6) {
            Email email;
            if (!lerDominio("Email da pessoa: ", email)) return;
            list<Projeto> projetos = cntrLNProjeto->listarPorPessoa(email);
            cout << "Total: " << projetos.size() << "\n";
            for (list<Projeto>::iterator it = projetos.begin(); it != projetos.end(); ++it)
                cout << "  - " << it->getCodigo().getValor() << " (" << it->getNome().getValor() << ")\n";
        } else if (opcao == -1) {
            return;
        }
    } while (opcao != 0);
}

// ===========================================================================
//  CntrIUPlanoSprint
// ===========================================================================

static void apresentarPlano(const PlanoSprint& p) {
    cout << "  Codigo    : " << p.getCodigo().getValor() << "\n"
         << "  Objetivo  : " << p.getObjetivo().getValor() << "\n"
         << "  Capacidade: " << p.getCapacidade().getValor() << "\n";
}

void CntrIUPlanoSprint::executar(const Email&) {
    int opcao;
    do {
        cout << "\n=== Plano de Sprint ===\n"
             << "1 - Criar\n2 - Ler\n3 - Atualizar\n4 - Excluir\n5 - Listar\n"
             << "6 - Listar por projeto\n0 - Voltar\n";
        opcao = lerOpcao("Opcao: ");

        if (opcao == 1) {
            PlanoSprint plano;
            Codigo codigo; Texto objetivo; Tempo capacidade; Codigo projeto;
            if (!lerDominio("Codigo: ", codigo)) return;
            if (!lerDominio("Objetivo: ", objetivo)) return;
            if (!lerTempo("Capacidade (1-365): ", capacidade)) return;
            if (!lerDominio("Codigo do projeto associado: ", projeto)) return;
            plano.setCodigo(codigo); plano.setObjetivo(objetivo); plano.setCapacidade(capacidade);
            cout << (cntrLNPlanoSprint->criar(plano, projeto)
                     ? "Plano de sprint criado com sucesso.\n"
                     : "Falha: codigo ja existe, projeto inexistente ou capacidade excedida.\n");
        } else if (opcao == 2) {
            PlanoSprint plano; Codigo codigo;
            if (!lerDominio("Codigo do plano: ", codigo)) return;
            plano.setCodigo(codigo);
            if (cntrLNPlanoSprint->ler(&plano)) apresentarPlano(plano);
            else cout << "Plano nao encontrado.\n";
        } else if (opcao == 3) {
            PlanoSprint plano; Codigo codigo;
            if (!lerDominio("Codigo do plano a atualizar: ", codigo)) return;
            plano.setCodigo(codigo);
            if (!cntrLNPlanoSprint->ler(&plano)) { cout << "Plano nao encontrado.\n"; continue; }
            Texto objetivo; Tempo capacidade;
            if (!lerDominio("Novo objetivo: ", objetivo)) return;
            if (!lerTempo("Nova capacidade (1-365): ", capacidade)) return;
            plano.setObjetivo(objetivo); plano.setCapacidade(capacidade);
            cout << (cntrLNPlanoSprint->atualizar(plano) ? "Plano atualizado.\n" : "Falha ao atualizar.\n");
        } else if (opcao == 4) {
            Codigo codigo;
            if (!lerDominio("Codigo do plano a excluir: ", codigo)) return;
            cout << (cntrLNPlanoSprint->excluir(codigo) ? "Plano excluido.\n" : "Plano nao encontrado.\n");
        } else if (opcao == 5) {
            list<PlanoSprint> planos = cntrLNPlanoSprint->listar();
            cout << "Total: " << planos.size() << "\n";
            for (list<PlanoSprint>::iterator it = planos.begin(); it != planos.end(); ++it)
                cout << "  - " << it->getCodigo().getValor() << " (cap " << it->getCapacidade().getValor() << ")\n";
        } else if (opcao == 6) {
            Codigo projeto;
            if (!lerDominio("Codigo do projeto: ", projeto)) return;
            list<PlanoSprint> planos = cntrLNPlanoSprint->listarPorProjeto(projeto);
            cout << "Total: " << planos.size() << "\n";
            for (list<PlanoSprint>::iterator it = planos.begin(); it != planos.end(); ++it)
                cout << "  - " << it->getCodigo().getValor() << "\n";
        } else if (opcao == -1) {
            return;
        }
    } while (opcao != 0);
}

// ===========================================================================
//  CntrIUHistoriaUsuario
// ===========================================================================

static void apresentarHistoria(const HistoriaUsuario& h) {
    cout << "  Codigo    : " << h.getCodigo().getValor() << "\n"
         << "  Titulo    : " << h.getTitulo().getValor() << "\n"
         << "  Papel     : " << h.getPapel().getValor() << "\n"
         << "  Acao      : " << h.getAcao().getValor() << "\n"
         << "  Valor     : " << h.getValor().getValor() << "\n"
         << "  Estimativa: " << h.getEstimativa().getValor() << "\n"
         << "  Prioridade: " << h.getPrioridade().getValor() << "\n"
         << "  Estado    : " << h.getEstado().getValor() << "\n";
}

void CntrIUHistoriaUsuario::executar(const Email&) {
    int opcao;
    do {
        cout << "\n=== Historia de Usuario ===\n"
             << "1 - Criar\n2 - Ler\n3 - Atualizar\n4 - Excluir\n5 - Listar\n"
             << "6 - Listar por projeto\n7 - Listar por plano de sprint\n"
             << "8 - Alterar estado\n9 - Mover para plano de sprint\n"
             << "10 - Associar pessoa\n11 - Remover associacao de pessoa\n"
             << "12 - Listar por pessoa\n0 - Voltar\n";
        opcao = lerOpcao("Opcao: ");

        if (opcao == 1) {
            HistoriaUsuario historia;
            Codigo codigo; Texto titulo, papel, acao, valor; Tempo estimativa;
            Prioridade prioridade; Estado estado; Codigo projeto;
            if (!lerDominio("Codigo: ", codigo)) return;
            if (!lerDominio("Titulo: ", titulo)) return;
            if (!lerDominio("Papel (como...): ", papel)) return;
            if (!lerDominio("Acao (eu quero...): ", acao)) return;
            if (!lerDominio("Valor (para...): ", valor)) return;
            if (!lerTempo("Estimativa (1-365): ", estimativa)) return;
            if (!lerDominio("Prioridade (ALTA / MEDIA / BAIXA): ", prioridade)) return;
            if (!lerDominio("Codigo do projeto associado: ", projeto)) return;
            estado.setValor("A FAZER"); // ao criar, o estado e sempre A FAZER
            historia.setCodigo(codigo); historia.setTitulo(titulo); historia.setPapel(papel);
            historia.setAcao(acao); historia.setValor(valor); historia.setEstimativa(estimativa);
            historia.setPrioridade(prioridade); historia.setEstado(estado);
            cout << (cntrLNHistoriaUsuario->criar(historia, projeto)
                     ? "Historia criada com sucesso (estado: A FAZER).\n"
                     : "Falha: codigo ja existe ou projeto inexistente.\n");
        } else if (opcao == 2) {
            HistoriaUsuario historia; Codigo codigo;
            if (!lerDominio("Codigo da historia: ", codigo)) return;
            historia.setCodigo(codigo);
            if (cntrLNHistoriaUsuario->ler(&historia)) apresentarHistoria(historia);
            else cout << "Historia nao encontrada.\n";
        } else if (opcao == 3) {
            HistoriaUsuario historia; Codigo codigo;
            if (!lerDominio("Codigo da historia a atualizar: ", codigo)) return;
            historia.setCodigo(codigo);
            if (!cntrLNHistoriaUsuario->ler(&historia)) { cout << "Historia nao encontrada.\n"; continue; }
            Texto titulo, papel, acao, valor; Tempo estimativa; Prioridade prioridade;
            if (!lerDominio("Novo titulo: ", titulo)) return;
            if (!lerDominio("Novo papel: ", papel)) return;
            if (!lerDominio("Nova acao: ", acao)) return;
            if (!lerDominio("Novo valor: ", valor)) return;
            if (!lerTempo("Nova estimativa (1-365): ", estimativa)) return;
            if (!lerDominio("Nova prioridade: ", prioridade)) return;
            historia.setTitulo(titulo); historia.setPapel(papel); historia.setAcao(acao);
            historia.setValor(valor); historia.setEstimativa(estimativa); historia.setPrioridade(prioridade);
            cout << (cntrLNHistoriaUsuario->atualizar(historia) ? "Historia atualizada.\n" : "Falha ao atualizar.\n");
        } else if (opcao == 4) {
            Codigo codigo;
            if (!lerDominio("Codigo da historia a excluir: ", codigo)) return;
            cout << (cntrLNHistoriaUsuario->excluir(codigo) ? "Historia excluida.\n" : "Historia nao encontrada.\n");
        } else if (opcao == 5) {
            list<HistoriaUsuario> hs = cntrLNHistoriaUsuario->listar();
            cout << "Total: " << hs.size() << "\n";
            for (list<HistoriaUsuario>::iterator it = hs.begin(); it != hs.end(); ++it)
                cout << "  - " << it->getCodigo().getValor() << " [" << it->getEstado().getValor() << "]\n";
        } else if (opcao == 6) {
            Codigo projeto;
            if (!lerDominio("Codigo do projeto: ", projeto)) return;
            list<HistoriaUsuario> hs = cntrLNHistoriaUsuario->listarPorProjeto(projeto);
            cout << "Total: " << hs.size() << "\n";
            for (list<HistoriaUsuario>::iterator it = hs.begin(); it != hs.end(); ++it)
                cout << "  - " << it->getCodigo().getValor() << "\n";
        } else if (opcao == 7) {
            Codigo plano;
            if (!lerDominio("Codigo do plano de sprint: ", plano)) return;
            list<HistoriaUsuario> hs = cntrLNHistoriaUsuario->listarPorPlanoSprint(plano);
            cout << "Total: " << hs.size() << "\n";
            for (list<HistoriaUsuario>::iterator it = hs.begin(); it != hs.end(); ++it)
                cout << "  - " << it->getCodigo().getValor() << "\n";
        } else if (opcao == 8) {
            Codigo codigo; Estado estado;
            if (!lerDominio("Codigo da historia: ", codigo)) return;
            if (!lerDominio("Novo estado (A FAZER / FAZENDO / FEITO): ", estado)) return;
            cout << (cntrLNHistoriaUsuario->alterarEstado(codigo, estado)
                     ? "Estado alterado.\n" : "Historia nao encontrada.\n");
        } else if (opcao == 9) {
            Codigo historia, plano;
            if (!lerDominio("Codigo da historia: ", historia)) return;
            if (!lerDominio("Codigo do plano de sprint destino: ", plano)) return;
            cout << (cntrLNHistoriaUsuario->moverParaSprint(historia, plano)
                     ? "Historia movida para o plano de sprint.\n"
                     : "Falha: historia/plano inexistente ou capacidade excedida.\n");
        } else if (opcao == 10) {
            Codigo historia; Email pessoa;
            if (!lerDominio("Codigo da historia: ", historia)) return;
            if (!lerDominio("Email da pessoa: ", pessoa)) return;
            cout << (cntrLNHistoriaUsuario->associarPessoa(historia, pessoa)
                     ? "Pessoa associada a historia.\n"
                     : "Falha: historia/pessoa inexistente ou ja associada.\n");
        } else if (opcao == 11) {
            Codigo historia; Email pessoa;
            if (!lerDominio("Codigo da historia: ", historia)) return;
            if (!lerDominio("Email da pessoa: ", pessoa)) return;
            cout << (cntrLNHistoriaUsuario->desassociarPessoa(historia, pessoa)
                     ? "Associacao removida.\n" : "Associacao nao encontrada.\n");
        } else if (opcao == 12) {
            Email pessoa;
            if (!lerDominio("Email da pessoa: ", pessoa)) return;
            list<HistoriaUsuario> hs = cntrLNHistoriaUsuario->listarPorPessoa(pessoa);
            cout << "Total: " << hs.size() << "\n";
            for (list<HistoriaUsuario>::iterator it = hs.begin(); it != hs.end(); ++it)
                cout << "  - " << it->getCodigo().getValor() << "\n";
        } else if (opcao == -1) {
            return;
        }
    } while (opcao != 0);
}
