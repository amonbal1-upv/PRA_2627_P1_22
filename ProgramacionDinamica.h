#ifndef PROGRAMACION_DINAMICA_H
#define PROGRAMACION_DINAMICA_H

#include <vector>

// Función para el problema del Cambio de Monedas
void monedas(const std::vector<int>& v, int d, std::vector<int>& s);

// Función para el problema de la Mochila
int mochila(const std::vector<int>& p, const std::vector<int>& b, int m, std::vector<int>& s);

#endif // PROGRAMACION_DINAMICA_H
