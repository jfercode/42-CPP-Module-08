# 📦 CPP Module 08 – Contenedores Templados, Iteradores y Algoritmos

> ✅ **Objetivo**: Aprender y dominar el uso de los **contenedores STL**, **iteradores** y **algoritmos** en C++98, para manipular colecciones de datos de forma eficiente y segura.  
> ✅ **Nivel**: Avanzado  
> ✅ **Temas clave**: STL containers (`vector`, `list`, `stack`, etc.), algoritmos (`find`, `sort`, etc.), rango de iteradores, mutabilidad, excepciones, diseño seguro y práctico.

---

## 📚 Tabla de Contenidos

1. [¿Qué son los contenedores, iteradores y algoritmos STL?](#-qué-son-los-contenedores-iteradores-y-algoritmos-stl)
2. [Reglas Generales del Módulo](#-reglas-generales-del-módulo)
3. [Reglas Específicas del Módulo](#-reglas-específicas-del-módulo)
4. [Ejercicio 00 – EasyFind](#ejercicio-00--easyfind)
5. [Ejercicio 01 – Span](#ejercicio-01--span)
6. [Ejercicio 02 – MutantStack](#ejercicio-02--mutantstack)
7. [Tabla Resumen de STL y Algoritmos](#-tabla-resumen-de-stl-y-algoritmos)
8. [Errores Comunes](#-errores-comunes)
9. [Buenas Prácticas](#-buenas-prácticas)

---

## ✨ ¿Qué son los contenedores, iteradores y algoritmos STL?

La **STL (Standard Template Library)** de C++ proporciona herramientas genéricas y reutilizables para la gestión de colecciones de datos:

- **Contenedores STL**: Clases genéricas como `vector`, `list`, `stack`, `map`, etc., que almacenan y organizan datos de cualquier tipo.
- **Iteradores**: Objetos que permiten recorrer los elementos de un contenedor de manera uniforme, similar a los punteros.
- **Algoritmos**: Funciones como `find`, `sort`, `copy`, `for_each`, etc., que operan sobre rangos definidos por iteradores, permitiendo manipular los datos de los contenedores eficientemente.

El dominio de estos elementos es fundamental para programar en C++ de forma moderna, limpia y eficiente.

---

## 🔹 Reglas Generales del Módulo

- **Compilación**:  
  - Usar: `c++ -Wall -Wextra -Werror`
  - El código debe compilar con: `-std=c++98`
- **Nomenclatura y Formato**:  
  - Directorios: `ex00`, `ex01`, `ex02`, ...
  - Archivos de clases: `ClassName.hpp`/`.h` y `.cpp`/`.tpp` según corresponda.
  - Clases en UpperCamelCase; archivos con include guards.
- **Restricciones**:  
  - Prohibido: C++11/Boost, funciones `*printf()`, `*alloc()`, `free()`, `using namespace`, `friend`.
  - Permitido: Toda la STL desde este módulo, tanto contenedores como algoritmos.
  - Evitar memory leaks y cumplir la Orthodox Canonical Form desde el módulo 02.

---

## 🔸 Reglas Específicas del Módulo

- **¡Usa la STL!**  
  - Se permite y se espera el uso de contenedores y algoritmos estándar (`vector`, `list`, `stack`, `<algorithm>`, etc.).
  - No usar la STL será penalizado incluso si el código funciona.
  - Puedes definir templates en el header, o dividir en `.hpp` y `.tpp`.

---

## Ejercicio 00 – **EasyFind**

**Objetivo:**  
Crear una función template `easyfind` que, dado un contenedor de enteros y un valor, busque la primera ocurrencia de ese valor usando algoritmos STL.

**Puntos clave:**
- Debe aceptar cualquier contenedor estándar de enteros (`vector`, `list`, etc.).
- Retornar un iterador al elemento encontrado, o lanzar una excepción si no existe.
- Inspirarse en el comportamiento de los algoritmos STL (`std::find`).

**Ejemplo de uso:**
```cpp
std::vector<int> v = {1, 2, 3, 4};
try {
    std::vector<int>::iterator it = easyfind(v, 3);
    std::cout << "Encontrado: " << *it << std::endl;
} catch (std::exception &e) {
    std::cout << "No encontrado" << std::endl;
}
```

---

## Ejercicio 01 – **Span**

**Objetivo:**  
Implementar una clase `Span` capaz de almacenar hasta N enteros y calcular la distancia mínima y máxima entre sus elementos.

**Puntos clave:**
- Constructor recibe N (máximo de elementos a almacenar).
- `addNumber(int)`: Agrega un número. Lanza excepción si se rebasa la capacidad.
- `shortestSpan()`: Devuelve la menor diferencia entre elementos. Lanza excepción si no hay al menos dos números.
- `longestSpan()`: Devuelve la mayor diferencia entre elementos. Lanza excepción si no hay al menos dos números.
- Permite agregar múltiples números usando un rango de iteradores.
- Testea con al menos 10.000 números.

**Ejemplo de uso:**
```cpp
Span sp(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

std::cout << sp.shortestSpan() << std::endl; // 2
std::cout << sp.longestSpan() << std::endl;  // 14
```

---

## Ejercicio 02 – **MutantStack**

**Objetivo:**  
Extender `std::stack` para hacerla iterable mediante iteradores, manteniendo toda su funcionalidad.

**Puntos clave:**
- Implementar una clase template `MutantStack` basada en `std::stack`.
- Añadir iteradores (`begin()`, `end()`) para recorrer los elementos.
- El resto de funciones (`push`, `pop`, `top`, `size`, etc.) deben comportarse igual que en `std::stack`.
- El comportamiento debe ser equivalente al de otros contenedores iterables (`list`, etc.) al iterar y mostrar los elementos.

**Ejemplo de uso:**
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl; // 17
mstack.pop();
std::cout << mstack.size() << std::endl; // 1
mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);

for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    std::cout << *it << std::endl;
```

---

## 📊 Tabla Resumen de STL y Algoritmos

| Ejercicio            | STL/Algoritmo usado            | Razón principal                           |
|----------------------|-------------------------------|-------------------------------------------|
| 00 – EasyFind        | `std::find`                   | Búsqueda eficiente y genérica en contenedor|
| 01 – Span            | `std::vector`, iteradores     | Almacenamiento, recorrido y cálculo seguro |
| 02 – MutantStack     | `std::stack` + iteradores     | Pila iterable, extensión de funcionalidad  |

---

## 🔹 Errores Comunes

❌ No usar STL donde es requerido  
❌ No lanzar excepciones en casos límite (capacidad, span con <2 elementos, etc.)  
❌ No testear con suficientes datos (p.ej. <10,000 en Span)  
❌ Olvidar include guards o violar normas de nomenclatura  
❌ No implementar iteradores en MutantStack  
❌ Fugas de memoria o mal manejo de recursos

---

## 🔹 Buenas Prácticas

✅ Prefiere algoritmos STL antes que bucles manuales  
✅ Usa excepciones estándar (`std::exception`, etc.)  
✅ Documenta el comportamiento esperado de cada función  
✅ Haz pruebas con distintos contenedores y casos límite  
✅ Usa `const &` y `typedef` para mayor claridad y eficiencia  
✅ Escribe código claro, legible y fácilmente evaluable

---

## Autor 🤝💡📬

<div align="center">
  <a href="https://github.com/jfercode">
    <img src="https://github.com/jfercode.png" width="100px" alt="Javier Fernández Correa" />
    <br />
    <sub><b>Javier Fernández Correa</b></sub>
  </a>
</div>

---

## Licencia 📜✅🗝️

Este proyecto está bajo la licencia MIT.
