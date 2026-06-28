#include "TUEmail.hpp"

TUEmail::TUEmail() {
    valoresValidos = {
        "usuario@dominio.com",
        "user.name@sub.org",
        "user-name@domain.br",
        "a@b.c"
    };

    valoresInvalidos = {
        // Parte local inválida
        ".usuario@dominio.com",   // inicia com ponto
        "usuario.@dominio.com",   // termina com ponto
        "-usuario@dominio.com",   // inicia com hífen
        "usuario-@dominio.com",   // termina com hífen
        "us..er@dominio.com",     // ponto seguido de ponto
        "us.-er@dominio.com",     // ponto seguido de hífen
        "us er@dominio.com",      // espaço não permitido
        "us#er@dominio.com",      // caractere especial inválido

        // Domínio inválido
        "usuario@-dominio.com",   // domínio inicia com hífen
        "usuario@dominio-.com",   // domínio termina com hífen
        "usuario@dominio.-com",   // segunda parte inicia com hífen
        "usuario@dominio.com-",   // segunda parte termina com hífen

        // Estrutura geral inválida
        "usuario",                // sem @
        "@dominio.com",           // parte local vazia
        "usuario@"                // domínio vazio
    };
}
