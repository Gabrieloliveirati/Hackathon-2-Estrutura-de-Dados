#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct No {
    int chave;
    int frequencia;
    int altura;
    int total;
    No *esq, *dir;

    No(int valor)
        : chave(valor), frequencia(1), altura(1), total(1),
          esq(nullptr), dir(nullptr) {}
};

int altura(No* no) {
    return no ? no->altura : 0;
}

int total(No* no) {
    return no ? no->total : 0;
}

void atualizar(No* no) {
    if (!no) return;

    no->altura = 1 + max(altura(no->esq), altura(no->dir));
    no->total = no->frequencia + total(no->esq) + total(no->dir);
}

int fatorBalanceamento(No* no) {
    return no ? altura(no->esq) - altura(no->dir) : 0;
}

No* rotacaoDireita(No* y) {
    No* x = y->esq;
    No* meio = x->dir;

    x->dir = y;
    y->esq = meio;

    atualizar(y);
    atualizar(x);

    return x;
}

No* rotacaoEsquerda(No* x) {
    No* y = x->dir;
    No* meio = y->esq;

    y->esq = x;
    x->dir = meio;

    atualizar(x);
    atualizar(y);

    return y;
}

No* balancear(No* raiz) {
    if (!raiz) return nullptr;

    atualizar(raiz);
    int fator = fatorBalanceamento(raiz);

    if (fator > 1) {
        if (fatorBalanceamento(raiz->esq) < 0) {
            raiz->esq = rotacaoEsquerda(raiz->esq);
        }
        return rotacaoDireita(raiz);
    }

    if (fator < -1) {
        if (fatorBalanceamento(raiz->dir) > 0) {
            raiz->dir = rotacaoDireita(raiz->dir);
        }
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

No* inserir(No* raiz, int valor) {
    if (!raiz) return new No(valor);

    if (valor < raiz->chave) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->chave) {
        raiz->dir = inserir(raiz->dir, valor);
    } else {
        raiz->frequencia++;
        atualizar(raiz);
        return raiz;
    }

    return balancear(raiz);
}

No* menorNo(No* raiz) {
    while (raiz && raiz->esq) raiz = raiz->esq;
    return raiz;
}

No* remover(No* raiz, int valor) {
    if (!raiz) return nullptr;

    if (valor < raiz->chave) {
        raiz->esq = remover(raiz->esq, valor);
    } else if (valor > raiz->chave) {
        raiz->dir = remover(raiz->dir, valor);
    } else {
        if (raiz->frequencia > 1) {
            raiz->frequencia--;
            atualizar(raiz);
            return raiz;
        }

        if (!raiz->esq || !raiz->dir) {
            No* filho = raiz->esq ? raiz->esq : raiz->dir;
            delete raiz;
            return filho;
        }

        No* sucessor = menorNo(raiz->dir);
        raiz->chave = sucessor->chave;
        raiz->frequencia = sucessor->frequencia;
        sucessor->frequencia = 1;
        raiz->dir = remover(raiz->dir, sucessor->chave);
    }

    return balancear(raiz);
}

int consultarK(No* raiz, int k) {
    if (!raiz || k < 1 || k > total(raiz)) return -1;

    int esquerda = total(raiz->esq);

    if (k <= esquerda) return consultarK(raiz->esq, k);

    if (k <= esquerda + raiz->frequencia) return raiz->chave;

    return consultarK(raiz->dir, k - esquerda - raiz->frequencia);
}

void listar(No* raiz, vector<int>& valores) {
    if (!raiz) return;

    listar(raiz->esq, valores);

    for (int i = 0; i < raiz->frequencia; i++) {
        valores.push_back(raiz->chave);
    }

    listar(raiz->dir, valores);
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
            raiz = inserir(raiz, x);
        } else if (comando == 'R') {
            int x;
            cin >> x;
            raiz = remover(raiz, x);
        } else if (comando == 'K') {
            int k;
            cin >> k;

            if (k < 1 || k > total(raiz)) {
                cout << "INVALIDO\n";
            } else {
                cout << consultarK(raiz, k) << '\n';
            }
        } else if (comando == 'L') {
            vector<int> valores;
            listar(raiz, valores);

            if (valores.empty()) {
                cout << "VAZIA";
            } else {
                for (int j = 0; j < (int)valores.size(); j++) {
                    if (j) cout << " ";
                    cout << valores[j];
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
