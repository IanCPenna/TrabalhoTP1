#ifndef PLANO_SPRINT_HPP_INCLUDED
#define PLANO_SPRINT_HPP_INCLUDED

#include "../dominios/codigo.hpp"
#include "../dominios/texto.hpp"
#include "../dominios/tempo.hpp"

class PlanoSprint{
private:
    Codigo codigo;
    Texto objetivo;
    Tempo capacidade;
public:
    // Setters
    void setCodigo(const Codigo&);
    void setObjetivo(const Texto&);
    void setCapacidade(const Tempo&);

    // Getters
    Codigo getCodigo() const;
    Texto getObjetivo() const;
    Tempo getCapacidade() const;
};


// Setters

inline void PlanoSprint::setCodigo(const Codigo& codigo) {
    this->codigo = codigo;
}
inline void PlanoSprint::setObjetivo(const Texto& objetivo) {
    this->objetivo = objetivo;
}
inline void PlanoSprint::setCapacidade(const Tempo& capacidade) {
    this->capacidade = capacidade;
}


// Getters

inline Codigo PlanoSprint::getCodigo() const {
    return codigo;
}
inline Texto PlanoSprint::getObjetivo() const {
    return objetivo;
}
inline Tempo PlanoSprint::getCapacidade() const {
    return capacidade;
}


#endif // PLANO_SPRINT_HPP_INCLUDED
