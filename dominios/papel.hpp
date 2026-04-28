#ifndef PAPEL_HPP_INCLUDED
#define PAPEL_HPP_INCLUDED

#include "template_dominios.hpp"

class Papel:public Dominio<string>{
private:
    static const string VALORES_VALIDOS[3];
    void validar(string);
};

#endif // PAPEL_HPP_INCLUDED
