#include "texto.hpp"
#include <cctype>

void Texto::validar(string texto){
     if (texto.empty())
        return;

    // Checar tamanho do texto
    if (texto.length() > TAMANHO)
        throw invalid_argument("Texto invalido: tamanho incorreto!");


    // Checar se tem ' ', '.' ou ',' no inicio ou no fim do texto
    string valid_symbols = " .,";

    for (int c = 0; c < 3; c++){
        if (texto.front() == valid_symbols[c] || texto.back() == valid_symbols[c])
            throw invalid_argument("Texto invalido: caractere nao permitido no inicio ou fim do texto!");
    }

    for (size_t i = 0; i < texto.length(); i++){
        char c = texto[i];

        // Checar caractere invalido
        if (!isalnum(c) && c != ' ' && c != '.' && c != ',')
            throw invalid_argument("Texto invalido: caractere nao permitido.");

        /* Checar sequencias invalidas:
            '  '    ' .'    ' ,'
            '..'    '.,'
            ',,'    ',.'
        */
        if (i + 1 < texto.length()){
            char prox = texto[i+1];

            if (c == ',' && (prox == ',' || prox == '.'))
                throw invalid_argument("Texto invalido: virgula mal posicionada.");


            if (c == '.' && (prox == ',' || prox == '.'))
                throw invalid_argument("Texto invalido: ponto mal posicionada.");

            if (c == ' ' && !isalnum(prox))
                throw invalid_argument("Texto invalido: espaco mal posicionado.");
        }
    }
}
