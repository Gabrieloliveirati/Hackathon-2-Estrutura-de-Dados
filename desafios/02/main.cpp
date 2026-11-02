#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n, raiz;
    cin >> n >> raiz;

    vector<int> esq(n + 1);
    vector<int> dir(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> esq[i] >> dir[i];
    }

    vector<int> pre, emOrdem, pos;
    if (raiz != 0) {
        stack<pair<int, int>> pilha;
        pilha.push({raiz, 0});

        while (!pilha.empty()) {
            auto atual = pilha.top();
            pilha.pop();

            int no = atual.first;
            int estado = atual.second;

            if (estado == 0) {
                pre.push_back(no);
                pilha.push({no, 1});
                if (esq[no] != 0) pilha.push({esq[no], 0});
            } else if (estado == 1) {
                emOrdem.push_back(no);
                pilha.push({no, 2});
                if (dir[no] != 0) pilha.push({dir[no], 0});
            } else {
                pos.push_back(no);
            }
        }
    }

    auto imprimir = [](const vector<int>& v) {
        if (v.empty()) {
            cout << "VAZIA";
        } else {
            for (int i = 0; i < (int)v.size(); i++) {
                if (i) cout << " ";
                cout << v[i];
            }
        }
        cout << '\n';
    };

    imprimir(pre);
    imprimir(emOrdem);
    imprimir(pos);

    return 0;
}
