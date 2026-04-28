#include "papel.hpp"


const string Papel::VALORES_VALIDOS[3] = {
    "DESENVOLVEDOR",
    "MESTRE SCRUM",
    "PROPRIETARIO DE PRODUTO"
};

void Papel::validar(string valor){
    for (int i = 0; i < 4; i++){
        if (valor == VALORES_VALIDOS[i])
        return;
    }
    throw invalid_argument("Argumento invalido para o dominio Papel.");
}
