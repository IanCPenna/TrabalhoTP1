#ifndef TUHISTORIAUSUARIO_HPP_INCLUDED
#define TUHISTORIAUSUARIO_HPP_INCLUDED

#include "../entidades/historia_usuario.hpp"

class TUHistoriaUsuario {

    private:
        const static string VALOR_VALIDO_CODIGO;        // Código
        const static string VALOR_VALIDO_TITULO;        // Texto
        const static string VALOR_VALIDO_PAPEL;         // Texto
        const static string VALOR_VALIDO_ACAO;          // Texto
        const static string VALOR_VALIDO_VALOR;         // Texto
        const static string VALOR_VALIDO_PRIORIDADE;    // Prioridade
        const static string VALOR_VALIDO_ESTADO;        // Estado
        const static int VALOR_VALIDO_ESTIMATIVA = 20;  // Tempo
        HistoriaUsuario *entidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenario();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;
        int run();
};


#endif // TUHISTORIAUSUARIO_HPP_INCLUDED


