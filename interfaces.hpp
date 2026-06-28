#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include <list>

#include "entidades/Pessoa.hpp"
#include "entidades/Projeto.hpp"
#include "entidades/Plano_Sprint.hpp"
#include "entidades/historia_usuario.hpp"

using namespace std;

/**
 * @file interfaces.hpp
 * @brief Declaracao das interfaces que separam a camada de apresentacao da
 *        camada de servico.
 *
 * Cada interface e uma classe abstrata composta exclusivamente por metodos
 * virtuais puros. As interfaces com prefixo IU sao realizadas pela camada de
 * apresentacao; as interfaces com prefixo ILN sao realizadas pela camada de
 * servico (logica de negocio). A comunicacao entre as camadas ocorre apenas
 * por meio de ponteiros para estas interfaces.
 */

// ===========================================================================
//  Modulo Autenticacao
// ===========================================================================

/**
 * @interface ILNAutenticacao
 * @brief Servico de autenticacao provido pela camada de logica de negocio.
 */
class ILNAutenticacao {
public:
    /**
     * @brief Verifica se existe uma pessoa cadastrada com o email e a senha informados.
     * @param email Email da pessoa.
     * @param senha Senha da pessoa.
     * @return true se as credenciais sao validas; false caso contrario.
     */
    virtual bool autenticar(const Email& email, const Senha& senha) = 0;
    virtual ~ILNAutenticacao() {}
};

/**
 * @interface IUAutenticacao
 * @brief Servico de autenticacao provido pela camada de apresentacao.
 */
class IUAutenticacao {
public:
    /**
     * @brief Conduz a interacao de login com o usuario.
     * @param emailAutenticado Ponteiro onde sera armazenado o email autenticado.
     * @return true se a autenticacao teve sucesso; false caso contrario.
     */
    virtual bool autenticar(Email* emailAutenticado) = 0;

    /**
     * @brief Liga esta controladora ao servico de autenticacao da camada de negocio.
     */
    virtual void setCntrLNAutenticacao(ILNAutenticacao* cntrLNAutenticacao) = 0;
    virtual ~IUAutenticacao() {}
};

// ===========================================================================
//  Modulo Pessoa
// ===========================================================================

/**
 * @interface ILNPessoa
 * @brief Servicos de manutencao de pessoas providos pela camada de negocio.
 */
class ILNPessoa {
public:
    /** @brief Cria (cadastra) uma nova pessoa. @return false se o email ja existe. */
    virtual bool criar(const Pessoa& pessoa) = 0;
    /** @brief Le os dados da pessoa cujo email esta preenchido em *pessoa. */
    virtual bool ler(Pessoa* pessoa) = 0;
    /** @brief Atualiza os dados da pessoa (a chave email nao e alterada). */
    virtual bool atualizar(const Pessoa& pessoa) = 0;
    /** @brief Exclui a pessoa identificada pelo email. */
    virtual bool excluir(const Email& email) = 0;
    /** @brief Retorna a lista de todas as pessoas cadastradas. */
    virtual list<Pessoa> listar() = 0;
    virtual ~ILNPessoa() {}
};

/**
 * @interface IUPessoa
 * @brief Apresentacao dos servicos de pessoa ao usuario.
 */
class IUPessoa {
public:
    /** @brief Exibe o menu de servicos da entidade Pessoa (servicos liberados a qualquer papel). */
    virtual void executar(const Papel& papelUsuario) = 0;
    /** @brief Conduz a criacao de conta (cadastro) de um novo usuario, antes do login. */
    virtual void cadastrar() = 0;
    virtual void setCntrLNPessoa(ILNPessoa* cntrLNPessoa) = 0;
    virtual ~IUPessoa() {}
};

// ===========================================================================
//  Modulo Projeto
// ===========================================================================

/**
 * @interface ILNProjeto
 * @brief Servicos de manutencao de projetos providos pela camada de negocio.
 */
class ILNProjeto {
public:
    /**
     * @brief Cria um projeto associado a um proprietario e a um mestre scrum.
     * @param solicitante Papel do usuario que solicita o servico (deve ser PROPRIETARIO DE PRODUTO).
     * @return false se o codigo ja existe ou se as pessoas associadas nao existem.
     * @throw runtime_error se o solicitante nao tem permissao para o servico.
     */
    virtual bool criar(const Projeto& projeto, const Email& proprietario, const Email& mestreScrum, const Papel& solicitante) = 0;
    virtual bool ler(Projeto* projeto) = 0;
    virtual bool atualizar(const Projeto& projeto, const Papel& solicitante) = 0;
    virtual bool excluir(const Codigo& codigo, const Papel& solicitante) = 0;
    virtual list<Projeto> listar() = 0;
    /** @brief Lista os projetos associados a uma pessoa (proprietario, mestre ou desenvolvedor). */
    virtual list<Projeto> listarPorPessoa(const Email& email) = 0;
    virtual ~ILNProjeto() {}
};

/**
 * @interface IUProjeto
 * @brief Apresentacao dos servicos de projeto ao usuario.
 */
