#ifndef TEMPO_HPP_INCLUDED
#define TEMPO_HPP_INCLUDED

#include <cstdint>
#include "template_dominios.hpp"

class Tempo:public Dominio<int> {
    private:
        bool validar(int);
};


#endif // TEMPO_HPP_INCLUDED
