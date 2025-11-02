# Bazel Build and Execution Examples

Copyright of Akshay Karjol and Kedar Rege  
Created Date - 2 NOV 2025

## Prerequisites

Install Bazel following instructions at: https://bazel.build/install

## Basic Build Commands

### Build CPU Backend
```bash
# Build the CPU solver binary
bazel build :main_cpu --config=cpu

# Or use the explicit path
bazel build //solver/drivers:main_cpu --config=cpu
```

### Build GPU Backend
```bash
# Build the GPU solver binary
bazel build :main_gpu --config=gpu

# Or use the explicit path
bazel build //solver/drivers:main_gpu --config=gpu
```

### Build with Different Compilation Modes

#### Debug Build
```bash
bazel build :main_cpu --config=cpu --config=dbg
bazel build :main_gpu --config=gpu --config=dbg
```

#### Optimized Build
```bash
bazel build :main_cpu --config=cpu --config=opt
bazel build :main_gpu --config=gpu --config=opt
```

## Execution Examples

### Run CPU Solver
```bash
# Run the CPU binary
bazel run :main_cpu --config=cpu

# Or run directly after building
./bazel-bin/main_cpu
```

### Run GPU Solver
```bash
# Run the GPU binary
bazel run :main_gpu --config=gpu

# Or run directly after building
./bazel-bin/main_gpu
```

## Build Specific Components

### Build Core Library Only
```bash
bazel build //solver/core:core
```

### Build Simulation API
```bash
bazel build //solver/sim:sim
bazel build //solver/sim:solverlib --config=cpu  # CPU version
bazel build //solver/sim:solverlib --config=gpu  # GPU version
```

### Build Individual Backends
```bash
bazel build //solver/backends:cpu_backend
bazel build //solver/backends:gpu_backend
```

## Testing

### Run Tests (once implemented)
```bash
bazel test //solver/drivers:main_cpu_test --config=cpu
bazel test //solver/drivers:main_gpu_test --config=gpu
```

## Clean Build

### Clean Entire Build
```bash
bazel clean
bazel clean --expunge  # More aggressive clean
```

### Clean and Rebuild
```bash
bazel clean && bazel build :main_cpu --config=cpu --config=opt
```

## View Dependency Graph

```bash
# Generate dependency graph
bazel query --notool_deps --noimplicit_deps 'deps(//solver/drivers:main_cpu)' --output=graph > deps.dot

# View with graphviz (if installed)
dot -Tpng deps.dot -o deps.png
```

## Parallel Builds

```bash
# Build with multiple workers
bazel build :main_cpu --config=cpu --jobs=8
```

## Remote Caching (if configured)

```bash
bazel build :main_cpu --config=cpu --remote_cache=http://your-cache-server:port
```

## Common Issues

### Issue: "command not found: bazel"
**Solution**: Install Bazel from https://bazel.build/install

### Issue: Missing CUDA support
**Solution**: Configure rules_cuda in WORKSPACE and uncomment CUDA config in .bazelrc

### Issue: Build fails with linker errors
**Solution**: Check that all dependencies are properly declared in BUILD files

## Project Structure Reference

```
.
├── BUILD              # Root build configuration
├── WORKSPACE          # Bazel workspace configuration
├── .bazelrc           # Bazel configuration flags
└── solver/
    ├── BUILD          # Solver module configuration
    ├── core/
    │   ├── BUILD      # Core library configuration
    │   └── *.hpp      # Header-only core components
    ├── backends/
    │   ├── BUILD      # Backend configurations
    │   └── *_backend.hpp
    ├── drivers/
    │   ├── BUILD      # Driver executable configurations
    │   └── main_*.cpp # Main executables
    └── sim/
        ├── BUILD      # Simulation API configuration
        └── simulation_api.hpp
```

## Quick Start Example

```bash
# 1. Clone the repository
git clone https://github.com/AkkiRegu/x-in-loop.git
cd x-in-loop

# 2. Checkout the correct branch
git checkout user/krege/AEB-solver

# 3. Build CPU version
bazel build :main_cpu --config=cpu --config=opt

# 4. Run the CPU solver
bazel run :main_cpu --config=cpu

# 5. Build GPU version (if CUDA is configured)
bazel build :main_gpu --config=gpu --config=opt

# 6. Run the GPU solver
bazel run :main_gpu --config=gpu
```

## Configuration Flags Explained

- `--config=cpu`: Selects CPU backend
- `--config=gpu`: Selects GPU backend
- `--config=dbg`: Debug build (no optimization, debug symbols)
- `--config=opt`: Optimized build (-O3, no debug symbols)
- `--define=backend=cpu`: Defines backend type for conditional compilation
- `--define=backend=gpu`: Defines backend type for conditional compilation

## Further Reading

- [Bazel Documentation](https://bazel.build/docs)
- [Bazel C++ Rules](https://bazel.build/reference/be/c-cpp)
- [Bazel Configuration Files](https://bazel.build/concepts/platforms-intro)

