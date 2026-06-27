#ifndef TUESTADO_HPP_INCLUDED
#define TUESTADO_HPP_INCLUDED

#include "TUTemplate.hpp"
#include "../dominios/estado.hpp"
#include <string>

class TUEstado : public TUTemplate<Estado, std::string> {
public:
    TUEstado() {
        // Cenário de sucesso (Testando o caso mais complexo)
        valoresValidos =   {"A FAZER",
                            "FAZENDO",
                            "FEITO"};

        // Cenários de falha (Ataque total à sua lógica de validação)
        valoresInvalidos = {
            "a fazer",
            "Cara, não sei bem o que escrever pra testar essa classe",
            "12345"
        };
    }
};

#endif // TUESTADO_HPP_INCLUDED
