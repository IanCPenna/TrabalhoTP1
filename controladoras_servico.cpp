#include "controladoras_servico.hpp"

// ---------------------------------------------------------------------------
//  Funcao auxiliar: numero de dias entre duas datas no formato DD/MM/AAAA.
// ---------------------------------------------------------------------------

/**
 * @brief Converte uma data (ano, mes, dia) em um numero serial de dias.
 *
 * Algoritmo "days from civil" que permite calcular a diferenca em dias entre
 * duas datas por simples subtracao.
 */
static long diasSeriais(int ano, int mes, int dia) {
    ano -= mes <= 2;
    long era = (ano >= 0 ? ano : ano - 399) / 400;
    long yoe = ano - era * 400;
    long doy = (153 * (mes + (mes > 2 ? -3 : 9)) + 2) / 5 + dia - 1;
    long doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;
    return era * 146097 + doe - 719468;
}

/**
 * @brief Calcula o numero de dias entre as datas de inicio e termino.
 * @param inicio Data de inicio no formato DD/MM/AAAA.
 * @param termino Data de termino no formato DD/MM/AAAA.
 * @return Diferenca em dias (pode ser negativa se termino anteceder inicio).
 */
static long diasEntre(const string& inicio, const string& termino) {
    int di = stoi(inicio.substr(0, 2));
    int mi = stoi(inicio.substr(3, 2));
    int ai = stoi(inicio.substr(6, 4));
    int dt = stoi(termino.substr(0, 2));
    int mt = stoi(termino.substr(3, 2));
    int at = stoi(termino.substr(6, 4));
    return diasSeriais(at, mt, dt) - diasSeriais(ai, mi, di);
}

// ===========================================================================
//  CntrLNPessoa
// ===========================================================================

bool CntrLNPessoa::criar(const Pessoa& pessoa) {
    return container.incluir(pessoa);
}

bool CntrLNPessoa::ler(Pessoa* pessoa) {
    return container.pesquisar(pessoa);
}

bool CntrLNPessoa::atualizar(const Pessoa& pessoa) {
    return container.atualizar(pessoa);
}

bool CntrLNPessoa::excluir(const Email& email) {
    return container.remover(email);
}

list<Pessoa> CntrLNPessoa::listar() {
    return container.listar();
}

bool CntrLNPessoa::autenticar(const Email& email, const Senha& senha) {
    Pessoa pessoa;
    pessoa.setEmail(email);
    if (!container.pesquisar(&pessoa))
        return false;
    return pessoa.getSenha().getValor() == senha.getValor();
}

// ===========================================================================
//  CntrLNProjeto
// ===========================================================================

bool CntrLNProjeto::criar(const Projeto& projeto, const Email& proprietario, const Email& mestreScrum) {
    // Valida existencia e papel do proprietario de produto.
    Pessoa pProp;
    pProp.setEmail(proprietario);
    if (!cntrLNPessoa || !cntrLNPessoa->ler(&pProp))
        return false;
    if (pProp.getPapel().getValor() != "PROPRIETARIO DE PRODUTO")
        return false;

    // Valida existencia e papel do mestre scrum.
    Pessoa pMestre;
    pMestre.setEmail(mestreScrum);
    if (!cntrLNPessoa->ler(&pMestre))
        return false;
    if (pMestre.getPapel().getValor() != "MESTRE SCRUM")
        return false;

    if (!container.incluir(projeto))
        return false;

    proprietarioDe[projeto.getCodigo().getValor()] = proprietario.getValor();
    mestreDe[projeto.getCodigo().getValor()] = mestreScrum.getValor();
    return true;
}

bool CntrLNProjeto::ler(Projeto* projeto) {
    return container.pesquisar(projeto);
}

bool CntrLNProjeto::atualizar(const Projeto& projeto) {
    return container.atualizar(projeto);
}

bool CntrLNProjeto::excluir(const Codigo& codigo) {
    if (!container.remover(codigo))
        return false;
    proprietarioDe.erase(codigo.getValor());
    mestreDe.erase(codigo.getValor());
    return true;
}

list<Projeto> CntrLNProjeto::listar() {
    return container.listar();
}

