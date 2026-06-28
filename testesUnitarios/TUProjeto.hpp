#ifndef TUPROJETO_HPP_INCLUDED
#define TUPROJETO_HPP_INCLUDED

#include "../entidades/projeto.hpp"

class TUProjeto {
    private:
        const static string VALOR_VALIDO_CODIGO;
        const static string VALOR_VALIDO_NOME;
        const static string VALOR_VALIDO_INICIO;
        const static string VALOR_VALIDO_TERMINO;

        Projeto *entidade;
        int estado;

        void setUp();
        void tearDown();
        void testarCenario();

    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // TUPROJETO_HPP_INCLUDED
