#include <iostream>
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

int buscarProfundidade(No* raiz, int valor) {
    int profundidade = 0;
    No* atual = raiz;

    while (atual != nullptr) {
        if (valor == atual->valor) return profundidade;

        if (valor < atual->valor) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
        profundidade++;
    }

    return -1;
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

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int consulta;
        cin >> consulta;
        cout << buscarProfundidade(raiz, consulta) << '\n';
    }

    return 0;
}
