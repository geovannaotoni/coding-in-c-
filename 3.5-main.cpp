#include <iostream>
#include <string>
#include <sstream>
#include "ContaBancaria.hpp"
#include "Banco.hpp"

using namespace std;

int main() {
    Banco banco;
    int id, idDest;
    float valor;
    string cliente;
    
    int continuar = 1;
    
    string linha;
    char comando;
    
    
    while(continuar) {
        getline(cin, linha);
        stringstream s(linha);
        s >> comando;
        
        switch(comando) {
            case 'C': {
                s >> id;
                s >> cliente;
                ContaBancaria* novaConta = banco.CriaConta(id, cliente);
                if (novaConta == nullptr) {
                    cout << "ERRO: conta repetida" << endl;
                } else {
                    cout << "conta criada" << endl;
                }
                break;
            }
            case 'D': {
                s >> id;
                s >> valor;
                ContaBancaria* conta = banco.Pesquisa(id);
                if (conta == nullptr) {
                    cout << "ERRO: conta inexistente" << endl;
                } else {
                    conta -> deposito(valor);
                    cout << "deposito efetuado" << endl;
                }
                break;
            }
            case 'S': {
                s >> id;
                s >> valor;
                ContaBancaria* conta = banco.Pesquisa(id);
                if (conta == nullptr) {
                    cout << "ERRO: conta inexistente" << endl;
                } else {
                    conta -> saque(valor);
                    cout << "saque efetuado" << endl;
                }
                break;
            }
            case 'P': {
                s >> id;
                s >> idDest;
                s >> valor;
                ContaBancaria* contaOrigem = banco.Pesquisa(id);
                ContaBancaria* contaDest = banco.Pesquisa(idDest);
                if (contaOrigem == nullptr || contaDest == nullptr) {
                    cout << "ERRO: conta inexistente" << endl;
                } else {
                    contaOrigem -> pix(contaDest, valor);
                    cout << "pix efetuado" << endl;
                }
                break;
            }
            case 'I': {
                banco.ListaContas();
                break;
            }
            case 'T': {
                continuar = 0;
                break;
            }
        }
    }
    
    return 0;
}
