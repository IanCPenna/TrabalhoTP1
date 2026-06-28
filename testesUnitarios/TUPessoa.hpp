#ifndef TUPESSOA_HPP_INCLUDED
#define TUPESSOA_HPP_INCLUDED

#include <string>
#include "../entidades/Pessoa.hpp"

/**
 * @class TUPessoa
 * @brief Teste de unidade para a entidade Pessoa.
 *
 * Para cada atributo da entidade, armazena um valor de dominio valido por
 * meio do metodo set e verifica se o mesmo valor pode ser recuperado pelo
 * metodo get correspondente. O resultado da execucao e reportado por meio
 * das constantes SUCESSO e FALHA.
 */
class TUPessoa {
private:
    const static std::string VALOR_VALIDO_EMAIL;
    const static std::string VALOR_VALIDO_NOME;
    const static std::string VALOR_VALIDO_SENHA;
    const static std::string VALOR_VALIDO_PAPEL;

    Pessoa* entidade;       ///< Referencia para a unidade em teste.
    int estado;             ///< Estado corrente do teste.

    void setUp();           ///< Cria a unidade em teste.
    void tearDown();        ///< Destroi a unidade em teste.
    void testarCenario();   ///< Cenario de teste da entidade.

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    /**
     * @brief Executa o teste de unidade da entidade Pessoa.
     * @return SUCESSO se todos os atributos foram armazenados e recuperados
     *         corretamente; FALHA caso contrario.
     */
    int run();
};

#endif // TUPESSOA_HPP_INCLUDED
