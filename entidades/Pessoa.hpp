#ifndef PESSOA_HPP_INCLUDED
#define PESSOA_HPP_INCLUDED

#include "../dominios/email.hpp"
#include "../dominios/nome.hpp"
#include "../dominios/senha.hpp"
#include "../dominios/papel.hpp"

class Pessoa {
private:
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;

public:
    // Setters
    void setEmail(const Email&);
    void setNome(const Nome&);
    void setSenha(const Senha&);
    void setPapel(const Papel&);

    // Getters
    Email getEmail() const;
    Nome getNome() const;
    Senha getSenha() const;
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
