#ifndef TUPAPEL_HPP_INCLUDED
#define TUPAPEL_HPP_INCLUDED

#include "TUTemplate.hpp"
#include "../dominios/papel.hpp"

class TUPapel : public TUTemplate<Papel, std::string> {
public:
    TUPapel();
};

#endif // TUPAPEL_HPP_INCLUDED
