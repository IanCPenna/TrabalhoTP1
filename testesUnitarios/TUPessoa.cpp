#include "TUPessoa.hpp"

// Valores validos usados como referencia em cada cenario de teste.
const std::string TUPessoa::VALOR_VALIDO_EMAIL = "usuario@dominio.com";
const std::string TUPessoa::VALOR_VALIDO_NOME  = "Ana Lima";
const std::string TUPessoa::VALOR_VALIDO_SENHA = "a1B2c3";
const std::string TUPessoa::VALOR_VALIDO_PAPEL = "DESENVOLVEDOR";

void TUPessoa::setUp() {
    entidade = new Pessoa();
    estado = SUCESSO;
}

void TUPessoa::tearDown() {
    delete entidade;
}

void TUPessoa::testarCenario() {
    // Atributo email.
    Email email;
    email.setValor(VALOR_VALIDO_EMAIL);
    entidade->setEmail(email);
    if (entidade->getEmail().getValor() != VALOR_VALIDO_EMAIL)
        estado = FALHA;

    // Atributo nome.
    Nome nome;
    nome.setValor(VALOR_VALIDO_NOME);
    entidade->setNome(nome);
    if (entidade->getNome().getValor() != VALOR_VALIDO_NOME)
        estado = FALHA;

    // Atributo senha.
    Senha senha;
    senha.setValor(VALOR_VALIDO_SENHA);
    entidade->setSenha(senha);
    if (entidade->getSenha().getValor() != VALOR_VALIDO_SENHA)
        estado = FALHA;

    // Atributo papel.
    Papel papel;
    papel.setValor(VALOR_VALIDO_PAPEL);
    entidade->setPapel(papel);
    if (entidade->getPapel().getValor() != VALOR_VALIDO_PAPEL)
        estado = FALHA;
}

int TUPessoa::run() {
    setUp();
    testarCenario();
    tearDown();
    return estado;
}
