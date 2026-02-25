Implementar un algoritmo híbrido (MPI + OpenMP) con migración de datos es un reto excelente. Para asegurar el máximo rendimiento y mantener el código limpio y profesional, dividiremos el proyecto en cuatro fases incrementales.

A continuación, te presento el *roadmap* de implementación. Como solicitaste, todos los nombres de variables, funciones, estructuras y comentarios en el código estarán en inglés, siguiendo estrictamente el estándar de estilo de Google C++ para garantizar una base sólida en HPC.

### Phase 1: Foundation & Data Distribution (MPI I/O)

El primer paso es lograr que todos los nodos tengan su porción de datos en memoria de forma eficiente.

1. **Implement Memory Models**: Crear los *structs* `Dataset`, `Centroids` y `ColumnStats` utilizando memoria contigua (vectores 1D) para maximizar la localidad de caché.
2. **Binary Reader**: Leer el archivo binario inicial. El formato consta de `UINT32` para filas, `UINT32` para columnas, y `REAL32` para los valores. El nodo maestro (`rank == 0`) leerá el archivo completo o utilizará MPI-IO para lecturas paralelas.


3. **Data Partitioning**: Distribuir los datos equitativamente entre los nodos basándose en el índice. Por ejemplo, el nodo 0 recibe los datos del 0 al 249. Utilizarás `MPI_Scatterv` para enviar a cada nodo su `std::vector<float>` correspondiente.



### Phase 2: Local Data Analysis (OpenMP)

Antes de entrar en el bucle del K-medias, resolveremos el cálculo de estadísticas.

1. **Local Statistics**: Cada nodo calculará el mínimo, máximo, media y varianza de sus filas locales para cada columna.


2. **OpenMP Parallelization**: Utilizarás `#pragma omp parallel for` con cláusulas de reducción (`reduction(min:...)`, `reduction(+:...)`) sobre las columnas de grano fino.
3. **Global Reduction**: Una vez que cada nodo tiene sus estadísticas locales, utilizarás `MPI_Allreduce` para obtener los mínimos y máximos globales, y sumar las varianzas y medias locales para calcular los valores globales.

### Phase 3: The K-Means Engine (Hybrid Computation & Communication)

Esta es la fase crítica donde la memoria compartida y distribuida interactúan. Debes implementar el bucle iterativo con los criterios de parada: máximo 2000 iteraciones o menos del 5% de puntos desplazados.

1. **Centroid Initialization**: El nodo maestro calcula los centroides iniciales o selecciona los primeros  puntos y los transmite a todos los nodos usando `MPI_Bcast`.


2. **Distance Calculation (OpenMP)**: Cada nodo calcula la distancia de sus puntos a todos los centroides. Este bucle anidado es el núcleo matemático y debe ser paralelizado con OpenMP (grano fino).


3. **Point Migration (MPI)**: Si un punto es más cercano a un centroide gestionado por otro nodo, debe ser enviado a ese nodo. Tendrás que empaquetar los puntos que cambian de dueño y usar comunicaciones asíncronas (`MPI_Isend` / `MPI_Irecv`) o `MPI_Alltoallv` para intercambiarlos.


4. **Centroid Update**: Tras mover los puntos, cada nodo recalcula el centroide de los grupos que gestiona. Luego, todos los nodos se comunican las actualizaciones de los centroides.



### Phase 4: Profiling & Documentation

1. **Timing**: Insertar llamadas a `MPI_Wtime()` alrededor de las fases de I/O, cálculo y comunicación para identificar cuellos de botella.
2. **Design Justification**: Redactar el documento final explicando por qué usaste vectores 1D (Structure of Arrays) y cómo combinaste `MPI_Alltoallv` con OpenMP, tal como exige la práctica.
