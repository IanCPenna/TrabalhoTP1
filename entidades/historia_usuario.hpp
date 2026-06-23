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


#endif // HISTORIA_USUARIO_HPP_INCLUDED
