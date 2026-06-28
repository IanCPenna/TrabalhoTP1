#ifndef TUPESSOA_HPP_INCLUDED
#define TUPESSOA_HPP_INCLUDED

#include "../entidades/Pessoa.hpp"

class TUPessoa {
    private:
        const static string VALOR_VALIDO_EMAIL;  // Email
        const static string VALOR_VALIDO_NOME;   // Nome
        const static string VALOR_VALIDO_SENHA;  // Senha
        const static string VALOR_VALIDO_PAPEL;  // Papel

        Pessoa *entidade;
        int estado;

        void setUp();
        void tearDown();
        void testarCenario();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // TUPESSOA_HPP_INCLUDED
