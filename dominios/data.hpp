#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include "template_dominios.hpp"

class Data:public Dominio<string> {
    private:
        void validar(string);
};

#endif // DATA_HPP_INCLUDED
