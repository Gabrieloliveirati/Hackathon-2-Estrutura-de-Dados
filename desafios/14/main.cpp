#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& valores, vector<int>& auxiliar,
               int inicio, int fim) {
    if (inicio >= fim) return;

    int meio = inicio + (fim - inicio) / 2;
    mergeSort(valores, auxiliar, inicio, meio);
    mergeSort(valores, auxiliar, meio + 1, fim);

    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (valores[i] <= valores[j]) {
            auxiliar[k++] = valores[i++];
        } else {
            auxiliar[k++] = valores[j++];
        }
    }

    while (i <= meio) auxiliar[k++] = valores[i++];
    while (j <= fim) auxiliar[k++] = valores[j++];

    for (int p = inicio; p <= fim; p++) {
        valores[p] = auxiliar[p];
    }
}

struct No {
    int valor;
    int tamanho;
    No *esq, *dir;

    No(int v) : valor(v), tamanho(1), esq(nullptr), dir(nullptr) {}
};

int tamanho(No* raiz) {
    return raiz ? raiz->tamanho : 0;
}

No* construir(const vector<int>& valores, int inicio, int fim) {
    if (inicio > fim) return nullptr;

    int meio = (inicio + fim) / 2;
    No* raiz = new No(valores[meio]);

    raiz->esq = construir(valores, inicio, meio - 1);
    raiz->dir = construir(valores, meio + 1, fim);
    raiz->tamanho = 1 + tamanho(raiz->esq) + tamanho(raiz->dir);

    return raiz;
}

int consultarPosicao(No* raiz, int valor) {
    int antes = 0;

    while (raiz) {
        int esquerda = tamanho(raiz->esq);

        if (valor == raiz->valor) {
            return antes + esquerda + 1;
        }

        if (valor < raiz->valor) {
            raiz = raiz->esq;
        } else {
            antes += esquerda + 1;
            raiz = raiz->dir;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> valores(n);
    vector<int> auxiliar(n);

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    mergeSort(valores, auxiliar, 0, n - 1);
    No* raiz = construir(valores, 0, n - 1);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int consulta;
        cin >> consulta;
        cout << consultarPosicao(raiz, consulta) << '\n';
    }

    return 0;
}
