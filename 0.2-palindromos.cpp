#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string frase;
    getline(cin, frase);
    
    string reversa;
    
    int tamanho = frase.length();
    for (int i = tamanho - 1; i >= 0; i--) {
        reversa += frase[i];
    }
    
    if (frase == reversa) {
        cout << "SIM";
    } else {
        cout << "NAO";
    }
    
    return 0;
}
