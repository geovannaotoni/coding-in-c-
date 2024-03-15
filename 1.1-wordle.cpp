#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void verificar_palavra(string chave, string palavra) {
    string dicas = "*****";
    static string letras_ausentes = "";
    
    
    for (int i = 0; i < 5; i++) {
        if (palavra[i] == chave[i]) {
            dicas[i] = toupper(palavra[i]);
        } else if (chave.find(palavra[i]) != string::npos) {
        // se a função find() não encontrar a letra é retornado string::npos
            dicas[i] = tolower(palavra[i]);
        } else if (letras_ausentes.find(palavra[i]) ==  string::npos) {
            letras_ausentes += toupper(palavra[i]);
        }
    }
    
    cout << dicas;
    if (letras_ausentes.length() > 0) {
        cout << " (" << letras_ausentes << ")";
    }
    
    cout << endl;
}

int main() {
    ifstream arquivo("palavras.txt", fstream::in);
    if (!arquivo.is_open())
        return 1;
        
    int tamanho;
    arquivo >> tamanho;
    // cout << tamanho;
    
    string palavras[tamanho];
    for (int i = 0; i < tamanho; i++) {
        arquivo >> palavras[i];
    }
    
    int num_chave;
    while (true) {
        cin >> num_chave;
        if (num_chave >= 0 && num_chave <= tamanho) {
            break;
        } else {
            cout << "Por favor, insira um valor entre 0 e " << tamanho << "." << endl;
        }
    }
    
    string chave = palavras[num_chave - 1];
    // cout << resposta;
    int num_tentativa = 0;
    int ganhou = 0;
    
    for (; num_tentativa < 5; num_tentativa++) {
        string tentativa;
        cin >> tentativa;
        verificar_palavra(chave, tentativa);
        
        if (chave == tentativa) {
            ganhou = 1;
            break;
        }
    }
    
    if (ganhou) {
        cout << "GANHOU!";
    } else {
        cout << "PERDEU! " << chave;
    }
    
    return 0;
}
