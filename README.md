# HPC Learning

This repository is a structured journey through the landscape of High-Performance Computing. It serves as a practical companion to a curated curriculum, containing code implementations, performance benchmarks, and project work inspired by the foundational texts of the field.

## 🗺️ Roadmap & Curriculum

The repository is organized by phases, moving from C++ mastery to systems architecture and massive parallelism.

| Phase | Category | Primary Text(s) | Focus Area |
| :--- | :--- | :--- | :--- |
| **I** | **Foundation** | *A Tour of C++* / *Professional C++* | Modern Syntax, RAII, & Template Meta-programming. |
| **II** | **Systems** | *CS:APP* / *Linux System Programming* | Cache locality, Pipelining, & Syscalls. |
| **III** | **Workload** | *Hands-On Machine Learning* | Matrix Math & Computational Kernels. |
| **IV** | **Parallelism** | *Parallel & HPC* / *C++ Concurrency* | MPI, OpenMP, & Lock-free Data Structures. |
| **V** | **Performance** | *Effective Modern C++* / *Optimized C++* | Move Semantics & Profiling. |
| **VI** | **GPU** | *Programming Massively Parallel Processors* | CUDA Architecture & Memory Tiling. |

---

## 📂 Project Structure

Each folder corresponds to a specific book and contains my implementations of its concepts:

```text
.
├── 01_Foundation/
│   ├── Tour_of_CPP/
│   └── Professional_CPP/
├── 02_Systems/
│   ├── CSAPP/
│   └── Linux_Sys_Prog/
├── 03_Workload/
│   └── ML_Kernels/
├── 04_Parallelism/
│   ├── Concurrency_In_Action/
│   └── MPI_OpenMP_Lab/
├── 05_Performance/
│   └── Optimization_Experiments/
└── 06_GPU/
    └── CUDA_Massively_Parallel/
```

---

## 🛠️ Tech Stack & Tools
- **Languages:** C++20/23, CUDA C++
- **Build Systems:** CMake
- **Parallelism:** OpenMP, MPI, std::threads
- **Analysis:** Valgrind, Google Benchmark, Perf, NVIDIA Nsight
