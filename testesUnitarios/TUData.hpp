#ifndef TUDATA_HPP_INCLUDED
#define TUDATA_HPP_INCLUDED

#include "TUTemplate.hpp"
#include "../dominios/data.hpp"
#include <string>

class TUData : public TUTemplate<Data, std::string> {
public:
    TUData() {
        // Cenário de sucesso (Testando o caso mais complexo)
        valorValido = "29/02/2024";

        // Cenários de falha (Ataque total à sua lógica de validação)
        valoresInvalidos = {
            "31/04/2023",
            "29/02/2023",
            "AA/02/2024",
            "15/13/2024",
            "15/05/1999",
            "15/05/3000",
            "123/05/202"
        };
    }
};


#endif // TUDATA_HPP_INCLUDED
