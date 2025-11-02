/*
Copyright of Akshay Karjol and Kedar Rege
Created Date - 2 NOV 2025

For the project GPU_vs_CPU_AEB
*/

// user RHS functors (no I/O, pure math)

#pragma once
#include "models.hpp"

struct SystemRHS {
  const BrakeModel* brake;
  const Vehicle1D* vehicle;
  // delay lines (optional): pointers to device/host circular buffers managed by API

  __host__ __device__
  void operator()(double t,
                  const BrakeState& xb, const VehicleState& xv,
                  const Inputs& u,
                  BrakeState& dxb, VehicleState& dxv,
                  double delayed_brake_force) const
  {
    brake->rhs(t, xb, u, dxb);
    const double bf = brake->output(xb, u);        // instantaneous
    const double bf_used = delayed_brake_force>=0 ? delayed_brake_force : bf; // choose delay path
    vehicle->rhs(t, xv, bf_used, dxv);
  }
};