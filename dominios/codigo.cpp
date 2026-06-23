#include "codigo.hpp"

void Codigo::validar(string valor){

    if (valor.length() != TAMANHO) {
        throw invalid_argument("Código deve ter exatamente 5 caracteres.");
    }

    for (int i = 0; i < TLET; i++) {
        if (!isupper(valor[i])) {
            throw invalid_argument("Os dois primeiros caracteres devem ser letras maiúsculas.");
        }
    }

    for (int i = TLET; i < TAMANHO; i++) {
        if (!isdigit(valor[i])) {
            throw invalid_argument("Os três últimos caracteres devem ser dígitos numéricos.");
        }
    }

}
