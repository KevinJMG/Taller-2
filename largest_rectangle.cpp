#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


long largestRectangle(vector<int> h) {
    stack<int> s; // Guardará los índices de los edificios, no sus alturas.
    long max_area = 0; // Guardará el área máxima encontrada.
    int i = 0; // Índice para recorrer el arreglo de edificios.
    int n = h.size();
    
    // 1. Recorremos todos los edificios de izquierda a derecha.
    while (i < n) {
        // Si la pila está vacía, o el edificio actual es más alto (o igual) al que 
        // está en el tope de la pila, lo metemos a la pila y avanzamos (i++).
        if (s.empty() || h[s.top()] <= h[i]) {
            s.push(i++);
        } 
        // Si el edificio actual es más bajito, significa que el edificio en el tope 
        // de la pila ya no puede extenderse más hacia la derecha.
        else {
            int top_of_stack = s.top(); // Sacamos el índice del tope de la pila.
            s.pop();
            
            // Calculamos el ancho del rectángulo de ese edificio que acabamos de sacar.
            // Si la pila quedó vacía, su ancho abarca desde el inicio (índice 0) hasta 'i'.
            // Si no está vacía, su ancho está limitado por el nuevo tope de la pila a 
            // la izquierda y el índice actual 'i' a la derecha.
            long width = s.empty() ? i : i - s.top() - 1;
            
            // Área = altura * ancho. (Cast a long para evitar overflow)
            long area = (long)h[top_of_stack] * width;
            
            // Actualizamos el área máxima si es necesario.
            max_area = max(max_area, area);
        }
    }
    
    // 2. Si terminamos de recorrer los edificios pero quedaron algunos en la pila,
    // significa que esos edificios pueden extenderse hasta el puro final derecho del arreglo.
    // Hacemos el mismo cálculo de área para vaciar la pila.
    while (!s.empty()) {
        int top_of_stack = s.top();
        s.pop();
        long width = s.empty() ? i : i - s.top() - 1;
        long area = (long)h[top_of_stack] * width;
        max_area = max(max_area, area);
    }
    
    return max_area; // Retornamos la respuesta final.
}

int main() {
    int n;
    cout << "Ingresa la cantidad de edificios: ";
    if (!(cin >> n)) return 0; // Evita errores si no se ingresa nada

    vector<int> h(n);
    cout << "Ingresa las alturas separadas por espacio: ";
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    long result = largestRectangle(h);
    
    cout << "El area del rectangulo mas grande es: " << result << "\n";

    return 0;
}