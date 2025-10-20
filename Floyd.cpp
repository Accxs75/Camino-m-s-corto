
//Fuente: https://www.youtube.com/watch?v=h-nmexY9gtA
#include <iostream>   
#include <iomanip>    
using namespace std;

const int INF = 9999; 
const int N = 5;     
int main() {
    char vertices[N] = {'A', 'B', 'C', 'D', 'E'};

    // Matriz de distancias iniciales entre los vértices
    // D[i][j] representa la distancia directa de i hacia j
    int D[N][N] = {
        {0, 4, 5, 6, 7},
        {4, 0, 1, 2, 3},
        {8, 6, 0, 4, 2},
        {6, 2, 3, 0, 5},
        {10, 8, 2, 6, 0}
    };

    // Matriz de recorridos (para saber el siguiente vértice en el camino más corto)
    char R[N][N];

    //  Inicialización de la matriz de recorridos 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                // Si el vértice es el mismo, no hay recorrido
                R[i][j] = '-';
            else if (D[i][j] != INF)
                // Si existe una conexión directa, el siguiente vértice en el camino
                // desde i hasta j es j mismo
                R[i][j] = vertices[j];
            else
                // Si no hay conexión directa, no hay recorrido
                R[i][j] = '-';
        }
    }


    // Busca los caminos más cortos entre todos los pares de vértices
    for (int k = 0; k < N; k++) {          //  vértice intermedio
        for (int i = 0; i < N; i++) {      //  vértice de origen
            for (int j = 0; j < N; j++) {  // es el vértice de destino
                // Si pasar por k mejora la distancia de i a j, actualiza
                if (D[i][k] + D[k][j] < D[i][j]) {
                    // Se encontró un camino más corto pasando por k
                    D[i][j] = D[i][k] + D[k][j];

                    
                    // será el mismo que el primer paso para ir de i a k
                    R[i][j] = R[i][k];
                }
            } //“En otras palabras, el algoritmo va probando todos los caminos posibles y se queda con el más corto.”
        }
    }

    // --- Mostrar la matriz de distancias finales ---
    cout << "Matriz de distancias finales:\n    ";
    for (int i = 0; i < N; i++) cout << vertices[i] << "   ";
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << vertices[i] << " ";
        for (int j = 0; j < N; j++) {
            // Si la distancia es infinita, muestra '8' (representando 8)
            if (D[i][j] == INF)
                cout << setw(3) << "8";
            else
                // Si hay distancia finita, muestra el valor numérico
                cout << setw(3) << D[i][j];
            cout << " ";
        }
        cout << endl;
    }

    // 
    cout << "\nMatriz de recorridos:\n    ";
    for (int i = 0; i < N; i++) cout << vertices[i] << "   ";
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << vertices[i] << " ";
        for (int j = 0; j < N; j++) {
            // Muestra el siguiente vértice en el camino más corto
            cout << setw(3) << R[i][j] << " ";
        }
        cout << endl;
    }

    return 0; 
}
