#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include "template_dominios.hpp"

#include <cctype>

class Codido:public Dominio <string>{
private:
    void validar(string);
    static const int TAMANHO = 5;
    static const int TLET = 2;


};


#endif // CODIGO_HPP_INCLUDED
