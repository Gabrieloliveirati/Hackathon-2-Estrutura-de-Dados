#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, raiz;
    cin >> n >> raiz;

    vector<int> esq(n + 1), dir(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> esq[i] >> dir[i];
    }

    if (n == 0 || raiz == 0) {
        cout << "-1 0\n";
        return 0;
    }

    queue<pair<int, int>> fila;
    fila.push({raiz, 0});

    int altura = 0;
    int largura = 0;

    while (!fila.empty()) {
        int quantidade = (int)fila.size();
        largura = max(largura, quantidade);

        for (int i = 0; i < quantidade; i++) {
            auto atual = fila.front();
            fila.pop();

            int no = atual.first;
            int nivel = atual.second;
            altura = max(altura, nivel);

            if (esq[no]) fila.push({esq[no], nivel + 1});
            if (dir[no]) fila.push({dir[no], nivel + 1});
        }
    }

    cout << altura << " " << largura << '\n';
    return 0;
}
