# Justificación de Diseño - Práctica 1 (K-Medias)

## 1. Introducción y Objetivos
[cite_start]El objetivo principal de esta práctica es desarrollar un programa capaz de analizar una gran cantidad de datos en el mínimo tiempo posible[cite: 10]. [cite_start]Para lograrlo, el sistema implementa el algoritmo k-medias para la agrupación de datos y calcula estadísticas fundamentales (media, mínimo, máximo y varianza) para cada columna[cite: 11]. 

[cite_start]Para maximizar el rendimiento, el diseño se fundamenta en una estrategia de paralelización híbrida, combinando memoria distribuida (OpenMPI) para tareas de grano grueso, con memoria compartida (OpenMP) para secciones de grano fino[cite: 12]. [cite_start]Este documento detalla y justifica las decisiones arquitectónicas tomadas, cumpliendo con los requisitos de evaluación de la asignatura[cite: 68, 69].

## 2. Diseño de Estructuras de Datos
La decisión arquitectónica más crítica ha sido el rechazo del paradigma clásico de Programación Orientada a Objetos (POO) en favor de un Diseño Orientado a Datos (Data-Oriented Design).

* **Rechazo de Array of Structures (AoS):** Modelar entidades individuales (como una clase `Point` con atributos propios) fragmenta la memoria y destruye la localidad espacial en la caché de la CPU.
* **Implementación de Structure of Arrays (SoA) / Vectores Contiguos:** Las entidades `Dataset` y `Centroids` se han implementado utilizando `std::vector<float>` unidimensionales. 
* **Beneficios de Rendimiento:** Al aplanar la matriz 2D en un bloque de memoria contiguo, garantizamos que los accesos a memoria durante los bucles de cálculo (ej. distancias euclidianas) sean predecibles. Esto minimiza los fallos de caché (cache misses) y permite que el compilador aplique auto-vectorización (instrucciones SIMD/AVX) de forma agresiva.
* [cite_start]**Optimización de Comunicaciones:** El uso de memoria contigua facilita la transmisión de bloques de datos entre nodos mediante MPI sin necesidad de empaquetar y desempaquetar estructuras complejas línea por línea[cite: 69].

## 3. Estrategia de Paralelización y Reparto de Carga
[cite_start]La combinación de OpenMPI y OpenMP se ha diseñado para explotar la arquitectura del clúster en dos niveles distintos[cite: 12]:

### 3.1. Nivel Inter-Nodo (Grano Grueso) - OpenMPI
* **Reparto Inicial de Datos:** El particionado del `Dataset` se realiza dividiendo equitativamente las filas entre los procesos MPI disponibles, basándose en su índice. Esto asegura un balanceo de carga estático inicial perfecto para la fase de lectura y el primer cálculo.
* **Migración de Puntos:** Cuando los puntos cambian de grupo y de nodo propietario, se utilizarán rutinas de comunicación colectiva o punto a punto (`MPI_Alltoallv` o `MPI_Isend`/`MPI_Irecv`) para gestionar la reasignación dinámicamente.
* [cite_start]**Actualización de Centroides:** Todos los nodos deben comunicarse las actualizaciones de los centroides[cite: 41]. Se empleará `MPI_Allreduce` para sumarizar las coordenadas parciales de los grupos y calcular las nuevas medias globalmente de forma eficiente.

### 3.2. Nivel Intra-Nodo (Grano Fino) - OpenMP
* **Cálculo de Distancias:** El bucle interno donde cada nodo calcula la distancia de sus puntos a todos los centroides asignados es paralelizado con hilos de OpenMP. Dado que las iteraciones son independientes y los datos están en memoria contigua, esta es la sección ideal para un bloque `#pragma omp parallel for`.
* [cite_start]**Cálculo de Estadísticas:** El cálculo de mínimos, máximos, medias y varianzas se paraleliza a nivel de hilo utilizando cláusulas de reducción (`reduction(min:...)`, `reduction(max:...)`, etc.) para evitar condiciones de carrera sin penalizar el rendimiento con *locks* manuales[cite: 11, 12].

## 4. Pruebas Experimentales y Profiling (Pendiente)
[cite_start]*(Esta sección se completará tras la implementación final, incluyendo tiempos de ejecución reales utilizando `MPI_Wtime()` para demostrar empíricamente las mejoras de rendimiento conseguidas por las decisiones descritas anteriormente[cite: 68].)*