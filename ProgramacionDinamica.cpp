#include "ProgramacionDinamica.h"
#include <algorithm>
#include <limits>

// Implementación del problema del Cambio de Monedas
void monedas(const std::vector<int>& v, int d, std::vector<int>& s) {
    int n = v.size();
    int inf_val = std::numeric_limits<int>::max();
    
    // Tabla T inicializada a inf_val, excepto para m=0 que será 0
    std::vector<std::vector<int>> T(n, std::vector<int>(d + 1, inf_val));
    for (int i = 0; i < n; ++i) {
        T[i][0] = 0;
    }

    // Cálculo de la primera fila
    for (int j = 1; j <= d; ++j) {
        if (j >= v[0] && T[0][j - v[0]] != inf_val) {
            T[0][j] = 1 + T[0][j - v[0]];
        }
    }

    // Cálculo del resto de la tabla
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= d; ++j) {
            if (j < v[i] || T[i][j - v[i]] == inf_val) {
                T[i][j] = T[i - 1][j];
            } else if (T[i - 1][j] != inf_val) {
                T[i][j] = std::min(T[i - 1][j], 1 + T[i][j - v[i]]);
            } else {
                T[i][j] = 1 + T[i][j - v[i]];
            }
        }
    }

    // Recuperar la solución inicializando el vector s a ceros
    s.assign(n, 0);
    int i = n - 1;
    int j = d;
    
    while (i != 0 && j != 0) {
        if (i == 0 || T[i][j] != T[i - 1][j]) {
            s[i] = s[i] + 1;
            j = j - v[i];
        } else {
            i = i - 1;
        }
    }
    
    // Si quedan restos en la primera fila (moneda 0)
    while (j > 0 && T[0][j] != inf_val) {
        s[0] = s[0] + 1;
        j = j - v[0];
    }
}

// Implementación del problema de la Mochila
int mochila(const std::vector<int>& p, const std::vector<int>& b, int m, std::vector<int>& s) {
    int n = p.size();
    
    // Tabla g(i, C) inicializada a 0
    std::vector<std::vector<int>> g(n + 1, std::vector<int>(m + 1, 0));

    // Llenado de la matriz mediante iteración
    for (int i = 1; i <= n; ++i) {
        for (int c = 0; c <= m; ++c) {
            if (p[i - 1] > c) {
                g[i][c] = g[i - 1][c];
            } else {
                g[i][c] = std::max(g[i - 1][c], g[i - 1][c - p[i - 1]] + b[i - 1]);
            }
        }
    }

    // Recuperar la solución (qué elementos se han elegido)
    s.assign(n, 0);
    int res = g[n][m];
    int c = m;
    
    for (int i = n; i > 0 && res > 0; --i) {
        if (res == g[i - 1][c]) {
            continue; // No se incluyó el elemento
        } else {
            s[i - 1] = 1; // Se incluyó el elemento
            res -= b[i - 1];
            c -= p[i - 1];
        }
    }

    // Devolver el beneficio máximo
    return g[n][m];
}
