#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

void quickSortTresRegioes(vector<int>& valores, int inicio, int fim,
                          mt19937& gerador) {
    while (inicio < fim) {
        uniform_int_distribution<int> distribuicao(inicio, fim);
        int pivo = valores[distribuicao(gerador)];

        int menor = inicio;
        int atual = inicio;
        int maior = fim;

        while (atual <= maior) {
            if (valores[atual] < pivo) {
                swap(valores[menor], valores[atual]);
                menor++;
                atual++;
            } else if (valores[atual] > pivo) {
                swap(valores[atual], valores[maior]);
                maior--;
            } else {
                atual++;
            }
        }

        int tamanhoEsq = menor - inicio;
        int tamanhoDir = fim - maior;

        // Processa primeiro a menor região e elimina a recursão da maior.
        if (tamanhoEsq < tamanhoDir) {
            quickSortTresRegioes(valores, inicio, menor - 1, gerador);
            inicio = maior + 1;
        } else {
            quickSortTresRegioes(valores, maior + 1, fim, gerador);
            fim = menor - 1;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> valores(n);

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    // Semente fixa para permitir reproduzir os testes.
    mt19937 gerador(20261102);

    quickSortTresRegioes(valores, 0, n - 1, gerador);

    if (valores.empty()) {
        cout << "VAZIA";
    } else {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << valores[i];
        }
    }
    cout << '\n';

    return 0;
}
