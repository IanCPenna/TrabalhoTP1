#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include <list>

#include "entidades/Pessoa.hpp"
#include "entidades/Projeto.hpp"
#include "entidades/Plano_Sprint.hpp"
#include "entidades/historia_usuario.hpp"

using namespace std;

/**
 * @file containers.hpp
 * @brief Conteineres da camada de servico responsaveis por armazenar as
 *        entidades em memoria usando o template list.
 *
 * Cada conteiner oferece as operacoes basicas de manutencao: incluir, remover,
 * pesquisar e atualizar, identificando os elementos por sua chave primaria.
 */

/**
 * @class ContainerPessoa
 * @brief Armazena objetos Pessoa identificados pelo email.
 */
class ContainerPessoa {
private:
    list<Pessoa> elementos;
public:
    /** @brief Inclui uma pessoa. @return false se ja existe pessoa com o mesmo email. */
    bool incluir(const Pessoa& pessoa);
    /** @brief Remove a pessoa identificada pelo email. @return false se nao existe. */
    bool remover(const Email& email);
    /** @brief Pesquisa a pessoa cujo email esta preenchido em *pessoa. @return false se nao existe. */
    bool pesquisar(Pessoa* pessoa);
    /** @brief Atualiza os dados da pessoa (identificada pelo email). @return false se nao existe. */
    bool atualizar(const Pessoa& pessoa);
    /** @brief Retorna a lista de todas as pessoas armazenadas. */
    list<Pessoa> listar() const;
};

/**
 * @class ContainerProjeto
 * @brief Armazena objetos Projeto identificados pelo codigo.
 */
class ContainerProjeto {
private:
    list<Projeto> elementos;
public:
    bool incluir(const Projeto& projeto);
    bool remover(const Codigo& codigo);
    bool pesquisar(Projeto* projeto);
    bool atualizar(const Projeto& projeto);
    list<Projeto> listar() const;
};

/**
 * @class ContainerPlanoSprint
 * @brief Armazena objetos PlanoSprint identificados pelo codigo.
 */
class ContainerPlanoSprint {
private:
    list<PlanoSprint> elementos;
public:
    bool incluir(const PlanoSprint& plano);
    bool remover(const Codigo& codigo);
    bool pesquisar(PlanoSprint* plano);
    bool atualizar(const PlanoSprint& plano);
    list<PlanoSprint> listar() const;
};

/**
 * @class ContainerHistoriaUsuario
 * @brief Armazena objetos HistoriaUsuario identificados pelo codigo.
 */
class ContainerHistoriaUsuario {
private:
    list<HistoriaUsuario> elementos;
public:
    bool incluir(const HistoriaUsuario& historia);
    bool remover(const Codigo& codigo);
    bool pesquisar(HistoriaUsuario* historia);
    bool atualizar(const HistoriaUsuario& historia);
    list<HistoriaUsuario> listar() const;
};

#endif // CONTAINERS_HPP_INCLUDED
