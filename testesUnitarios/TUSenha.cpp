#include "TUSenha.hpp"

TUSenha::TUSenha() {
    valoresValidos = {
        "a1B2c3",   // letra-dígito alternados, tem maiúsculo, minúsculo e dígito
        "A1b2C3",   // outra combinação válida
        "1a2B3c"    // inicia com dígito
    };

    valoresInvalidos = {
        "a1B2c",      // apenas 5 caracteres
        "a1B2c33",    // 7 caracteres
        "aAbBcC",     // sem dígito
        "112233",     // só dígitos
        "a1b2c3",     // sem maiúsculo
        "A1B2C3",     // sem minúsculo
        "aa1B2c",     // letra seguida de letra
        "a11B2c",     // dígito seguido de dígito
        "a1B2c!",     // caractere especial
        ""            // vazio
    };
}
