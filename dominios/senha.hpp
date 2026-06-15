#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include "template_dominios.hpp"

class Senha:public Dominio<string>{
private:
    const int TAMANHO = 6;
    void validar(string);
};

#endif // SENHA_HPP_INCLUDED
