#include "email.hpp"

void Email::validar(string email){
    // verifica se contém "@"
    if(email.find("@") == string::npos){
        throw invalid_argument("E-mail invalido: Deve conter '@'!");
    }

    //divisão parte e dominio
    string parte_local = email.substr(0, email.find("@"));
    string dominio = email.substr(email.find("@") + 1);

    //restrições de tamanho
    if(parte_local.empty() || (parte_local.length() > 64)){
        throw invalid_argument("E-mail invalido: Parte local não pode ter mais que 64 caracteres!");
    }

    if(dominio.empty() || (dominio.length() > 255)){
        throw invalid_argument("E-mail invalido: Parte local não pode ter mais que 255 caracteres!");
    }

    //validação dos dados parte_local
    for(int i = 0; i < parte_local.length(); i++){
        if(!isalnum(parte_local[i]) && (parte_local[i] != '-') && (parte_local[i] != '.')){
            throw invalid_argument("E-mail invalido: Character inserido em parte_local invalido!");
        }
        else if(((parte_local[i] == '.') || (parte_local[i] == '-')) && (!isalnum(parte_local[i+1]))) {
            throw invalid_argument("E-mail invalido: '.' ou '-' deve ser seguido por letra ou numeros");
        }
    }

    if(parte_local.front() == '.' || parte_local.front() == '-' || parte_local.back() == '.' || parte_local.back() == '-'){
        throw invalid_argument("E-mail invalido: Parte local nao pode inciar ou finalizar com '.' ou '-'");
    }

    //validação dos dados dominio
    string dominio_primeiro = dominio.substr(0, dominio.find("."));
    string dominio_segundo = dominio.substr(dominio.find(".") + 1);

    for(int i = 0; i < dominio_primeiro.length(); i++){
        if(!isalnum(dominio_primeiro[i]) && (dominio_primeiro[i] != '-')){
            throw invalid_argument("E-mail invalido: Character inserido em dominio invalido!");
        }
    }

    if(dominio_primeiro.front() == '-' || dominio_primeiro.back() == '-'){
        throw invalid_argument("E-mail invalido: dominio nao pode inciar ou finalizar com '.' ou '-'");
    }

    for(int i = 0; i < dominio_segundo.length(); i++){
        if(!isalnum(dominio_segundo[i]) && (dominio_segundo[i] != '-')){
            throw invalid_argument("E-mail invalido: Character inserido em dominio invalido!");
        }
    }

    if(dominio_segundo.front() == '-' || dominio_segundo.back() == '-'){
        throw invalid_argument("E-mail invalido: dominio nao pode inciar ou finalizar com '.' ou '-'");
    }

}
