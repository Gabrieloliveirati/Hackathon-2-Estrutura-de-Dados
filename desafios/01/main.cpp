#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> filhos(n + 1, 0);
    int raiz = 0;

    for (int i = 1; i <= n; i++) {
        int pai;
        cin >> pai;

        if (pai == 0) {
            raiz = i;
        } else {
            filhos[pai]++;
        }
    }

    int folhas = 0;
    int internos = 0;

    for (int i = 1; i <= n; i++) {
        if (filhos[i] == 0) {
            folhas++;
        } else {
            internos++;
        }
    }

    cout << raiz << " " << folhas << " " << internos << '\n';
    return 0;
}
