# GPU_vs_CPU_AEB

Copyright of Akshay Karjol and Kedar Rege  
Created Date

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

[TODO: Add installation instructions]

## Usage

[TODO: Add usage examples]

## Dependencies

[TODO: List dependencies]

## Build Instructions

[TODO: Add build instructions]

## Results

[TODO: Document performance results]

## License

[TODO: Add license information]

