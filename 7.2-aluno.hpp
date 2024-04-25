#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <vector>

struct Aluno {
    std::string nome;
    int matricula;
    std::vector<int> notas;

    Aluno(std::string, int, std::vector <int>);

    float CalcularMedia();
    int MaiorNota();
    int MenorNota();
    std::string getNome();
    int getMatricula();
    std::vector<int> getNotas();
    void imprimeNotas();
};

#endif
