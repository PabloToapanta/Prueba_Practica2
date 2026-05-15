# Universidad Técnica de Ambato
# Facultad de Ingeniería en Sistemas, Electrónica e Industrial

## Proyecto: Gestión de Estructuras de Datos mediante Árboles Binarios de Búsqueda
**Asignatura:** Estructura de Datos  
**Lenguajes de Programación:** C++  
**Estudiante:** Toapanta Paucar Pablo Daniel

---

## 1. Introducción
El presente proyecto consiste en el diseño e implementación de un sistema académico de gestión de estudiantes utilizando la estructura de datos de Árbol Binario de Búsqueda (BST). La solución ha sido desarrollada de forma bilingüe en los lenguajes C++ y Java, aplicando principios de programación orientada a objetos, recursividad y gestión eficiente de memoria.

El sistema permite organizar la información estudiantil (cédula, nombres, notas, carrera y nivel) tomando como clave primaria la cédula de identidad, garantizando un acceso logarítmico a la información.

## 2. Características Técnicas
### Implementación en C++
- Uso de punteros para la gestión de nodos.
- Implementación de memoria dinámica para la creación y eliminación de registros.
- Modularización mediante estructuras y clases.


## 3. Funcionalidades del Sistema
El software incluye las siguientes capacidades obligatorias:
- Inserción y eliminación de nodos (estudiantes).
- Búsqueda binaria por número de cédula.
- Recorridos de profundidad (Inorden, Preorden, Postorden).
- Recorrido en anchura (Por niveles/BFS).
- Cálculos estructurales: altura del árbol y conteo total de nodos.
- Filtros de rendimiento académico: identificación de notas máximas, mínimas, estudiantes aprobados y reprobados.

## 4. Instrucciones de Ejecución

### Entorno C++
1. Compilar el archivo principal: `g++ -o sistema_academico main.cpp`
2. Ejecutar el binario generado: `./sistema_academico`

---

## 5. Evidencias de Ejecución

A continuación se presentan las capturas de pantalla que validan el correcto funcionamiento de cada módulo del sistema:

### Gestión de Datos y Búsqueda
**Inserción de un nuevo registro:**
![Inserción de estudiante](capturas/ejecucion_insertar_estudiante.png)

**Búsqueda de estudiante por cédula:**
![Buscar estudiante](capturas/ejecucion_buscar_estudiante.png)

### Recorridos del Árbol
**Recorrido Inorden (Orden ascendente por cédula):**
![Recorrido Inorden](capturas/ejecucion_recorrido_inorden.png)

**Recorrido Preorden:**
![Recorrido Preorden](capturas/ejecucion_recorrido_preorden.png)

**Recorrido Postorden:**
![Recorrido Postorden](capturas/ejecucion_recorrido_postorden.png)

**Recorrido por Niveles (BFS):**
![Recorrido BFS](capturas/ejecucion_recorrido_BFS.png)

### Métricas y Estadísticas
**Cálculo de la altura del árbol:**
![Altura del árbol](capturas/ejecucion_calcular_altura_arbol.png)

**Conteo total de registros:**
![Conteo de estudiantes](capturas/ejecucion_contar_total_estudiantes.png)

### Reportes Académicos
**Estudiante con el mejor rendimiento (Nota Mayor):**
![Nota Mayor](capturas/ejecucion_mostrar_estudiante_mayor_nota.png)

**Estudiante con el menor rendimiento (Nota Menor):**
![Nota Menor](capturas/ejecucion_nota_menor.png)

**Listado de estudiantes aprobados:**
![Alumnos aprobados](capturas/ejecucion_alumnos_aprobados.png)

**Listado de estudiantes reprobados:**
![Alumnos reprobados](capturas/ejecucion_alumnos_reprobados.png)

---

### Commits Generados

![Commits](capturas/commits.png)

## 6. Conclusiones
La implementación exitosa de este sistema demuestra la versatilidad de los Árboles Binarios de Búsqueda para el manejo de información jerárquica y ordenada.