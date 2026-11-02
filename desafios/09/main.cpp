#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Registro {
    string identificador;
    int nota;
};

int main() {
    int n;
    cin >> n;

    vector<Registro> registros(n);

    for (int i = 0; i < n; i++) {
        cin >> registros[i].identificador >> registros[i].nota;
    }

    long long deslocamentos = 0;

    for (int i = 1; i < n; i++) {
        Registro chave = registros[i];
        int j = i - 1;

        while (j >= 0 && registros[j].nota > chave.nota) {
            registros[j + 1] = registros[j];
            deslocamentos++;
            j--;
        }

        registros[j + 1] = chave;
    }

    for (const Registro& registro : registros) {
        cout << registro.identificador << " " << registro.nota << '\n';
    }

    cout << "DESLOCAMENTOS " << deslocamentos << '\n';
    return 0;
}
