#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float calcular_media(float numeros[], int quantidade_numeros) {
    float soma = 0;
    for (int i = 0; i < quantidade_numeros; i++) {
        soma += numeros[i];
    }
    
    return soma/quantidade_numeros;
}

float calcular_desvio(float numeros[], int quantidade_numeros, float media) {
    float soma = 0;
    for (int i = 0; i < quantidade_numeros; i++) {
        float diferenca = numeros[i] - media;
        soma += diferenca * diferenca;
    }
    float variancia = soma / quantidade_numeros;
    return sqrt(variancia);
}

int main() {
    int quantidade_numeros;
    cin >> quantidade_numeros;
    
    float numeros[quantidade_numeros];
    for (int i = 0; i < quantidade_numeros; i++) {
        cin >> numeros[i];
    }
    
    float media = calcular_media(numeros, quantidade_numeros);
    float desvio_padrao = calcular_desvio(numeros, quantidade_numeros, media);

    cout << fixed << setprecision(4) << media << endl;
    cout << fixed << setprecision(4) << desvio_padrao << endl;
    
    return 0;
}
