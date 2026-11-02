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

bool buscar(No* raiz, int valor) {
    while (raiz) {
        if (valor == raiz->valor) return true;
        raiz = (valor < raiz->valor) ? raiz->esq : raiz->dir;
    }
    return false;
}

void faixa(No* raiz, int a, int b, vector<int>& resultado) {
    if (!raiz) return;

    if (raiz->valor > a) faixa(raiz->esq, a, b, resultado);
    if (raiz->valor >= a && raiz->valor <= b) resultado.push_back(raiz->valor);
    if (raiz->valor < b) faixa(raiz->dir, a, b, resultado);
}

int main() {
    int q;
    cin >> q;

    No* raiz = nullptr;

    for (int i = 0; i < q; i++) {
        char comando;
        cin >> comando;

        if (comando == 'I') {
            int x;
            cin >> x;
            inserir(raiz, x);
        } else if (comando == 'R') {
            int x;
            cin >> x;
            raiz = remover(raiz, x);
        } else if (comando == 'B') {
            int x;
            cin >> x;
            cout << (buscar(raiz, x) ? "SIM" : "NAO") << '\n';
        } else if (comando == 'F') {
            int a, b;
            cin >> a >> b;

            vector<int> resultado;
            faixa(raiz, a, b, resultado);

            if (resultado.empty()) {
                cout << "VAZIA";
            } else {
                for (int j = 0; j < (int)resultado.size(); j++) {
                    if (j) cout << " ";
                    cout << resultado[j];
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
