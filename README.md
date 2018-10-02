# Análisis Numérico
Conjunto de metodos de análisis numérico hechos en c++ con programación estructurada.

## Busqueda de raices
Los algoritmos utilizados para encontrar una aproximación a la raiz en una función son los siguientes: 

**- Bisección**

**- Punto fijo**

**- Newthon Raphson**

**- Secante**


## Solucion a sistemas de ecuaciones
Los algoritmos utilizados para encontrar solucion a sistemas de ecuaciones de nxn son:

**- Eliminación Gaussiana con y sin pivoteo parcial**. Para este metodo se utiliza el archivo *"PruebaEliminacionGaussiana.txt"*

**- Factorización LU**. Para este metodo se utiliza el archivo *"matrizlu.txt"*

**- Gauss Seidel**. Para este metodo se utiliza el archivo *"matrizseidel.txt"*


## Otros metodos
Aqui se encuentran diferentes metodos númericos que no pertenecen a las categorias anteriores.

**- Diferencias divididas de Newton**.  Programa que genera el polinomio interpolante con diferencias divididas de Newton de orden n, dados n+1 puntos. Este programa utiliza el archivo *"difdiv.txt"*

**- Lagrange**. Genera el polinomio interpolante de Lagrange de orden n, dados n+1 puntos. Este programa utiliza el archivo *"lagrange.txt"*

**- Regresión**. Implementa el método de Regresión Polinomial de orden m, para ajustar un conjunto de n puntos dados. Este programa utiliza el archivo *"Regresion.txt"*

**- Simpson**. Implementa la regla de simpson 1/3 y 3/8 para una función f(x) en un intervalo [a,b].

**- Trapecios**. Implementa la regla trapezoidal para integrar numéricamente una función f(x) en un intervalo [a,b].


## Todo en uno
Dentro de esta carpeta se encuentra el archivo ***MetodosNumericos.cpp*** el cual utiliza todos los metodos especificados anteriormente con un programa cliente, para así, facilitar al usuario la utilización de estos.
