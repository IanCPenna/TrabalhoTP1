#include "TUHistoriaUsuario.hpp"

const std::string TUHistoriaUsuario::VALOR_VALIDO_CODIGO = "AA000";     // Código
const std::string TUHistoriaUsuario::VALOR_VALIDO_TITULO = "Titulo";    // Texto
const std::string TUHistoriaUsuario::VALOR_VALIDO_PAPEL = "Papel";      // Texto
const std::string TUHistoriaUsuario::VALOR_VALIDO_ACAO = "Acao";        // Texto
const std::string TUHistoriaUsuario::VALOR_VALIDO_VALOR = "Valor";      // Texto
const std::string TUHistoriaUsuario::VALOR_VALIDO_PRIORIDADE = "ALTA";  // Prioridade
const std::string TUHistoriaUsuario::VALOR_VALIDO_ESTADO = "FEITO";     // Estado
                                                                        // Tempo

void TUHistoriaUsuario::setUp() {
    entidade = new HistoriaUsuario();
    estado = SUCESSO;
}

void TUHistoriaUsuario::tearDown() {
    delete entidade;
}

void TUHistoriaUsuario::testarCenario() {
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    entidade->setCodigo(codigo);
    if (entidade->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = FALHA;

    Texto titulo;
    titulo.setValor(VALOR_VALIDO_TITULO);
    entidade->setTitulo(titulo);
    if (entidade->getTitulo().getValor() != VALOR_VALIDO_TITULO)
        estado = FALHA;

    Texto papel;
    papel.setValor(VALOR_VALIDO_PAPEL);
    entidade->setPapel(papel);
    if (entidade->getPapel().getValor() != VALOR_VALIDO_PAPEL)
        estado = FALHA;

    Texto acao;
    acao.setValor(VALOR_VALIDO_ACAO);
    entidade->setAcao(acao);
    if (entidade->getAcao().getValor() != VALOR_VALIDO_ACAO)
        estado = FALHA;

    Texto valor;
    valor.setValor(VALOR_VALIDO_VALOR);
    entidade->setValor(valor);
    if (entidade->getValor().getValor() != VALOR_VALIDO_VALOR)
        estado = FALHA;

    Prioridade prioridade;
    prioridade.setValor(VALOR_VALIDO_PRIORIDADE);
    entidade->setPrioridade(prioridade);
    if (entidade->getPrioridade().getValor() != VALOR_VALIDO_PRIORIDADE)
        estado = FALHA;

    Estado dom_estado;
    dom_estado.setValor(VALOR_VALIDO_ESTADO);
    entidade->setEstado(dom_estado);
    if (entidade->getEstado().getValor() != VALOR_VALIDO_ESTADO)
        estado = FALHA;

    Tempo estimativa;
    estimativa.setValor(VALOR_VALIDO_ESTIMATIVA);
    entidade->setEstimativa(estimativa);
    if (entidade->getEstimativa().getValor() != VALOR_VALIDO_ESTIMATIVA)
        estado = FALHA;
}

int TUHistoriaUsuario::run() {
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
