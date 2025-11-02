/*
Copyright of Akshay Karjol and Kedar Rege
Created Date - 2 NOV 2025

For the project GPU_vs_CPU_AEB
*/

// parallel_for, reduce via SYCL/CUDA/HIP

#pragma once

struct GPUBackend {
  template <typename F>
  void parallel_for(std::size_t n, F&& kernel); // launches a kernel (you implement)

  template <typename T>
  struct Buffer {
    T* ptr; std::size_t n;
    // device alloc/free; host <-> device copy helpers
  };
};