#include "TUTexto.hpp"

TUTexto::TUTexto(){
    valoresValidos = {
    "A",
    "ABC",
    "Casa 123",
    "Rua A, 123",
    "Joao Silva",
    "Texto. Outro",
    "A1 B2 C3",
    "Abc, Def. 123",
    "1234567890123456789012345678901234567890" // exatamente 40
};
    valoresInvalidos = {
    "TextoComMaisDeQuarentaCaracteres1234567890", // > 40 caracteres

    "@",                                   // caractere inválido
    "Texto#Teste",                         // caractere inválido no meio

    ",Texto",                              // começa com vírgula
    ".Texto",                              // começa com ponto
    " Texto",                              // começa com espaço

    "Texto,",                              // termina com vírgula
    "Texto.",                              // termina com ponto
    "Texto ",                              // termina com espaço

    "Texto,,Teste",                        // vírgula seguida de vírgula
    "Texto,.Teste",                        // vírgula seguida de ponto

    "Texto..Teste",                        // ponto seguido de ponto
    "Texto.,Teste",                        // ponto seguido de vírgula

    "Texto  Teste",                        // espaço seguido de espaço
    "Texto ,Teste",                        // espaço seguido de vírgula
    "Texto .Teste",                        // espaço seguido de ponto

    "ABC @ DEF",                           // caractere inválido após espaço
    "ABC @DEF",                            // caractere inválido

    "Teste\t123",                          // tabulação
    "Teste\n123"                           // quebra de linha
    };
}
