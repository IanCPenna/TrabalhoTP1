#include "data.hpp"

void Data::validar(string valor) {
    // 1. Valida��o b�sica de formato (tamanho e barras)
    if (valor.length() != 10 || valor[2] != '/' || valor[5] != '/') {
        throw invalid_argument("Formato inv�lido. Use DD/MM/AAAA.");
    }

    // 2. Extra��o e convers�o
    int dia = stoi(valor.substr(0, 2));
    int mes = stoi(valor.substr(3, 2));
    int ano = stoi(valor.substr(6, 4));

    // 3. Valida��o dos limites do M�s e do Ano
    if (ano < 2000 || ano > 2999) {
        throw invalid_argument("Ano fora do intervalo permitido (2000-2999).");
    }
    if (mes < 1 || mes > 12) {
        throw invalid_argument("M�s inv�lido.");
    }

    // 4. Valida��o dos Dias por M�s (considerando bissexto)
    int diasNoMes = 31; // Padr�o m�ximo

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasNoMes = 30;
    } else if (mes == 2) {
        // Aplica a l�gica do bissexto que aprendemos
        bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        diasNoMes = bissexto ? 29 : 28;
    }

    // Verifica se o dia fornecido est� no intervalo correto para aquele m�s espec�fico
    if (dia < 1 || dia > diasNoMes) {
        throw invalid_argument("Dia inv�lido para o m�s/ano especificado.");
    }
}
