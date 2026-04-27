#ifndef PAPEL_HPP_INCLUDED
#define PAPEL_HPP_INCLUDED

#include "template_dominios.hpp"

class Papel:public Dominio<int>{
    /*
    DESENVOLVEDOR           =   0
    MESTRE SCRUM            =   1
    PROPRIETARIO DE PRODUTO =   2
    */
private:
    void validar(int);
};

#endif // PAPEL_HPP_INCLUDED
