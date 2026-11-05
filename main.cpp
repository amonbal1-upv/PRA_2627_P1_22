#include <iostream>
#include <vector>
#include "ProgramacionDinamica.h"

int main() {
    std::cout << "=== PRUEBA: CAMBIO DE MONEDAS ===" << std::endl;
    
    std::vector<int> v = {1, 4, 6};
    int d = 8;
    std::vector<int> s_monedas;
    
    monedas(v, d, s_monedas);
    
    std::cout << "Cantidad a devolver: " << d << std::endl;
    std::cout << "Monedas disponibles: ";
    for (int moneda : v) {
        std::cout << moneda << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Solucion (cantidad de cada moneda):" << std::endl;
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "  Monedas de " << v[i] << ": " << s_monedas[i] << std::endl;
    }
    std::cout << "\n";

    std::cout << "=== PRUEBA 1: LA MOCHILA ===" << std::endl;
    
    std::vector<int> p1 = {9, 6, 5};
    std::vector<int> b1 = {38, 40, 24};
    int m1 = 15;
    std::vector<int> s_mochila1;
    
    int beneficio_max1 = mochila(p1, b1, m1, s_mochila1);
    
    std::cout << "Capacidad maxima: " << m1 << std::endl;
    std::cout << "Beneficio maximo obtenido: " << beneficio_max1 << std::endl;
    std::cout << "Elementos elegidos (1=Si, 0=No): ";
    for (int elegido : s_mochila1) {
        std::cout << elegido << " ";
    }
    std::cout << "\n\n";

    std::cout << "=== PRUEBA 2: LA MOCHILA ===" << std::endl;
    
    std::vector<int> p2 = {1, 3, 2, 4};
    std::vector<int> b2 = {10, 20, 15, 20};
    int m2 = 5;
    std::vector<int> s_mochila2;
    
    int beneficio_max2 = mochila(p2, b2, m2, s_mochila2);
    
    std::cout << "Capacidad maxima: " << m2 << std::endl;
    std::cout << "Beneficio maximo obtenido: " << beneficio_max2 << std::endl;
    std::cout << "Elementos elegidos (1=Si, 0=No): ";
    for (int elegido : s_mochila2) {
        std::cout << elegido << " ";
    }
    std::cout << std::endl;

    return 0;
}
