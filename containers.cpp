#include "containers.hpp"

// ===========================================================================
//  ContainerPessoa
// ===========================================================================

bool ContainerPessoa::incluir(const Pessoa& pessoa) {
    for (list<Pessoa>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getEmail().getValor() == pessoa.getEmail().getValor())
            return false;
    }
    elementos.push_back(pessoa);
    return true;
}

bool ContainerPessoa::remover(const Email& email) {
    for (list<Pessoa>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getEmail().getValor() == email.getValor()) {
            elementos.erase(it);
            return true;
        }
    }
    return false;
}

bool ContainerPessoa::pesquisar(Pessoa* pessoa) {
    for (list<Pessoa>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getEmail().getValor() == pessoa->getEmail().getValor()) {
            *pessoa = *it;
            return true;
        }
    }
    return false;
}

bool ContainerPessoa::atualizar(const Pessoa& pessoa) {
    for (list<Pessoa>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getEmail().getValor() == pessoa.getEmail().getValor()) {
            *it = pessoa;
            return true;
        }
    }
    return false;
}

list<Pessoa> ContainerPessoa::listar() const {
    return elementos;
}

// ===========================================================================
//  ContainerProjeto
// ===========================================================================

bool ContainerProjeto::incluir(const Projeto& projeto) {
    for (list<Projeto>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == projeto.getCodigo().getValor())
            return false;
    }
    elementos.push_back(projeto);
    return true;
}

bool ContainerProjeto::remover(const Codigo& codigo) {
    for (list<Projeto>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == codigo.getValor()) {
            elementos.erase(it);
            return true;
        }
    }
    return false;
}

bool ContainerProjeto::pesquisar(Projeto* projeto) {
    for (list<Projeto>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == projeto->getCodigo().getValor()) {
            *projeto = *it;
            return true;
        }
    }
    return false;
}

bool ContainerProjeto::atualizar(const Projeto& projeto) {
    for (list<Projeto>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == projeto.getCodigo().getValor()) {
            *it = projeto;
            return true;
        }
    }
    return false;
}

list<Projeto> ContainerProjeto::listar() const {
    return elementos;
}

// ===========================================================================
//  ContainerPlanoSprint
// ===========================================================================

bool ContainerPlanoSprint::incluir(const PlanoSprint& plano) {
    for (list<PlanoSprint>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == plano.getCodigo().getValor())
            return false;
    }
    elementos.push_back(plano);
    return true;
}

bool ContainerPlanoSprint::remover(const Codigo& codigo) {
    for (list<PlanoSprint>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == codigo.getValor()) {
            elementos.erase(it);
            return true;
        }
    }
    return false;
}

bool ContainerPlanoSprint::pesquisar(PlanoSprint* plano) {
    for (list<PlanoSprint>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == plano->getCodigo().getValor()) {
            *plano = *it;
            return true;
        }
    }
    return false;
}

bool ContainerPlanoSprint::atualizar(const PlanoSprint& plano) {
    for (list<PlanoSprint>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == plano.getCodigo().getValor()) {
            *it = plano;
            return true;
        }
    }
    return false;
}

list<PlanoSprint> ContainerPlanoSprint::listar() const {
    return elementos;
}

// ===========================================================================
//  ContainerHistoriaUsuario
// ===========================================================================

bool ContainerHistoriaUsuario::incluir(const HistoriaUsuario& historia) {
    for (list<HistoriaUsuario>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == historia.getCodigo().getValor())
            return false;
    }
    elementos.push_back(historia);
    return true;
}

bool ContainerHistoriaUsuario::remover(const Codigo& codigo) {
    for (list<HistoriaUsuario>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == codigo.getValor()) {
            elementos.erase(it);
            return true;
        }
    }
    return false;
}

bool ContainerHistoriaUsuario::pesquisar(HistoriaUsuario* historia) {
    for (list<HistoriaUsuario>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == historia->getCodigo().getValor()) {
            *historia = *it;
            return true;
        }
    }
    return false;
}

bool ContainerHistoriaUsuario::atualizar(const HistoriaUsuario& historia) {
    for (list<HistoriaUsuario>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
        if (it->getCodigo().getValor() == historia.getCodigo().getValor()) {
            *it = historia;
            return true;
        }
    }
    return false;
}

list<HistoriaUsuario> ContainerHistoriaUsuario::listar() const {
    return elementos;
}
