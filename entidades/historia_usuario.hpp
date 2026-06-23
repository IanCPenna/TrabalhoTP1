#ifndef HISTORIA_USUARIO_HPP_INCLUDED
#define HISTORIA_USUARIO_HPP_INCLUDED

#include "../dominios/codigo.hpp"
#include "../dominios/texto.hpp"
#include "../dominios/tempo.hpp"
#include "../dominios/prioridade.hpp"
#include "../dominios/estado.hpp"

class HistoriaUsuario {
private:
    Codigo codigo;
    Texto titulo;
    Texto papel;
    Texto acao;
    Texto valor;
    Tempo estimativa;
    Prioridade prioridade;
    Estado estado;

public:
    // Setters
    void setCodigo(const Codigo&);
    void setTitulo(const Texto&);
    void setPapel(const Texto&);
    void setAcao(const Texto&);
    void setValor(const Texto&);
    void setEstimativa(const Tempo&);
    void setPrioridade(const Prioridade&);
    void setEstado(const Estado&);

    // Getters
    Codigo getCodigo() const;
    Texto getTitulo() const;
    Texto getPapel() const;
    Texto getAcao() const;
    Texto getValor() const;
    Tempo getEstimativa() const;
    Prioridade getPrioridade() const;
    Estado getEstado() const;
};


// Setters

inline void HistoriaUsuario::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}
inline void HistoriaUsuario::setTitulo(const Texto& titulo) {
    this->titulo = titulo;
}
inline void HistoriaUsuario::setPapel(const Texto& papel) {
    this->papel = papel;
}
inline void HistoriaUsuario::setAcao(const Texto& acao) {
    this->acao = acao;
}
inline void HistoriaUsuario::setValor(const Texto& valor) {
    this->valor = valor;
}
inline void HistoriaUsuario::setEstimativa(const Tempo& estimativa) {
    this->estimativa = estimativa;
}
inline void HistoriaUsuario::setPrioridade(const Prioridade& prioridade) {
    this->prioridade = prioridade;
}
inline void HistoriaUsuario::setEstado(const Estado& estado) {
    this->estado = estado;
}


// Getters

inline Codigo HistoriaUsuario::getCodigo() const {
    return codigo;
}
inline Texto HistoriaUsuario::getTitulo() const {
    return titulo;
}
inline Texto HistoriaUsuario::getPapel() const {
    return papel;
}
inline Texto HistoriaUsuario::getAcao() const {
    return acao;
}
inline Texto HistoriaUsuario::getValor() const {
    return valor;
}
inline Tempo HistoriaUsuario::getEstimativa() const {
    return estimativa;
}
inline Prioridade HistoriaUsuario::getPrioridade() const {
    return prioridade;
}
inline Estado HistoriaUsuario::getEstado() const {
    return estado;
}

#endif // HISTORIA_USUARIO_HPP_INCLUDED
