#ifndef TUSENHA_HPP_INCLUDED
#define TUSENHA_HPP_INCLUDED

#include "TUTemplate.hpp"
#include "../dominios/senha.hpp"

class TUSenha : public TUTemplate<Senha, std::string> {
public:
    TUSenha();
};

#endif // TUSENHA_HPP_INCLUDED