class IUProjeto {
public:
    virtual void executar(const Papel& papelUsuario) = 0;
    virtual void setCntrLNProjeto(ILNProjeto* cntrLNProjeto) = 0;
    virtual ~IUProjeto() {}
};

// ===========================================================================
//  Modulo Plano de Sprint
// ===========================================================================

/**
 * @interface ILNPlanoSprint
 * @brief Servicos de manutencao de planos de sprint providos pela camada de negocio.
 */
class ILNPlanoSprint {
public:
    /**
     * @brief Cria um plano de sprint associado a um projeto.
     * @param solicitante Papel do usuario que solicita o servico (deve ser MESTRE SCRUM).
     * @return false se o codigo ja existe, o projeto nao existe ou a soma das
     *         capacidades excede o numero de dias do projeto.
     * @throw runtime_error se o solicitante nao tem permissao para o servico.
     */
    virtual bool criar(const PlanoSprint& plano, const Codigo& projeto, const Papel& solicitante) = 0;
    virtual bool ler(PlanoSprint* plano) = 0;
    virtual bool atualizar(const PlanoSprint& plano, const Papel& solicitante) = 0;
    virtual bool excluir(const Codigo& codigo, const Papel& solicitante) = 0;
    virtual list<PlanoSprint> listar() = 0;
    /** @brief Lista os planos de sprint associados a um projeto. */
    virtual list<PlanoSprint> listarPorProjeto(const Codigo& projeto) = 0;
    virtual ~ILNPlanoSprint() {}
};

/**
 * @interface IUPlanoSprint
 * @brief Apresentacao dos servicos de plano de sprint ao usuario.
 */
class IUPlanoSprint {
public:
    virtual void executar(const Papel& papelUsuario) = 0;
    virtual void setCntrLNPlanoSprint(ILNPlanoSprint* cntrLNPlanoSprint) = 0;
    virtual ~IUPlanoSprint() {}
};

// ===========================================================================
//  Modulo Historia de Usuario
// ===========================================================================

/**
 * @interface ILNHistoriaUsuario
 * @brief Servicos de manutencao de historias de usuario providos pela camada de negocio.
 */
class ILNHistoriaUsuario {
public:
    /**
     * @brief Cria uma historia de usuario associada a um projeto, com estado A FAZER.
     * @return false se o codigo ja existe ou o projeto nao existe.
     */
    virtual bool criar(const HistoriaUsuario& historia, const Codigo& projeto, const Papel& solicitante) = 0;
    virtual bool ler(HistoriaUsuario* historia) = 0;
    virtual bool atualizar(const HistoriaUsuario& historia, const Papel& solicitante) = 0;
    virtual bool excluir(const Codigo& codigo, const Papel& solicitante) = 0;
    virtual list<HistoriaUsuario> listar() = 0;
    /** @brief Lista as historias de usuario associadas a um projeto. */
    virtual list<HistoriaUsuario> listarPorProjeto(const Codigo& projeto) = 0;
    /** @brief Lista as historias de usuario associadas a um plano de sprint. */
    virtual list<HistoriaUsuario> listarPorPlanoSprint(const Codigo& plano) = 0;
    /** @brief Altera o estado de uma historia de usuario (PROPRIETARIO DE PRODUTO ou MESTRE SCRUM). */
    virtual bool alterarEstado(const Codigo& historia, const Estado& novoEstado, const Papel& solicitante) = 0;
    /**
     * @brief Move uma historia de usuario de um projeto para um plano de sprint (MESTRE SCRUM).
     * @return false se a soma das estimativas exceder a capacidade do plano.
     */
    virtual bool moverParaSprint(const Codigo& historia, const Codigo& plano, const Papel& solicitante) = 0;
    /**
     * @brief Estabelece associacao entre uma historia de usuario e uma pessoa (MESTRE SCRUM).
     * @return false se a historia ou a pessoa nao existem, ou se ja estao associadas.
     */
    virtual bool associarPessoa(const Codigo& historia, const Email& pessoa, const Papel& solicitante) = 0;
    /**
     * @brief Remove a associacao entre uma historia de usuario e uma pessoa (MESTRE SCRUM).
     * @return false se a associacao nao existe.
     */
    virtual bool desassociarPessoa(const Codigo& historia, const Email& pessoa, const Papel& solicitante) = 0;
    /** @brief Lista as historias de usuario associadas a uma pessoa. */
    virtual list<HistoriaUsuario> listarPorPessoa(const Email& pessoa) = 0;
    virtual ~ILNHistoriaUsuario() {}
};

/**
 * @interface IUHistoriaUsuario
 * @brief Apresentacao dos servicos de historia de usuario ao usuario.
 */
class IUHistoriaUsuario {
public:
    virtual void executar(const Papel& papelUsuario) = 0;
    virtual void setCntrLNHistoriaUsuario(ILNHistoriaUsuario* cntrLNHistoriaUsuario) = 0;
    virtual ~IUHistoriaUsuario() {}
};

#endif // INTERFACES_HPP_INCLUDED
