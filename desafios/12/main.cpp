#include <iostream>
#include <vector>
using namespace std;

struct No {
    int valor;
    No *esq, *dir;

    No(int v) : valor(v), esq(nullptr), dir(nullptr) {}
};

void inserir(No*& raiz, int valor) {
    if (!raiz) {
        raiz = new No(valor);
        return;
    }

    No* atual = raiz;
    while (true) {
        if (valor < atual->valor) {
            if (!atual->esq) {
                atual->esq = new No(valor);
                return;
            }
            atual = atual->esq;
        } else if (valor > atual->valor) {
            if (!atual->dir) {
                atual->dir = new No(valor);
                return;
            }
            atual = atual->dir;
        } else {
            return;
        }
    }
}

int altura(No* raiz) {
    if (!raiz) return -1;
    int a = altura(raiz->esq);
    int b = altura(raiz->dir);
    return max(a, b) + 1;
}

void emOrdem(No* raiz, vector<int>& valores) {
    if (!raiz) return;
    emOrdem(raiz->esq, valores);
    valores.push_back(raiz->valor);
    emOrdem(raiz->dir, valores);
}

No* construirBalanceada(const vector<int>& valores, int inicio, int fim) {
    if (inicio > fim) return nullptr;

    int meio = (inicio + fim) / 2;
    No* raiz = new No(valores[meio]);

    raiz->esq = construirBalanceada(valores, inicio, meio - 1);
    raiz->dir = construirBalanceada(valores, meio + 1, fim);

    return raiz;
}

void preOrdem(No* raiz, vector<int>& valores) {
    if (!raiz) return;
    valores.push_back(raiz->valor);
    preOrdem(raiz->esq, valores);
    preOrdem(raiz->dir, valores);
}

int main() {
    int n;
    cin >> n;

    No* original = nullptr;

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        inserir(original, valor);
    }

    int alturaOriginal = altura(original);

    vector<int> ordenados;
    emOrdem(original, ordenados);

    No* nova = construirBalanceada(ordenados, 0, (int)ordenados.size() - 1);

    vector<int> resultado;
    preOrdem(nova, resultado);

    if (resultado.empty()) {
        cout << "VAZIA";
    } else {
        for (int i = 0; i < (int)resultado.size(); i++) {
            if (i) cout << " ";
            cout << resultado[i];
        }
    }

    cout << '\n';
    cout << alturaOriginal << " " << altura(nova) << '\n';

    return 0;
}
