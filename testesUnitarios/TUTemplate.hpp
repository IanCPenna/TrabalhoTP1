#ifndef TUTEMPLATE_HPP_INCLUDED
#define TUTEMPLATE_HPP_INCLUDED


#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>

template <class T_Dominio, typename T_Valor>
class TUTemplate {
protected:
    T_Dominio *objeto;
    int estado;

    T_Valor valorValido;
    std::vector<T_Valor> valoresInvalidos;

    void setUp() {
        objeto = new T_Dominio();
        estado = SUCESSO;
    }

    void tearDown() {
        delete objeto;
    }

    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};


template <class T_Dominio, typename T_Valor>
void TUTemplate<T_Dominio, T_Valor>::testarCenarioSucesso() {
    try {
        objeto->setValor(valorValido);
        if (objeto->getValor() != valorValido) estado = FALHA;
    }
    catch (const std::invalid_argument &excecao) {
        estado = FALHA;
    }
}


template <class T_Dominio, typename T_Valor>
void TUTemplate<T_Dominio, T_Valor>::testarCenarioFalha() {

    // Voltamos a iterar apenas sobre uma lista simples de valores
    for (const T_Valor& valorAtual : valoresInvalidos) {

        try {
            objeto->setValor(valorAtual);

            // ATENÇÃO: Se chegou aqui, a classe FALHOU em barrar o erro.
            // É vital imprimir esse aviso visual na cor vermelha mentalmente.
            std::cout << "[ERRO CRITICO NO TESTE] O valor '" << valorAtual
                      << "' foi ACEITO indevidamente pelo objeto!" << std::endl;

            estado = FALHA;
        }
        catch (const std::invalid_argument &excecao) {

            // O teste passou, mas imprimimos o log para sua verificação manual
            std::cout << "[OK] Valor barrado: " << valorAtual
                      << " | Motivo: " << excecao.what() << std::endl;
        }
    }
}

template <class T_Dominio, typename T_Valor>
int TUTemplate<T_Dominio, T_Valor>::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

#endif // TUTEMPLATE_HPP_INCLUDED
