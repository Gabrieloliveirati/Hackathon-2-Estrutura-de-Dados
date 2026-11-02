#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int calcularAltura(int no, const vector<int>& esq, const vector<int>& dir,
                   int& maiorDesequilibrio, bool& balanceada) {
    if (no == 0) return -1;

    int alturaEsq = calcularAltura(esq[no], esq, dir, maiorDesequilibrio, balanceada);
    int alturaDir = calcularAltura(dir[no], esq, dir, maiorDesequilibrio, balanceada);

    int diferenca = abs(alturaEsq - alturaDir);
    maiorDesequilibrio = max(maiorDesequilibrio, diferenca);

    if (diferenca > 1) balanceada = false;

    return max(alturaEsq, alturaDir) + 1;
}

int main() {
    int n, raiz;
    cin >> n >> raiz;

    vector<int> esq(n + 1), dir(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> esq[i] >> dir[i];
    }

    int maiorDesequilibrio = 0;
    bool balanceada = true;

    if (raiz != 0) {
        calcularAltura(raiz, esq, dir, maiorDesequilibrio, balanceada);
    }

    cout << (balanceada ? "SIM" : "NAO") << '\n';
    cout << maiorDesequilibrio << '\n';

    return 0;
}
