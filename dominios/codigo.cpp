#include "codigo.hpp"

void Codigo::validar(string valor){

    if (valor.length() != TAMANHO) {
        throw invalid_argument("C�digo deve ter exatamente 5 caracteres.");
    }

    for (int i = 0; i < TLET; i++) {
        if (!isupper(valor[i])) {
            throw invalid_argument("Os dois primeiros caracteres devem ser letras mai�sculas.");
        }
    }

    for (int i = TLET; i < TAMANHO; i++) {
        if (!isdigit(valor[i])) {
            throw invalid_argument("Os tr�s �ltimos caracteres devem ser d�gitos num�ricos.");
        }
    }

}
