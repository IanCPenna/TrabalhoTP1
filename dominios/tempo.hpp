#ifndef TEMPO_HPP_INCLUDED
#define TEMPO_HPP_INCLUDED


#include "template_dominios.hpp"

class Tempo:public Dominio<int> {
    private:
        void validar(int);
};


#endif // TEMPO_HPP_INCLUDED
