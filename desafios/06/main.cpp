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

No* remover(No* raiz, int valor) {
    if (!raiz) return nullptr;

    if (valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
    } else {
        if (!raiz->esq) {
            No* temp = raiz->dir;
            delete raiz;
            return temp;
        }

        if (!raiz->dir) {
            No* temp = raiz->esq;
            delete raiz;
            return temp;
        }

        No* sucessor = raiz->dir;
        while (sucessor->esq) sucessor = sucessor->esq;

        raiz->valor = sucessor->valor;
        raiz->dir = remover(raiz->dir, sucessor->valor);
    }

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

    No* raiz = nullptr;

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        inserir(raiz, valor);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int valor;
        cin >> valor;
        raiz = remover(raiz, valor);
    }

    vector<int> valores;
    preOrdem(raiz, valores);

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
