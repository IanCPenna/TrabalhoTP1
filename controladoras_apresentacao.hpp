#ifndef CONTROLADORAS_APRESENTACAO_HPP_INCLUDED
#define CONTROLADORAS_APRESENTACAO_HPP_INCLUDED

#include "interfaces.hpp"

using namespace std;

/**
 * @file controladoras_apresentacao.hpp
 * @brief Controladoras da camada de apresentacao (interface com o usuario).
 *
 * Cada controladora realiza a interface IU correspondente, conduz a interacao
 * com o usuario por meio de cin/cout, valida o formato dos dados de entrada
 * (capturando invalid_argument) e delega a logica de negocio aos servicos da
 * camada de servico por meio de ponteiros para as interfaces ILN.
 */

/**
 * @class CntrIUAutenticacao
 * @brief Controladora de apresentacao do servico de autenticacao.
 */
class CntrIUAutenticacao : public IUAutenticacao {
private:
    ILNAutenticacao* cntrLNAutenticacao;
public:
    CntrIUAutenticacao() : cntrLNAutenticacao(0) {}
    bool autenticar(Email* emailAutenticado);
    void setCntrLNAutenticacao(ILNAutenticacao* cntr) { cntrLNAutenticacao = cntr; }
};

/**
 * @class CntrIUPessoa
 * @brief Controladora de apresentacao dos servicos de pessoa.
 */
class CntrIUPessoa : public IUPessoa {
private:
    ILNPessoa* cntrLNPessoa;
public:
    CntrIUPessoa() : cntrLNPessoa(0) {}
    void executar(const Papel& papelUsuario);
    void cadastrar();
    void setCntrLNPessoa(ILNPessoa* cntr) { cntrLNPessoa = cntr; }
};

/**
 * @class CntrIUProjeto
 * @brief Controladora de apresentacao dos servicos de projeto.
 */
class CntrIUProjeto : public IUProjeto {
private:
    ILNProjeto* cntrLNProjeto;
public:
    CntrIUProjeto() : cntrLNProjeto(0) {}
    void executar(const Papel& papelUsuario);
    void setCntrLNProjeto(ILNProjeto* cntr) { cntrLNProjeto = cntr; }
};

/**
 * @class CntrIUPlanoSprint
 * @brief Controladora de apresentacao dos servicos de plano de sprint.
 */
class CntrIUPlanoSprint : public IUPlanoSprint {
private:
    ILNPlanoSprint* cntrLNPlanoSprint;
public:
    CntrIUPlanoSprint() : cntrLNPlanoSprint(0) {}
    void executar(const Papel& papelUsuario);
    void setCntrLNPlanoSprint(ILNPlanoSprint* cntr) { cntrLNPlanoSprint = cntr; }
};

/**
 * @class CntrIUHistoriaUsuario
 * @brief Controladora de apresentacao dos servicos de historia de usuario.
 */
class CntrIUHistoriaUsuario : public IUHistoriaUsuario {
private:
    ILNHistoriaUsuario* cntrLNHistoriaUsuario;
public:
    CntrIUHistoriaUsuario() : cntrLNHistoriaUsuario(0) {}
    void executar(const Papel& papelUsuario);
    void setCntrLNHistoriaUsuario(ILNHistoriaUsuario* cntr) { cntrLNHistoriaUsuario = cntr; }
};

#endif // CONTROLADORAS_APRESENTACAO_HPP_INCLUDED
