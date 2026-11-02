#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> valores(n);

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    long long comparacoes = 0;
    long long trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        int indiceMenor = i;

        for (int j = i + 1; j < n; j++) {
            comparacoes++;

            if (valores[j] < valores[indiceMenor]) {
                indiceMenor = j;
            }
        }

        if (indiceMenor != i) {
            swap(valores[i], valores[indiceMenor]);
            trocas++;
        }
    }

    if (valores.empty()) {
        cout << "VAZIA";
    } else {
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << valores[i];
        }
    }

    cout << '\n';
    cout << comparacoes << " " << trocas << '\n';

    return 0;
}
