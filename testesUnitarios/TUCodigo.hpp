#ifndef TUCODIGO_HPP_INCLUDED
#define TUCODIGO_HPP_INCLUDED

#include "TUTemplate.hpp"
#include "../dominios/codigo.hpp"
#include <string>

class TUCodigo : public TUTemplate<Codigo, std::string> {
public:
    TUCodigo() {
        // Cenário de sucesso (Testando o caso mais complexo)
        valorValido = "AB123";

        // Cenários de falha (Ataque total à sua lógica de validação)
        valoresInvalidos = {
            "ABC1234",
            "ABCDE",
            "12345"
        };
    }
};

#endif // TUCODIGO_HPP_INCLUDED
