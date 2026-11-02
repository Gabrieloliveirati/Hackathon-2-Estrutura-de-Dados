#include <iostream>
#include <vector>
using namespace std;

long long mergeSort(vector<long long>& valores, vector<long long>& auxiliar,
                    int inicio, int fim) {
    if (inicio >= fim) return 0;

    int meio = inicio + (fim - inicio) / 2;

    long long inversoes = 0;
    inversoes += mergeSort(valores, auxiliar, inicio, meio);
    inversoes += mergeSort(valores, auxiliar, meio + 1, fim);

    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (valores[i] <= valores[j]) {
            auxiliar[k++] = valores[i++];
        } else {
            auxiliar[k++] = valores[j++];
            inversoes += meio - i + 1;
        }
    }

    while (i <= meio) auxiliar[k++] = valores[i++];
    while (j <= fim) auxiliar[k++] = valores[j++];

    for (int p = inicio; p <= fim; p++) {
        valores[p] = auxiliar[p];
    }

    return inversoes;
}

int main() {
    int n;
    cin >> n;

    vector<long long> valores(n);
    vector<long long> auxiliar(n);

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    long long inversoes = mergeSort(valores, auxiliar, 0, n - 1);

    if (valores.empty()) {
        cout << "VAZIA";
    } else {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << valores[i];
        }
    }

    cout << '\n' << inversoes << '\n';
    return 0;
}