list<Projeto> CntrLNProjeto::listarPorPessoa(const Email& email) {
    list<Projeto> resultado;
    string alvo = email.getValor();
    list<Projeto> todos = container.listar();
    for (list<Projeto>::iterator it = todos.begin(); it != todos.end(); ++it) {
        string cod = it->getCodigo().getValor();
        if (proprietarioDe[cod] == alvo || mestreDe[cod] == alvo)
            resultado.push_back(*it);
    }
    return resultado;
}

// ===========================================================================
//  CntrLNPlanoSprint
// ===========================================================================

bool CntrLNPlanoSprint::criar(const PlanoSprint& plano, const Codigo& projeto) {
    // Valida existencia do projeto.
    if (!cntrLNProjeto)
        return false;
    Projeto p;
    p.setCodigo(projeto);
    if (!cntrLNProjeto->ler(&p))
        return false;

    // Regra: soma das capacidades dos planos do projeto <= dias do projeto.
    long diasProjeto = diasEntre(p.getInicio().getValor(), p.getTermino().getValor());
    long somaCapacidades = plano.getCapacidade().getValor();
    list<PlanoSprint> todos = container.listar();
    for (list<PlanoSprint>::iterator it = todos.begin(); it != todos.end(); ++it) {
        if (planoDeProjeto[it->getCodigo().getValor()] == projeto.getValor())
            somaCapacidades += it->getCapacidade().getValor();
    }
    if (somaCapacidades > diasProjeto)
        return false;

    if (!container.incluir(plano))
        return false;

    planoDeProjeto[plano.getCodigo().getValor()] = projeto.getValor();
    return true;
}

bool CntrLNPlanoSprint::ler(PlanoSprint* plano) {
    return container.pesquisar(plano);
}

bool CntrLNPlanoSprint::atualizar(const PlanoSprint& plano) {
    return container.atualizar(plano);
}

bool CntrLNPlanoSprint::excluir(const Codigo& codigo) {
    if (!container.remover(codigo))
        return false;
    planoDeProjeto.erase(codigo.getValor());
    return true;
}

list<PlanoSprint> CntrLNPlanoSprint::listar() {
    return container.listar();
}

list<PlanoSprint> CntrLNPlanoSprint::listarPorProjeto(const Codigo& projeto) {
    list<PlanoSprint> resultado;
    list<PlanoSprint> todos = container.listar();
    for (list<PlanoSprint>::iterator it = todos.begin(); it != todos.end(); ++it) {
        if (planoDeProjeto[it->getCodigo().getValor()] == projeto.getValor())
            resultado.push_back(*it);
    }
    return resultado;
}

string CntrLNPlanoSprint::projetoDoPlano(const string& codigoPlano) {
    map<string, string>::iterator it = planoDeProjeto.find(codigoPlano);
    if (it == planoDeProjeto.end())
        return "";
    return it->second;
}

// ===========================================================================
//  CntrLNHistoriaUsuario
// ===========================================================================

bool CntrLNHistoriaUsuario::criar(const HistoriaUsuario& historia, const Codigo& projeto) {
    // Valida existencia do projeto.
    if (!cntrLNProjeto)
        return false;
    Projeto p;
    p.setCodigo(projeto);
    if (!cntrLNProjeto->ler(&p))
        return false;

    if (!container.incluir(historia))
        return false;

    historiaDeProjeto[historia.getCodigo().getValor()] = projeto.getValor();
    return true;
}

bool CntrLNHistoriaUsuario::ler(HistoriaUsuario* historia) {
    return container.pesquisar(historia);
}

bool CntrLNHistoriaUsuario::atualizar(const HistoriaUsuario& historia) {
    return container.atualizar(historia);
}

bool CntrLNHistoriaUsuario::excluir(const Codigo& codigo) {
    if (!container.remover(codigo))
        return false;
    historiaDeProjeto.erase(codigo.getValor());
    historiaDeSprint.erase(codigo.getValor());
    historiaPessoa.erase(codigo.getValor()); // remove todas as associacoes com pessoas
    return true;
}

list<HistoriaUsuario> CntrLNHistoriaUsuario::listar() {
    return container.listar();
}

list<HistoriaUsuario> CntrLNHistoriaUsuario::listarPorProjeto(const Codigo& projeto) {
    list<HistoriaUsuario> resultado;
    list<HistoriaUsuario> todos = container.listar();
    for (list<HistoriaUsuario>::iterator it = todos.begin(); it != todos.end(); ++it) {
        if (historiaDeProjeto[it->getCodigo().getValor()] == projeto.getValor())
            resultado.push_back(*it);
    }
    return resultado;
}

