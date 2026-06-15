#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include "template_dominios.hpp"

class Email:public Dominio<string>{
private:
    void validar(string);
};

#endif // EMAIL_HPP_INCLUDED
