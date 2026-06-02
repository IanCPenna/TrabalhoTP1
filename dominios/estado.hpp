#ifndef ESTADO_HPP_INCLUDED
#define ESTADO_HPP_INCLUDED

#include "template_dominios.hpp"

class Estado:public Dominio<string>{
private:
    static const string VALORES_VALIDOS[3];
    void validar(string);
};

#endif // ESTADO_HPP_INCLUDED
