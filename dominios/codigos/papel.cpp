#include "../headers/papel.hpp"

void Papel::validar(int valor){
    if (valor < 0 || valor > 2)
        throw invalid_argument("Argumento invalido para o dominio Papel.");
}
