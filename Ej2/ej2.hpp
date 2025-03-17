#ifndef EJ2_HPP
#define EJ2_HPP

#include <string>

enum NivelSeveridad {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    SECURITY
};

void logMessage(const std::string& mensaje, NivelSeveridad nivel);
void logMessage(const std::string& mensaje, const std::string& archivo, int linea);
void logMessage(const std::string& mensaje, const std::string& usuario);

#endif // EJ2_HPP
