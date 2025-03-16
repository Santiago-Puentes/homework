#include <iostream>
#include "ej1.hpp"

using namespace std;

vector<vector<int>> generarMatriz(int n) {
    vector<vector<int>> matriz(n, vector<int>(n));
    int contador = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = contador++;
        }
    }
    return matriz;
}

void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

void imprimirContMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    for (int i = n * n - 1; i >= 0; i--) {
        int fila = i / n;
        int columna = i % n;
        cout << "M[" << fila << "][" << columna << "] = " << matriz[fila][columna] << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese un valor entero positivo mayor a 1: ";
    cin >> n;
    
    if (n <= 1) {
        cout << "El valor debe ser mayor a 1." << endl;
        return 1;
    }
    
    vector<vector<int>> matriz = generarMatriz(n);
    imprimirMatriz(matriz);
    cout << "Contenido de la matriz:" << endl;
    imprimirContMatriz(matriz);
    
    return 0;
}
