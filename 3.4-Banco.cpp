#include "Banco.hpp"

Banco::Banco() {
    totalDeContas = 0;
    for (int i = 0; i < MAX_CONTAS; ++i) {
        contas[i] = nullptr;
    }
}

ContaBancaria* Banco::CriaConta(int id, std::string cliente) {
    if (totalDeContas == MAX_CONTAS) {
        return nullptr;
    }

    for (int i = 0; i < totalDeContas; ++i) {
        if (contas[i]->id == id) {
            return nullptr;
        }
    }

    ContaBancaria* novaConta = new ContaBancaria(id, cliente);
    contas[totalDeContas] = novaConta;
    totalDeContas += 1;

    return novaConta;    
}

ContaBancaria* Banco::Pesquisa(int id) {
    for (int i = 0; i < totalDeContas; i++) {
        if (contas[i] -> id == id) {
            return contas[i];
        }
    }
    return nullptr;
}

void Banco::ListaContas() {
    for (int i = 0; i < totalDeContas; i++) {
        contas[i] -> imprime();
    }
}
