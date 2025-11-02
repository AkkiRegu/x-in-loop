# GPU_vs_CPU_AEB

Copyright of Akshay Karjol and Kedar Rege  
Created Date - 2 NOV 2025

## Project Overview

[TODO: Add project description]

## Project Structure

- **core/** - Core solver mathematics
  - `stepper.h` - RK/AB/implicit math (header-only, device-agnostic)
  - `rhs.h` - user RHS functors (no I/O, pure math)

- **backends/** - Parallel execution backends
  - `cpu_backend.h` - parallel_for, reduce via OpenMP/TBB
  - `gpu_backend.h` - parallel_for, reduce via SYCL/CUDA/HIP

- **drivers/** - Backend integration drivers
  - `solve_cpu.cpp` - wires core + cpu_backend
  - `solve_gpu.cpp` - wires core + gpu_backend

## Installation

Mount the git repo on the local machine which consists of any GPU 
``` git clone https://github.com/AkkiRegu/x-in-loop.git ```

Checkout the branch neccessary fot this study 

``` git checkout user/krege/AEB-solver ```
## Usage

[ To Do - @akarjol , Update this once the shell script is running and how to integrate this infra for any use case ]


## License

[Open source development as of NOV 2 2025]

