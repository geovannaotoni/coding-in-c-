#ifndef BANCO_H
#define BANCO_H
#include <iostream>
#include <string>

#include "ContaBancaria.hpp"

struct Banco {
    static const int MAX_CONTAS = 20;
    int totalDeContas;
    ContaBancaria* contas[MAX_CONTAS];

    Banco();

    ContaBancaria* CriaConta(int, std::string);

    ContaBancaria* Pesquisa(int);

    void ListaContas();
    
};

#endif
