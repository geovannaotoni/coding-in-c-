#include "aluno.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compararPorNome(Aluno &a, Aluno &b) {
    return a.getNome() < b.getNome();
}

int main() {
    vector<Aluno> alunos;
    
    while(true) {
        string nome;
        int matricula;
        vector<int> notas;
        
        string linha;
        getline(cin, linha);
        
        if (linha == "END")
            break;
        
        nome = linha;
        cin >> matricula;
        
        int nota;
        while(cin >> nota) {
            if(nota == -1)
                break;
                
            notas.push_back(nota);
        }
        
        cin.ignore();
        
        Aluno aluno(nome, matricula, notas);
        alunos.push_back(aluno);
    }
    
    sort(alunos.begin(), alunos.end(), compararPorNome);
    
    for (auto aluno : alunos) {
        cout << aluno.getMatricula() << " " << aluno.getNome() << " ";
        aluno.imprimeNotas();
        cout << fixed << setprecision(2) << aluno.CalcularMedia();
        cout << " " << aluno.MaiorNota() << " " << aluno.MenorNota() << endl;
    }
    
}
