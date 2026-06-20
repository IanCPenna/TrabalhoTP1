#ifndef PRIORIDADE_HPP_INCLUDED
#define PRIORIDADE_HPP_INCLUDED

#include "template_dominios.hpp"

class Prioridade:public Dominio<string>{
    private:
        void validar(string);
};

#endif // PRIORIDADE_HPP_INCLUDED
