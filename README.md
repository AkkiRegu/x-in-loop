# GPU_vs_CPU_AEB

Copyright of Akshay Karjol and Kedar Rege  
Created Date - 2 NOV 2025

## Project Overview

Abstract: 
This project aims to develop an AI-guided, GPU-accelerated Monte Carlo framework for
evaluating the reliability of Automated Braking Systems (ABS) and Autonomous Emergency
Braking (AEB) technologies. Traditional Monte Carlo simulations for safety validation
require millions of stochastic driving scenarios to achieve statistical confidence, leading to
high computational cost. By leveraging parallel GPU computing and AI-based adaptive
sampling, this project accelerates reliability estimation while maintaining accuracy. A
lightweight neural sampler learns to focus computation on high-risk, rare-event scenarios,
reducing the number of samples required for a given confidence interval. The resulting
system demonstrates dual acceleration — computational (via CUDA kernels) and statistical
(via AI-guided sampling). Expected outcomes include a 50–200× computational speedup
over CPU baselines and a 3–10× reduction in sample requirements for equivalent accuracy.
This framework contributes to the broader field of intelligent vehicle systems, providing a
scalable tool for AI-driven safety validation under uncertainty.

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


