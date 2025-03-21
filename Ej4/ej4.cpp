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
    auto startTime = std::chrono::high_resolution_clock::now();
    miProcesoAMedir();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
    endTime - startTime);
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << "nanosegundos" << std::endl;
    string texto1 = "Este es un ejemplo de texto que tiene más de sesenta y cuatro caracteres.";
    string texto2 = "Este es un ejemplo de texto que tiene más de sesenta y cuatro caracteres.";
    string texto3 = "Este es un ejemplo diferente de texto con más de sesenta y cuatro caracteres.";

    bool resultado1 = sonIguales(texto1, texto2);
    bool resultado2 = sonIguales(texto1, texto3);

    cout << "¿Texto1 y Texto2 son iguales? " << (resultado1 ? "Sí" : "No") << endl;
    cout << "¿Texto1 y Texto3 son iguales? " << (resultado2 ? "Sí" : "No") << endl;

    return 0;
}