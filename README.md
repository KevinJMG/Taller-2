#Taller 2 HackerRank 
# ===============================
#  Ambos ejercicios se puedes copilar desde Github CodeSpace, vas a el boton verde "code" y creas un espacio virtual, en la terminal copilas y ejecutas.
#  1. Rectángulo más Grande (largest_rectangle.cpp)
# ------------------------------------------------
# Encuentra el área máxima en un histograma usando Monotonic Stack (O(N))

# Compilar
g++ largest_rectangle.cpp -o rectangle

# Ejecutar
./rectangle
# Ingresa la cantidad de edificios: 5
# Ingresa las alturas separadas por espacio: 1 2 3 4 5

# Output esperado:
# El area del rectangulo mas grande es: 9


#  2. Detección de Ciclos (cycle_detection.cpp)
# ---------------------------------------------
# Detecta ciclos en listas enlazadas usando Algoritmo de Floyd

# Compilar
g++ -std=c++17 cycle_detection.cpp -o cycle

# Ejecutar (muestra ambos casos de prueba)
./cycle

# Output esperado:
# ========================================================
# PRUEBA 1: Evaluando estructura lineal
# Nodos: [1] -> [2] -> [3] -> NULL
# --------------------------------------------------------
# RESULTADO: >> No hay ciclo <<
# ========================================================
# 
# ========================================================
# PRUEBA 2: Evaluando estructura circular
# Nodos: [1] -> [2] -> [3] -> (apunta de nuevo a [1])
# --------------------------------------------------------
# RESULTADO: >> Se detecto un ciclo <<
# ========================================================


#  Pruebas adicionales
# ---------------------

# largest_rectangle - Caso con múltiples picos
echo -e "6\n2 1 5 6 2 3" | ./rectangle
# Output esperado: 10

# cycle_detection - Ya ejecuta ambas pruebas automáticamente


#  Estructura del proyecto
# -------------------------
# taller-algoritmos-cpp/
# ├── largest_rectangle.cpp
# ├── cycle_detection.cpp
# └── README.md


#  Notas técnicas
# ----------------
# - largest_rectangle: Stack de índices para mantener alturas crecientes
# - cycle_detection: Punteros slow y fast (1 y 2 pasos)
# - Complejidad: Ambos algoritmos son O(N)
# - Espacio: O(N) en el peor caso


#  Referencias
# -------------
# - Largest Rectangle: https://www.hackerrank.com/challenges/largest-rectangle
# - Cycle Detection: https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle
