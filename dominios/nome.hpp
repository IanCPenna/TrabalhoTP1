#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include "template_dominios.hpp"

class Nome:public Dominio<string>{
    private:
        static const int TAMANHO = 10;
        void validar(string);
};


#endif // NOME_HPP_INCLUDED
