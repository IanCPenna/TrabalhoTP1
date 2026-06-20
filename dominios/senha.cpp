#include "senha.hpp"

void Senha::validar(string senha){
    bool possuiMaiusculo = false;
    bool possuiMinusculo = false;
    bool possuiDigito = false;

    if(!(senha.length() == 6)){
        throw invalid_argument("Senha invalida: A senha de conter 6 characteres!");
    }

    for(int i = 0; i < senha.length(); i++){
        islower(senha[i]) ? possuiMinusculo = true : 0;
        isupper(senha[i]) ? possuiMaiusculo = true : 0;
        isdigit(senha[i]) ? possuiDigito = true : 0;

        if(!isalnum(senha[i])){
            throw invalid_argument("Senha invalida: A senha deve conter apenas letras ou numeros!");
        }
        if(i < senha.length() - 1){
            if(isalpha(senha[i]) && isalpha(senha[i + 1])) {
                throw invalid_argument("Senha invalida: Letra nao pode ser seguida por letra.");
            }
            else if(isdigit(senha[i]) && isdigit(senha[i + 1])) {
                throw invalid_argument("Senha invalida: Digito nao pode ser seguido por digito.");
            }
        }
    }

    if(!possuiDigito || !possuiMaiusculo || !possuiMinusculo){
        throw invalid_argument("Senha invalida: Deve conter characteres maiusculo, minusculo e numero.");
    }

}
