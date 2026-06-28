#include "TUPrioridade.hpp"

TUPrioridade::TUPrioridade() {
    valoresValidos = {
        "ALTA",
        "MEDIA",
        "BAIXA"
    };

    valoresInvalidos = {
        "alta",          // minúsculo
        "Alta",          // misto
        "URGENTE",       // valor inexistente
        "",              // vazio
        "ALTO"           // grafia errada
    };
}
