#include "../headers/tempo.hpp"


bool Tempo::validar(int valor){
    if (valor < 1 or valor > 365)
        return false;
    return true;
}
