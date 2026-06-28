#include "TUProjeto.hpp"

const std::string TUProjeto::VALOR_VALIDO_CODIGO  = "AB123";
const std::string TUProjeto::VALOR_VALIDO_NOME    = "Projeto";
const std::string TUProjeto::VALOR_VALIDO_INICIO  = "01/01/2025";
const std::string TUProjeto::VALOR_VALIDO_TERMINO = "31/12/2025";

void TUProjeto::setUp() {
    entidade = new Projeto();
    estado = SUCESSO;
}

void TUProjeto::tearDown() {
    delete entidade;
}

void TUProjeto::testarCenario() {
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    entidade->setCodigo(codigo);
    if (entidade->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = FALHA;

    Nome nome;
    nome.setValor(VALOR_VALIDO_NOME);
    entidade->setNome(nome);
    if (entidade->getNome().getValor() != VALOR_VALIDO_NOME)
        estado = FALHA;

    Data inicio;
    inicio.setValor(VALOR_VALIDO_INICIO);
    entidade->setInicio(inicio);
    if (entidade->getInicio().getValor() != VALOR_VALIDO_INICIO)
        estado = FALHA;

    Data termino;
    termino.setValor(VALOR_VALIDO_TERMINO);
    entidade->setTermino(termino);
    if (entidade->getTermino().getValor() != VALOR_VALIDO_TERMINO)
        estado = FALHA;
}

int TUProjeto::run() {
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
