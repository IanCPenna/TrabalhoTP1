#ifndef PROJETO_HPP_INCLUDED
#define PROJETO_HPP_INCLUDED

#include "../dominios/codigo.hpp"
#include "../dominios/nome.hpp"
#include "../dominios/data.hpp"

class Projeto {
private:
    Codigo codigo;
    Nome nome;
    Data inicio;
    Data termino;

public:
    // Setters
    void setCodigo(const Codigo&);
    void setNome(const Nome&);
    void setInicio(const Data&);
    void setTermino(const Data&);

    // Getters
    Codigo getCodigo() const;
    Nome getNome() const;
    Data getInicio() const;
    Data getTermino() const;
};

// Setters
inline void Projeto::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}
inline void Projeto::setNome(const Nome& nome) {
    this->nome = nome;
}
inline void Projeto::setInicio(const Data& inicio) {
    this->inicio = inicio;
}
inline void Projeto::setTermino(const Data& termino) {
    this->termino = termino;
}

// Getters
inline Codigo Projeto::getCodigo() const {
    return codigo;
}
inline Nome Projeto::getNome() const {
    return nome;
}
inline Data Projeto::getInicio() const {
    return inicio;
}
inline Data Projeto::getTermino() const {
    return termino;
}

#endif // PROJETO_HPP_INCLUDED
