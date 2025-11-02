/*
Copyright of Akshay Karjol and Kedar Rege
Created Date - 2 NOV 2025

For the project GPU_vs_CPU_AEB
*/

// RK/AB/implicit math (header-only, device-agnostic)

#pragma once
template <typename Backend>
struct Stepper {
  // single system advance (one time step)
  __host__ __device__
  void step(double t, double dt,
            BrakeState& xb, VehicleState& xv,
            Inputs& u,
            const SystemRHS& f,
            /* delay context ref */ void* delay_ctx) const;
};