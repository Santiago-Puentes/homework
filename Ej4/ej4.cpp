#include <iostream>
#include <chrono>
#include <string>

bool compararCadenas(const std::string& str1, const std::string& str2, size_t index = 0) {
    if (index == str1.size() && index == str2.size()) return true;
    if (index >= str1.size() || index >= str2.size() || str1[index] != str2[index]) return false;
    return compararCadenas(str1, str2, index + 1);
}

constexpr bool sonIgualesComp(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) return false;
        ++str1;
        ++str2;
    }
    return *str1 == *str2;
}

int main() {
    std::string texto1 = "Este es un texto de prueba con al menos 64 caracteres para la comparación.";
    std::string texto2 = "Este es un texto de prueba con al menos 64 caracteres para la comparación.";

    auto startTime = std::chrono::high_resolution_clock::now();
    bool sonIguales = compararCadenas(texto1, texto2);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout << "Las cadenas son " << (sonIguales ? "iguales" : "diferentes") << ".\n";
    std::cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos.\n";

    constexpr const char* textoComp1 = "Texto de prueba en tiempo de compilación.";
    constexpr const char* textoComp2 = "Texto de prueba en tiempo de compilación.";

    bool sonIguales_2 = sonIgualesComp(textoComp1, textoComp2);

    auto startTime_2 = std::chrono::high_resolution_clock::now();
    std::cout << "Las cadenas en tiempo de compilación son " << (sonIgualesComp ? "iguales" : "diferentes") << ".\n";
    auto endTime_2 = std::chrono::high_resolution_clock::now();
    auto elapsedTime_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime_2 - startTime_2);
    std::cout << "Tiempo de ejecución: " << elapsedTime_2.count() << " nanosegundos.\n";

    // Utilizo string en vez de char para comparar en tiempo de ejecución porque
    // permite manipular y comparar cadenas dinámicamente.
    // Utilizo char en vez de string para comparar en tiempo de compilación porque 
    // permite que el compilador evalúe las cadenas antes de ejecutar el programa,
    // optimizando el rendimiento.
    return 0;
}
