#ifndef TUNOME_HPP_INCLUDED
#define TUNOME_HPP_INCLUDED

#include "TUTemplate.hpp"
#include "../dominios/nome.hpp"

class TUNome : public TUTemplate<Nome, std::string> {
public:
    TUNome();
};


#endif // TUNOME_HPP_INCLUDED
