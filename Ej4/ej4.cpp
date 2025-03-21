#include <iostream>
#include <string>
#include <chrono>

using namespace std;

bool sonIguales(const string& str1, const string& str2, size_t index = 0) {
    if (str1.length() != str2.length()) {
        return false;
    }
    if (index == str1.length()) {
        return true;
    }
    if (str1[index] != str2[index]) {
        return false;
    }
    return sonIguales(str1, str2, index + 1);
}

int main() {
    string texto1 = "Este es un ejemplo de texto que tiene más de sesenta y cuatro caracteres.";
    string texto2 = "Este es un ejemplo de texto que tiene más de sesenta y cuatro caracteres.";
    string texto3 = "Este es un ejemplo diferente de texto con más de sesenta y cuatro caracteres.";
    
    auto startTime = chrono::high_resolution_clock::now();
    
    bool resultado1 = sonIguales(texto1, texto2);
    bool resultado2 = sonIguales(texto1, texto3);
    
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

    cout << "¿Texto1 y Texto2 son iguales? " << (resultado1 ? "Sí" : "No") << endl;
    cout << "¿Texto1 y Texto3 son iguales? " << (resultado2 ? "Sí" : "No") << endl;

    cout << "A miProcesoSonIguales le tomó: " << elapsedTime.count() << " nanosegundos" << std::endl;

    return 0;
}