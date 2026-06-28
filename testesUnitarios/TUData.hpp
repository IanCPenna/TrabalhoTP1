#ifndef TUDATA_HPP_INCLUDED
#define TUDATA_HPP_INCLUDED

#include "TUTemplate.hpp"
#include "../dominios/data.hpp"
#include <string>

class TUData : public TUTemplate<Data, std::string> {
public:
    TUData() {
        // Cen�rio de sucesso (Testando o caso mais complexo)
        valoresValidos = {
            "01/01/2000",
            "31/01/2000",
            "29/02/2000", // bissexto
            "29/02/2004", // bissexto
            "28/02/2001",
            "30/04/2024",
            "31/12/2999"
        };

        // Cenarios de falha
        // valoresInvalidos = {
        //     "31/04/2023",
        //     "29/02/2023",
        //     "AA/02/2024",
        //     "15/13/2024",
        //     "15/05/1999",
        //     "15/05/3000",
        //     "123/05/202"
        // };

        valoresInvalidos = {
            "",

            // Formato inválido
            "1/01/2000",      // dia com 1 dígito
            "01/1/2000",      // mês com 1 dígito
            "01-01-2000",     // separador errado
            "01.01.2000",     // separador errado
            "01012000",       // sem separadores
            "01/01/00",       // ano com 2 dígitos

            // Dia inválido
            "00/01/2000",
            "32/01/2000",
            "99/01/2000",

            // Mês inválido
            "01/00/2000",
            "01/13/2000",
            "01/99/2000",

            // Ano inválido
            "01/01/1999",
            "01/01/3000",
            "01/01/1000",

            // Datas inexistentes
            "31/04/2000",     // abril tem 30 dias
            "31/06/2000",     // junho tem 30 dias
            "31/09/2000",     // setembro tem 30 dias
            "31/11/2000",     // novembro tem 30 dias

            // Fevereiro
            "30/02/2000",
            "31/02/2000",

            // Ano não bissexto
            "29/02/2001",
            "29/02/2002",
            "29/02/2003",
            "29/02/2100",     // não é bissexto

            // Dias inexistentes em meses específicos
            "31/02/2024",
            "31/04/2024",
            "31/06/2024",

            // Caracteres inválidos
            "AA/01/2000",
            "01/BB/2000",
            "01/01/AAAA",
            "ab/cd/efgh",

            // Espaços
            " 01/01/2000",
            "01/01/2000 ",
            "01 /01/2000",
            "01/ 01/2000"
        };
    }
};

#endif // TUDATA_HPP_INCLUDED
