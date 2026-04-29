#ifndef TEXTO_HPP_INCLUDED
#define TEXTO_HPP_INCLUDED

#include "template_dominios.hpp"

class Texto:public Dominio<string>{
    private:
        static const int TAMANHO = 40;
        void validar(string);
};

#endif // TEXTO_HPP_INCLUDED