list<HistoriaUsuario> CntrLNHistoriaUsuario::listarPorPlanoSprint(const Codigo& plano) {
    list<HistoriaUsuario> resultado;
    list<HistoriaUsuario> todos = container.listar();
    for (list<HistoriaUsuario>::iterator it = todos.begin(); it != todos.end(); ++it) {
        if (historiaDeSprint[it->getCodigo().getValor()] == plano.getValor())
            resultado.push_back(*it);
    }
    return resultado;
}

bool CntrLNHistoriaUsuario::alterarEstado(const Codigo& historia, const Estado& novoEstado) {
    HistoriaUsuario h;
    h.setCodigo(historia);
    if (!container.pesquisar(&h))
        return false;
    h.setEstado(novoEstado);
    return container.atualizar(h);
}

bool CntrLNHistoriaUsuario::moverParaSprint(const Codigo& historia, const Codigo& plano) {
    // Valida existencia da historia.
    HistoriaUsuario h;
    h.setCodigo(historia);
    if (!container.pesquisar(&h))
        return false;

    // Valida existencia do plano e obtem sua capacidade.
    if (!cntrLNPlanoSprintConcreto)
        return false;
    PlanoSprint plS;
    plS.setCodigo(plano);
    if (!cntrLNPlanoSprintConcreto->ler(&plS))
        return false;

    // Regra: soma das estimativas das historias do plano <= capacidade do plano.
    long capacidade = plS.getCapacidade().getValor();
    long somaEstimativas = h.getEstimativa().getValor();
    list<HistoriaUsuario> todos = container.listar();
    for (list<HistoriaUsuario>::iterator it = todos.begin(); it != todos.end(); ++it) {
        if (historiaDeSprint[it->getCodigo().getValor()] == plano.getValor())
            somaEstimativas += it->getEstimativa().getValor();
    }
    if (somaEstimativas > capacidade)
        return false;

    // Move: remove associacao com projeto e cria associacao com o plano.
    historiaDeProjeto.erase(historia.getValor());
    historiaDeSprint[historia.getValor()] = plano.getValor();
    return true;
}

bool CntrLNHistoriaUsuario::associarPessoa(const Codigo& historia, const Email& pessoa) {
    // Valida existencia da historia.
    HistoriaUsuario h;
    h.setCodigo(historia);
    if (!container.pesquisar(&h))
        return false;

    // Valida existencia da pessoa.
    if (!cntrLNPessoa)
        return false;
    Pessoa p;
    p.setEmail(pessoa);
    if (!cntrLNPessoa->ler(&p))
        return false;

    // Evita associacao duplicada do mesmo par historia-pessoa.
    pair<multimap<string, string>::iterator, multimap<string, string>::iterator> faixa =
        historiaPessoa.equal_range(historia.getValor());
    for (multimap<string, string>::iterator it = faixa.first; it != faixa.second; ++it) {
        if (it->second == pessoa.getValor())
            return false;
    }

    historiaPessoa.insert(make_pair(historia.getValor(), pessoa.getValor()));
    return true;
}

bool CntrLNHistoriaUsuario::desassociarPessoa(const Codigo& historia, const Email& pessoa) {
    pair<multimap<string, string>::iterator, multimap<string, string>::iterator> faixa =
        historiaPessoa.equal_range(historia.getValor());
    for (multimap<string, string>::iterator it = faixa.first; it != faixa.second; ++it) {
        if (it->second == pessoa.getValor()) {
            historiaPessoa.erase(it);
            return true;
        }
    }
    return false;
}

list<HistoriaUsuario> CntrLNHistoriaUsuario::listarPorPessoa(const Email& pessoa) {
    list<HistoriaUsuario> resultado;
    string alvo = pessoa.getValor();
    for (multimap<string, string>::iterator it = historiaPessoa.begin(); it != historiaPessoa.end(); ++it) {
        if (it->second == alvo) {
            HistoriaUsuario h;
            Codigo c;
            c.setValor(it->first);
            h.setCodigo(c);
            if (container.pesquisar(&h))
                resultado.push_back(h);
        }
    }
    return resultado;
}
