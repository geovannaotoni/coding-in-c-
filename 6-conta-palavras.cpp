#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

int main() {
    string nome_arquivo;
    cin >> nome_arquivo;
    
    ifstream arquivo(nome_arquivo, fstream::in);
    if (!arquivo.is_open())
        return 1;
    
    map<string, int> contador_palavras;
    
    // Expressão regular que separa as palavras a patir de caracteres não alfanuméricos
    regex regex_palavras("[a-zA-Z0-9]+");
    
    string linha;
    while(getline(arquivo, linha)) {
        transform(linha.begin(), linha.end(), linha.begin(), ::tolower);
        
        sregex_iterator it_regex(linha.begin(), linha.end(), regex_palavras);
        sregex_iterator end;
        
        while (it_regex != end) {
            string palavra = it_regex->str();
            if (!palavra.empty()) {
                contador_palavras[palavra]++;
            }
            it_regex++;
        }
    }
    
    arquivo.close();
    
    map<string, int>::iterator it;
    for (it = contador_palavras.begin(); it != contador_palavras.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}
