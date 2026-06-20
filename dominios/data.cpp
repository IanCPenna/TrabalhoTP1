#include "data.hpp"
#include <string>

void Data::validar(string valor) {
    // 1. Validação básica de formato (tamanho e barras)
    if (valor.length() != 10 || valor[2] != '/' || valor[5] != '/') {
        throw invalid_argument("Formato inválido. Use DD/MM/AAAA.");
    }

    // 2. Extração e conversão
    int dia = stoi(valor.substr(0, 2));
    int mes = stoi(valor.substr(3, 2));
    int ano = stoi(valor.substr(6, 4));

    // 3. Validação dos limites do Mês e do Ano
    if (ano < 2000 || ano > 2999) {
        throw invalid_argument("Ano fora do intervalo permitido (2000-2999).");
    }
    if (mes < 1 || mes > 12) {
        throw invalid_argument("Mês inválido.");
    }

    // 4. Validação dos Dias por Mês (considerando bissexto)
    int diasNoMes = 31; // Padrão máximo

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasNoMes = 30;
    } else if (mes == 2) {
        // Aplica a lógica do bissexto que aprendemos
        bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        diasNoMes = bissexto ? 29 : 28;
    }

    // Verifica se o dia fornecido está no intervalo correto para aquele mês específico
    if (dia < 1 || dia > diasNoMes) {
        throw invalid_argument("Dia inválido para o mês/ano especificado.");
    }
}
