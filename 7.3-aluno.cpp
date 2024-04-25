#include "aluno.hpp"
#include <iostream>

Aluno::Aluno(std::string nome, int matricula, std::vector <int> notas) {
    this->nome = nome;
    this->matricula = matricula;
    this->notas = notas;
}

float Aluno::CalcularMedia() {
    if(notas.empty()) {
        return 0;
    }
    
    float total = 0;
    for (int nota : notas) {
        total += nota;
    }
    float media = total / (notas.size());
    return media;
}

int Aluno::MaiorNota() {
    if(notas.empty()) {
        return 0;
    }
    
    int notaMax = notas[0];
    for (int nota : notas) {
        if (nota > notaMax) {
            notaMax = nota;
        }
    }
    return notaMax;
}

int Aluno::MenorNota() {
    if(notas.empty()) {
        return 0;
    }
    
    int notaMin = notas[0];
    for (int nota : notas) {
        if (nota < notaMin) {
            notaMin = nota;
        }
    }
    return notaMin;
}

std::string Aluno::getNome() {
    return this->nome;
}

int Aluno::getMatricula() {
    return this->matricula;
}

std::vector<int> Aluno::getNotas() {
    return this->notas;
}

void Aluno::imprimeNotas() {
    for (int nota : notas) {
        std::cout << nota << " ";
    }
    std::cout << std::endl;
}
