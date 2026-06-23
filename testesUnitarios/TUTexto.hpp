#ifndef TUTEXTO_HPP_INCLUDED
#define TUTEXTO_HPP_INCLUDED

#include "TUTemplate.hpp"
#include "../dominios/texto.hpp"

class TUTexto : public TUTemplate<Texto, std::string> {
public:
    TUTexto();
};

#endif // TUTEXTO_HPP_INCLUDED
