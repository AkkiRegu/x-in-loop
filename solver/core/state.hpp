/*
Copyright of Akshay Karjol and Kedar Rege
Created Date - 2 NOV 2025

For the project GPU_vs_CPU_AEB
*/

#pragma once
#include <cstdint>

struct BrakeState { double x1, x2; };   // 2nd order internal states
struct VehicleState { double v, s; };   // velocity, position

struct BrakeParams { double wn, zeta, gain, delay_s; };
struct VehicleParams { double mass, drag, rr, force_delay_s; };

struct Inputs {
  double brake_torque_cmd; // command from API
};

struct Outputs {
  double brake_force;      // fed into vehicle
  double v, s;             // vehicle outputs
};