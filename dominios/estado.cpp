#include "estado.hpp"

const string Estado::VALORES_VALIDOS[3] = {
    "A FAZER",
    "FAZENDO",
    "FEITO"
};

void Estado::validar(string valor){
    for (int i = 0; i < 4; i++){
        if (valor == VALORES_VALIDOS[i])
        return;
    }
    throw invalid_argument("Argumento invalido para o dominio Estado.");
}

