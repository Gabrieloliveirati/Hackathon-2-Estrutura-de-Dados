#include <iostream>
#include <vector>
using namespace std;

struct No {
    int valor;
    No *esq, *dir;

    No(int v) : valor(v), esq(nullptr), dir(nullptr) {}
};

void inserir(No*& raiz, int valor) {
    if (raiz == nullptr) {
        raiz = new No(valor);
        return;
    }

    No* atual = raiz;

    while (true) {
        if (valor < atual->valor) {
            if (atual->esq == nullptr) {
                atual->esq = new No(valor);
                return;
            }
            atual = atual->esq;
        } else if (valor > atual->valor) {
            if (atual->dir == nullptr) {
                atual->dir = new No(valor);
                return;
            }
            atual = atual->dir;
        } else {
            return;
        }
    }
}

void emOrdem(No* raiz, vector<int>& valores) {
    if (raiz == nullptr) return;
    emOrdem(raiz->esq, valores);
    valores.push_back(raiz->valor);
    emOrdem(raiz->dir, valores);
}

int main() {
    int n;
    cin >> n;

    No* raiz = nullptr;

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        inserir(raiz, valor);
    }

    vector<int> valores;
    emOrdem(raiz, valores);

    if (valores.empty()) {
        cout << "VAZIA";
    } else {
        for (int i = 0; i < (int)valores.size(); i++) {
            if (i) cout << " ";
            cout << valores[i];
        }
    }
    cout << '\n';

    return 0;
}
