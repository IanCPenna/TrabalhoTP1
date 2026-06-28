#ifndef CONTROLADORAS_SERVICO_HPP_INCLUDED
#define CONTROLADORAS_SERVICO_HPP_INCLUDED

#include <map>

#include "interfaces.hpp"
#include "containers.hpp"

using namespace std;

/**
 * @file controladoras_servico.hpp
 * @brief Controladoras da camada de servico (logica de negocio).
 *
 * Cada controladora realiza a interface ILN correspondente, armazena as
 * entidades em seu conteiner e aplica as regras de negocio do sistema. As
 * associacoes entre entidades sao mantidas em estruturas auxiliares indexadas
 * pelas chaves primarias.
 */

/**
 * @class CntrLNPessoa
 * @brief Controladora de logica de negocio das pessoas e da autenticacao.
 *
 * Alem dos servicos de manutencao de pessoas, esta controladora realiza o
 * servico de autenticacao, verificando as credenciais contra as pessoas
 * cadastradas em seu proprio conteiner.
 */
class CntrLNPessoa : public ILNPessoa, public ILNAutenticacao {
private:
    ContainerPessoa container;
public:
    bool criar(const Pessoa& pessoa);
    bool ler(Pessoa* pessoa);
    bool atualizar(const Pessoa& pessoa);
    bool excluir(const Email& email);
    list<Pessoa> listar();

    bool autenticar(const Email& email, const Senha& senha);
};

/**
 * @class CntrLNProjeto
 * @brief Controladora de logica de negocio dos projetos.
 *
 * Mantem, para cada projeto, a associacao com o proprietario de produto e com
 * o mestre scrum. Depende da controladora de pessoas para validar a existencia
 * e o papel das pessoas associadas.
 */
class CntrLNProjeto : public ILNProjeto {
private:
    ContainerProjeto container;
    ILNPessoa* cntrLNPessoa;
    map<string, string> proprietarioDe; ///< codigoProjeto -> emailProprietario
    map<string, string> mestreDe;       ///< codigoProjeto -> emailMestreScrum
public:
    CntrLNProjeto() : cntrLNPessoa(0) {}
    void setCntrLNPessoa(ILNPessoa* cntr) { cntrLNPessoa = cntr; }

    bool criar(const Projeto& projeto, const Email& proprietario, const Email& mestreScrum);
    bool ler(Projeto* projeto);
    bool atualizar(const Projeto& projeto);
    bool excluir(const Codigo& codigo);
    list<Projeto> listar();
    list<Projeto> listarPorPessoa(const Email& email);
};

/**
 * @class CntrLNPlanoSprint
 * @brief Controladora de logica de negocio dos planos de sprint.
 *
 * Mantem a associacao de cada plano com seu projeto e garante que a soma das
 * capacidades dos planos de um projeto nao exceda o numero de dias entre as
 * datas de inicio e termino do projeto.
 */
class CntrLNPlanoSprint : public ILNPlanoSprint {
private:
    ContainerPlanoSprint container;
    ILNProjeto* cntrLNProjeto;
    map<string, string> planoDeProjeto; ///< codigoPlano -> codigoProjeto
public:
    CntrLNPlanoSprint() : cntrLNProjeto(0) {}
    void setCntrLNProjeto(ILNProjeto* cntr) { cntrLNProjeto = cntr; }

    bool criar(const PlanoSprint& plano, const Codigo& projeto);
    bool ler(PlanoSprint* plano);
    bool atualizar(const PlanoSprint& plano);
    bool excluir(const Codigo& codigo);
    list<PlanoSprint> listar();
    list<PlanoSprint> listarPorProjeto(const Codigo& projeto);

    /** @brief Retorna o codigo do projeto ao qual o plano esta associado (string vazia se nao houver). */
    string projetoDoPlano(const string& codigoPlano);
};

/**
 * @class CntrLNHistoriaUsuario
 * @brief Controladora de logica de negocio das historias de usuario.
 *
 * Mantem a associacao de cada historia com um projeto ou com um plano de
 * sprint (relacionamento exclusivo) e garante que a soma das estimativas das
 * historias de um plano nao exceda a capacidade do plano.
 */
class CntrLNHistoriaUsuario : public ILNHistoriaUsuario {
private:
    ContainerHistoriaUsuario container;
    ILNProjeto* cntrLNProjeto;
    ILNPlanoSprint* cntrLNPlanoSprint;
    ILNPessoa* cntrLNPessoa;
    CntrLNPlanoSprint* cntrLNPlanoSprintConcreto; ///< usado para consultar capacidade/associacao
    map<string, string> historiaDeProjeto; ///< codigoHistoria -> codigoProjeto
    map<string, string> historiaDeSprint;  ///< codigoHistoria -> codigoPlano
    multimap<string, string> historiaPessoa; ///< codigoHistoria -> emailPessoa (muitos-para-muitos)
public:
    CntrLNHistoriaUsuario() : cntrLNProjeto(0), cntrLNPlanoSprint(0), cntrLNPessoa(0), cntrLNPlanoSprintConcreto(0) {}
    void setCntrLNProjeto(ILNProjeto* cntr) { cntrLNProjeto = cntr; }
    void setCntrLNPessoa(ILNPessoa* cntr) { cntrLNPessoa = cntr; }
    void setCntrLNPlanoSprint(CntrLNPlanoSprint* cntr) {
        cntrLNPlanoSprint = cntr;
        cntrLNPlanoSprintConcreto = cntr;
    }

    bool criar(const HistoriaUsuario& historia, const Codigo& projeto);
    bool ler(HistoriaUsuario* historia);
    bool atualizar(const HistoriaUsuario& historia);
    bool excluir(const Codigo& codigo);
    list<HistoriaUsuario> listar();
    list<HistoriaUsuario> listarPorProjeto(const Codigo& projeto);
    list<HistoriaUsuario> listarPorPlanoSprint(const Codigo& plano);
    bool alterarEstado(const Codigo& historia, const Estado& novoEstado);
    bool moverParaSprint(const Codigo& historia, const Codigo& plano);
    bool associarPessoa(const Codigo& historia, const Email& pessoa);
    bool desassociarPessoa(const Codigo& historia, const Email& pessoa);
    list<HistoriaUsuario> listarPorPessoa(const Email& pessoa);
};

#endif // CONTROLADORAS_SERVICO_HPP_INCLUDED
