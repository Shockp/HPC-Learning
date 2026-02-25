# HPC Learning

A hands-on journey through High-Performance Computing—from modern C++ fundamentals to GPU-accelerated workloads. Each phase maps to a directory in this repository, containing implementations, exercises, and benchmarks drawn from the field's foundational texts.

---

## 🗺️ Roadmap & Curriculum

### Phase 1: Core Fundamentals & Hardware Awareness
Before writing extremely fast code, you need a solid grasp of modern C++ and exactly how the underlying hardware executes it.

- **A Tour of C++, 3rd Edition**
  - *Why here:* This is your primer. It gives you a fast, comprehensive overview of modern C++ features without getting bogged down in edge cases.

- **Computer Systems: A Programmer's Perspective**
  - *Why here:* This is arguably the most important foundational book for HPC. It teaches you how code translates to assembly, how the CPU pipeline works, and crucially, how CPU caches operate. You cannot write high-performance C++ without understanding memory hierarchy.

### Phase 2: C++ Mastery & Single-Threaded Performance
With a hardware mindset established, it is time to master the C++ language and learn how to extract maximum performance from a single CPU core.

- **Professional C++, 6th Edition**
  - *Why here:* This fills in the deep language details that the Tour skipped. It covers memory management, templates, and standard library features that are critical for writing robust systems.

- **Effective Modern C++, by Scott Meyers**
  - *Why here:* This shifts your focus from "writing C++ that works" to "writing C++ the right way." It teaches crucial performance concepts like perfect forwarding, move semantics, and the correct use of smart pointers.

- **Optimized C++, by Kurt Guntheroth**
  - *Why here:* Now you apply your language mastery to pure performance. This book will teach you how to benchmark, profile, and optimize memory allocation, strings, and data structures.

### Phase 3: The OS Interface & Concurrency
Scaling up requires understanding how the operating system handles resources and how to write code that safely executes on multiple threads.

- **Linux System Programming, 2nd Edition**
  - *Why here:* HPC clusters run on Linux. Understanding system calls, process management, file I/O, and POSIX standards is necessary before you start distributing workloads across network nodes.

- **C++ Concurrency in Action, Second Edition**
  - *Why here:* This bridges the gap between single-threaded performance and parallel computing. It covers the C++ memory model, atomics, mutexes, and lock-free programming—essential skills for preventing race conditions and keeping CPU cores fed.

### Phase 4: Scaling to HPC and Accelerators
This is where you move from standard multi-threading to massive scale, utilizing specialized hardware and distributed systems.

- **Parallel and High Performance Computing**
  - *Why here:* This introduces you to the broader HPC ecosystem. You will move beyond standard `std::thread` and learn industry standards like OpenMP (for multi-core scaling), MPI (for multi-node cluster scaling), and vectorization.

- **Programming Massively Parallel Processors, 4th Edition**
  - *Why here:* GPUs handle the bulk of modern HPC workloads. With a strong grasp of CPU concurrency and memory, you are ready to learn CUDA and adapt your algorithms for massive SIMD (Single Instruction, Multiple Data) execution.

### Phase 5: Applied Domain Knowledge
- **Hands-On Machine Learning with C++**
  - *Why here:* This acts as your capstone project. Machine learning relies heavily on linear algebra, massive datasets, and GPU acceleration. It allows you to apply your optimized, parallel C++ skills to a real-world, highly demanding workload.

> **Pro-Tip for your progression:** As you work through these books, write your practice exercises adhering strictly to the Google C++ style guide. Enforcing strict styling early on makes reading, profiling, and debugging complex parallel code much easier later.

---

## 📂 Project Structure

Each directory maps directly to a curriculum phase. Sub-folders correspond to individual books or courses:

```text
.
├── 00_university/                          # University coursework
│   ├── 01_OpenMP/                          #   OpenMP + MPI project
│   └── 02_CUDA/                            #   CUDA project
├── 01_fundamentals/                        # Phase 1
│   ├── 01_tour_of_cpp/                     #   A Tour of C++
│   └── 02_cs_programmer_perspective/       #   CS:APP
├── 02_cpp_mastery/                         # Phase 2
│   ├── 01_professional_cpp/                #   Professional C++
│   ├── 02_effective_modern_cpp/            #   Effective Modern C++
│   └── 03_optimized_cpp/                   #   Optimized C++
├── 03_os_and_concurrency/                  # Phase 3
│   ├── 01_linux_sys_programming/           #   Linux System Programming
│   └── 02_concurrency_in_action/           #   C++ Concurrency in Action
├── 04_parallel_and_gpu/                    # Phase 4
│   ├── 01_parallel_and_hpc/                #   Parallel & HPC
│   └── 02_prog_massiv_parallel_proc/       #   Programming Massively Parallel Processors
└── 05_applied_ml/                          # Phase 5
    └── 01_hands_on_ml/                     #   Hands-On ML with C++
```

---

## 🛠️ Tech Stack & Tools
- **Languages:** C++17, CUDA C++
- **Build Systems:** CMake, Make
- **Parallelism:** OpenMP, MPI, `std::thread`
- **Tooling:** Clangd, GDB
- **Analysis:** Valgrind, Google Benchmark, Perf, NVIDIA Nsight
