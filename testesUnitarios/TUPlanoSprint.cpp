#include "TUPlanoSprint.hpp"

const std::string TUPlanoSprint::VALOR_VALIDO_CODIGO = "AA000";       // Código
const std::string TUPlanoSprint::VALOR_VALIDO_OBJETIVO = "Galera";   // Texto
const int TUPlanoSprint::VALOR_VALIDO_CAPACIDADE = 69;        // Tempo

void TUPlanoSprint::setUp() {
    entidade = new PlanoSprint();
    estado = SUCESSO;
}

void TUPlanoSprint::tearDown() {
    delete entidade;
}

void TUPlanoSprint::testarCenario() {
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    entidade->setCodigo(codigo);
    if (entidade->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = FALHA;

    Texto objetivo;
    objetivo.setValor(VALOR_VALIDO_OBJETIVO);
    entidade->setObjetivo(objetivo);
    if (entidade->getObjetivo().getValor() != VALOR_VALIDO_OBJETIVO)
        estado = FALHA;


    Tempo capacidade;
    capacidade.setValor(VALOR_VALIDO_CAPACIDADE);
    entidade->setCapacidade(capacidade);
    if (entidade->getCapacidade().getValor() != VALOR_VALIDO_CAPACIDADE)
        estado = FALHA;
}

int TUPlanoSprint::run() {
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
