#include "ej2.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void logMessage(const string& mensaje, NivelSeveridad nivel) {
    ofstream logFile("log.txt", ios_base::app);
    if (!logFile.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    switch (nivel) {
        case DEBUG:
            logFile << "[DEBUG] " << mensaje << endl;
            break;
        case INFO:
            logFile << "[INFO] " << mensaje << endl;
            break;
        case WARNING:
            logFile << "[WARNING] " << mensaje << endl;
            break;
        case ERROR:
            logFile << "[ERROR] " << mensaje << endl;
            break;
        case CRITICAL:
            logFile << "[CRITICAL] " << mensaje << endl;
            break;
        case SECURITY:
            logFile << "[SECURITY] " << mensaje << endl;
            break;
    }

    logFile.close();
}

void logMessage(const string& mensaje, const string& archivo, int linea) {
    ofstream logFile("log.txt", ios_base::app);
    if (!logFile.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    logFile << "[ERROR] " << mensaje << " Archivo: " << archivo << " Línea: " << linea << endl;
    logFile.close();
}

void logMessage(const string& mensaje, const string& usuario) {
    ofstream logFile("log.txt", ios_base::app);
    if (!logFile.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    logFile << "[SECURITY] " << mensaje << " Usuario: " << usuario << endl;
    logFile.close();
}

int main() {
    logMessage("Este es un mensaje de depuración.", DEBUG);
    logMessage("Este es un mensaje informativo.", INFO);
    logMessage("Este es un mensaje de advertencia.", WARNING);
    logMessage("Este es un mensaje de error.", ERROR);
    logMessage("Este es un mensaje crítico.", CRITICAL);
    logMessage("Access Granted", "usuario1");
    logMessage("Access Denied", "usuario2");

    try {
        throw runtime_error("Error de prueba en tiempo de ejecución");
    } catch (const runtime_error& e) {
        logMessage(e.what(), __FILE__, __LINE__);
        return 1;
    }

    return 0;
}
