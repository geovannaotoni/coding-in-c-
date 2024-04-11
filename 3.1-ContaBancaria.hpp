#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H
#include <string>

struct ContaBancaria {
    int id;
    std::string cliente;
    float saldo;

    ContaBancaria(int, std::string);

    void deposito(float);
    void saque(float);
    void pix(ContaBancaria*, float);
    void imprime();
};

#endif
