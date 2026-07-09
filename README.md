# Taller 2 HackerRank

===============================

Ambos ejercicios se pueden compilar desde GitHub CodeSpace: vas al botón verde **"Code"**, creas un espacio virtual y, en la terminal, compilas y ejecutas.

---

## 1. Rectángulo más Grande (`largest_rectangle.cpp`)

Encuentra el área máxima en un histograma usando **Monotonic Stack** (`O(N)`).

**Compilar:**

```bash
g++ largest_rectangle.cpp -o rectangle
```

**Ejecutar:**

```bash
./rectangle
```

```
Ingresa la cantidad de edificios: 5
Ingresa las alturas separadas por espacio: 1 2 3 4 5
```

**Output esperado:**

```
El area del rectangulo mas grande es: 9
```

---

## 2. Detección de Ciclos (`cycle_detection.cpp`)

Detecta ciclos en listas enlazadas usando el **Algoritmo de Floyd**.

**Compilar:**

```bash
g++ cycle_detection.cpp -o cycle
```

**Ejecutar** (muestra ambos casos de prueba):

```bash
./cycle
```

**Output esperado:**

```
========================================================
PRUEBA 1: Evaluando estructura lineal
Nodos: [1] -> [2] -> [3] -> NULL
--------------------------------------------------------
RESULTADO: >> No hay ciclo <<
========================================================

========================================================
PRUEBA 2: Evaluando estructura circular
Nodos: [1] -> [2] -> [3] -> (apunta de nuevo a [1])
--------------------------------------------------------
RESULTADO: >> Se detecto un ciclo <<
========================================================
```

> `cycle_detection` ya ejecuta ambas pruebas automáticamente.

---

## Estructura del proyecto

```
taller-algoritmos-cpp/
├── largest_rectangle.cpp
├── cycle_detection.cpp
└── README.md
```

---

## Referencias

- **Largest Rectangle:** https://www.hackerrank.com/challenges/largest-rectangle
- **Cycle Detection:** https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle
