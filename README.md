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
  - `stepper.hpp` - RK/AB/implicit math (header-only, device-agnostic)
  - `rhs.hpp` - user RHS functors (no I/O, pure math)
  - `models.hpp` - brake and vehicle model definitions
  - `state.hpp` - state and parameter type definitions

- **backends/** - Parallel execution backends
  - `cpu_backend.hpp` - parallel_for, reduce via OpenMP/TBB
  - `gpu_backend.hpp` - parallel_for, reduce via SYCL/CUDA/HIP

- **drivers/** - Backend integration drivers
  - `solve_cpu.cpp` - wires core + cpu_backend
  - `solve_gpu.cpp` - wires core + gpu_backend

- **sim/** - simulation apis
  - `simulation_api.hpp` - Acts as a frontend API to higher level project files
## Installation

### Prerequisites

**Install Bazel** (required build system):

**For macOS:**
```bash
# Using Homebrew (recommended)
brew install bazel

# Verify installation
bazel --version
```

**For Ubuntu/Linux:**
```bash
# Install prerequisites
sudo apt update
sudo apt install apt-transport-https curl gnupg -y

# Add Bazel's distribution URI as a package source
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel-archive-keyring.gpg
sudo mv bazel-archive-keyring.gpg /usr/share/keyrings/
echo "deb [signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list

# Update and install Bazel
sudo apt update
sudo apt install bazel -y

# Verify installation
bazel --version
```

**For Windows:**
1. Download the Bazel installer from the [Bazel releases page](https://github.com/bazelbuild/bazel/releases)
2. Run the installer and follow on-screen instructions
3. Add Bazel to your system PATH if needed

### Clone the Repository

```bash
# Clone the git repo
git clone https://github.com/AkkiRegu/x-in-loop.git
cd x-in-loop

# Checkout the branch necessary for this study
git checkout user/krege/AEB-solver
```

### Additional Dependencies for Linux (GPU builds)

For GPU builds on Linux, you may need additional dependencies:

```bash
# For CUDA support (if applicable)
sudo apt install nvidia-cuda-toolkit nvidia-driver -y

# For OpenMP support (CPU backend)
sudo apt install libomp-dev -y

# Verify CUDA installation
nvidia-smi
nvcc --version
```

## Quick Start

```bash
# 1. Build the CPU solver
bazel build :main_cpu --config=cpu --config=opt

# 2. Run it
bazel run :main_cpu --config=cpu

# 3. Build the GPU solver (requires CUDA setup)
bazel build :main_gpu --config=gpu --config=opt

# 4. Run it
bazel run :main_gpu --config=gpu
```

## Usage

### Basic Build Commands

**Build CPU Backend:**
```bash
# Build with optimized settings
bazel build :main_cpu --config=cpu --config=opt

# Build with debug symbols
bazel build :main_cpu --config=cpu --config=dbg

# Or use explicit path
bazel build //solver/drivers:main_cpu --config=cpu
```

**Build GPU Backend:**
```bash
# Build with optimized settings
bazel build :main_gpu --config=gpu --config=opt

# Build with debug symbols
bazel build :main_gpu --config=gpu --config=dbg

# Or use explicit path
bazel build //solver/drivers:main_gpu --config=gpu
```

### Running the Solvers

**Run CPU Solver:**
```bash
# Build and run in one command
bazel run :main_cpu --config=cpu

# Or run the built binary directly
./bazel-bin/solver/drivers/main_cpu
```

**Run GPU Solver:**
```bash
# Build and run in one command
bazel run :main_gpu --config=gpu

# Or run the built binary directly
./bazel-bin/solver/drivers/main_gpu
```

### Advanced Usage

For more detailed build and execution examples, see [BUILD_EXAMPLES.md](BUILD_EXAMPLES.md).

**Clean build:**
```bash
bazel clean
bazel clean --expunge  # More aggressive clean
```

**View dependency graph:**
```bash
bazel query --notool_deps --noimplicit_deps 'deps(//solver/drivers:main_cpu)' --output=graph > deps.dot
```

[ Additional usage details and integration examples to be added by @akarjol ]


## License

[Open source development as of NOV 2 2025]


