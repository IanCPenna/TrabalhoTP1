#include "../headers/tempo.hpp"


bool Tempo::validar(uint8_t valor){
    if (valor < 1 or valor > 365)
        return false;
    return true;
}
