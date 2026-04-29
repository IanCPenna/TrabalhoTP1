#include "nome.hpp"
#include <cctype>

void Nome::validar(string nome){
    if (nome.empty() || nome.length() > TAMANHO)
        throw invalid_argument("Nome invalido: tamanho incorreto!");

    if (nome.front() == ' ' || nome.back() == ' ')
        throw invalid_argument("Nome invalido: espaco no inicio ou fim!");

    for (size_t i = 0; i < nome.length(); i++){
        char c = nome[i];

        if (!isalpha(c) && c != ' ')
            throw invalid_argument("Nome invalido: caractere nao permitido!");

        if (c == ' '){
            if (i+1 > nome.length() || nome[i+1] == ' ')
                throw invalid_argument("Nome invalido: espaco mal posicionado!");
        }
    }
}
