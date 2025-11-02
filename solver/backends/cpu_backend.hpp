/*
Copyright of Akshay Karjol and Kedar Rege
Created Date - 2 NOV 2025

For the project GPU_vs_CPU_AEB
*/

// parallel_for, reduce via OpenMP/TBB

#pragma once
#include <vector>
#include <functional>

struct CPUBackend {
  template <typename F>
  void parallel_for(std::size_t n, F&& f) {
    #pragma omp parallel for
    for (std::int64_t i=0; i<(std::int64_t)n; ++i) f((std::size_t)i);
  }

  template <typename T>
  using Buffer = std::vector<T>;
};