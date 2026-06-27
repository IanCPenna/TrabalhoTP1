#ifndef TUPLANOSPRINT_HPP_INCLUDED
#define TUPLANOSPRINT_HPP_INCLUDED

#include "../entidades/Plano_Sprint.hpp"

class TUPlanoSprint {

    private:
        const static string VALOR_VALIDO_CODIGO;       // Código
        const static string VALOR_VALIDO_OBJETIVO;    // Texto
        const static int VALOR_VALIDO_CAPACIDADE;    // Tempo
        PlanoSprint *entidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};

#endif // TUPLANOSPRINT_HPP_INCLUDED
