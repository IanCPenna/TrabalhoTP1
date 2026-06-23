#include "prioridade.hpp"

void Prioridade::validar(string prioridade){
    if((prioridade == "BAIXA") || (prioridade == "MEDIA") || (prioridade == "ALTA")){
        return;
    }else{
        throw invalid_argument("Prioridade invalida!");
    }
}
