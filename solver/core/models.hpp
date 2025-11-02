/*
Copyright of Akshay Karjol and Kedar Rege
Created Date - 2 NOV 2025

For the project GPU_vs_CPU_AEB
*/

#pragma once
#include "state.hpp"

struct BrakeModel {
  BrakeParams p;
  // rhs() computes d/dt of BrakeState given torque command (with internal delay handling hook)
  __host__ __device__
  void rhs(double t, const BrakeState& x, const Inputs& u, BrakeState& dx) const;
  __host__ __device__
  double output(const BrakeState& x, const Inputs& u) const; // -> brake_force (pre wheel radius etc.)
};

struct Vehicle1D {
  VehicleParams p;
  __host__ __device__
  void rhs(double t, const VehicleState& x, double brake_force, VehicleState& dx) const;
};