#ifndef PESSOA_HPP_INCLUDED
#define PESSOA_HPP_INCLUDED

#include "../dominios/email.hpp"
#include "../dominios/nome.hpp"
#include "../dominios/senha.hpp"
#include "../dominios/papel.hpp"

/**
 * @class Pessoa
 * @brief Entidade que representa um usuario do sistema.
 *
 * Uma Pessoa e composta por quatro objetos de dominio: o email, que e a
 * chave primaria da entidade, o nome, a senha e o papel desempenhado no
 * projeto (Proprietario de Produto, Mestre Scrum ou Desenvolvedor).
 * O acesso a cada atributo e feito exclusivamente por meio dos metodos
 * publicos set e get. A validacao de formato de cada valor e
 * responsabilidade da respectiva classe de dominio.
 */
class Pessoa {
private:
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;

public:
    /**
     * @brief Armazena o email da pessoa.
     * @param email Objeto Email, ja validado, a ser armazenado.
     */
    void setEmail(const Email& email);

    /**
     * @brief Armazena o nome da pessoa.
     * @param nome Objeto Nome, ja validado, a ser armazenado.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Armazena a senha da pessoa.
     * @param senha Objeto Senha, ja validado, a ser armazenado.
     */
    void setSenha(const Senha& senha);

    /**
     * @brief Armazena o papel da pessoa no projeto.
     * @param papel Objeto Papel, ja validado, a ser armazenado.
     */
    void setPapel(const Papel& papel);

    /**
     * @brief Recupera o email armazenado.
     * @return Objeto Email da pessoa.
     */
    Email getEmail() const;

    /**
     * @brief Recupera o nome armazenado.
     * @return Objeto Nome da pessoa.
     */
    Nome getNome() const;

    /**
     * @brief Recupera a senha armazenada.
     * @return Objeto Senha da pessoa.
     */
    Senha getSenha() const;

    /**
     * @brief Recupera o papel armazenado.
     * @return Objeto Papel da pessoa.
     */
    Papel getPapel() const;
};

// Setters

inline void Pessoa::setEmail(const Email& email) {
    this->email = email;
}
inline void Pessoa::setNome(const Nome& nome) {
    this->nome = nome;
}
inline void Pessoa::setSenha(const Senha& senha) {
    this->senha = senha;
}
inline void Pessoa::setPapel(const Papel& papel) {
    this->papel = papel;
}

// Getters

inline Email Pessoa::getEmail() const {
    return email;
}
inline Nome Pessoa::getNome() const {
    return nome;
}
inline Senha Pessoa::getSenha() const {
    return senha;
}
inline Papel Pessoa::getPapel() const {
    return papel;
}

#endif // PESSOA_HPP_INCLUDED
