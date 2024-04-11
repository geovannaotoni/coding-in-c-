#include "ContaBancaria.hpp"
#include <iostream>
#include <iomanip>

ContaBancaria::ContaBancaria(int id, std::string cliente) {
    this -> id = id;
    this -> cliente = cliente;
    this -> saldo = 0;
}

void ContaBancaria::deposito(float valor) {
    saldo += valor;
}

void ContaBancaria::saque(float valor) {
    saldo -= valor;
}

void ContaBancaria::pix(ContaBancaria* contaDestinho, float valor) {
    saldo -= valor;
    contaDestinho -> deposito(valor);
}

void ContaBancaria::imprime() {
    std::cout << id << " " << cliente << " " << std::fixed << std::setprecision(2) << saldo << std::endl;
}
