#include "../headers/tempo.hpp"


void Tempo::validar(int valor){
    if (valor < 1 or valor > 365)
        throw invalid_argument("Argumento invalido para o dominio Tempo.");
}
