#include "prioridade.hpp"

void Prioridade::validar(string prioridade){
    if((prioridade == "BAIXO") || (prioridade == "MEDIO") || (prioridade == "ALTO")){
        return;
    }else{
        throw invalid_argument("Prioridade invalida!");
    }
}
