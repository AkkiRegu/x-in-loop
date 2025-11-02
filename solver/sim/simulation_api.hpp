/*
Copyright of Akshay Karjol and Kedar Rege
Created Date - 2 NOV 2025

For the project GPU_vs_CPU_AEB
*/

#pragma once
#include <variant>
#include <string>
#include <optional>
#include "../core/state.hpp"
#include "../core/models.hpp"
#include "../core/rhs.hpp"
#include "../core/stepper.hpp"

struct RangeSpec { double start, step, stop; }; // e.g. 2000:10:3000

struct SimConfig {
  BrakeParams brake_p{};
  VehicleParams veh_p{};

  double t0{0.0}, dt{1e-3}, t_end{5.0};

  // optional swept parameters:
  std::optional<RangeSpec> mass_sweep;
  std::optional<RangeSpec> brake_delay_sweep;

  // initial conditions:
  BrakeState xb0{0,0};
  VehicleState xv0{0,0};

  // pbjson payloads (raw JSON; you map to Params/IC inside load_from_pbjson)
  std::string pbjson_params;
  std::string pbjson_initial_conditions;

  bool use_true_delay{false}; // else lag model inside brake/vehicle
};

enum class ExecBackend { CPU, GPU };

template <typename Backend>
class SimulationAPI {
public:
  SimulationAPI(const SimConfig& cfg, ExecBackend be)
  : cfg_(cfg), be_(be) {
    load_from_pbjson(cfg.pbjson_params, cfg.pbjson_initial_conditions);
    // allocate buffers for sweeps, states, delay lines
    construct_problem<Backend>();
  }

  // --- Setters / Getters (single handles, or batched by index) ---
  void set_brake_torque(double u);
  double get_vehicle_velocity(std::size_t i = 0) const;
  double get_vehicle_position(std::size_t i = 0) const;

  // For sweeps (N systems in parallel):
  std::size_t system_count() const;

  // --- Run control ---
  void reset();
  void run();         // integrates to t_end over all systems
  void step_once();   // one dt, useful for co-simulation

  // Export snapshots or final results (CPU- or GPU-aware)
  void fetch_results(/* out arrays or vector refs */);

private:
  SimConfig cfg_;
  ExecBackend be_;

  BrakeModel brake_;
  Vehicle1D vehicle_;
  SystemRHS sys_;

  // Batches when sweeps are active:
  typename Backend::Buffer<BrakeState> xb_;
  typename Backend::Buffer<VehicleState> xv_;
  typename Backend::Buffer<Inputs> u_;
  typename Backend::Buffer<double> brake_force_delay_line_; // if true delay
  // delay ctx pointer if needed
  void* delay_ctx_{nullptr};

  Stepper<Backend> stepper_;

  void load_from_pbjson(const std::string& params, const std::string& ics);
  template <typename B>
  void construct_problem();

  // helpers for range expansion
  static inline std::vector<double> expand(const RangeSpec& r) {
    std::vector<double> v; 
    for(double x=r.start; x<=r.stop + 1e-12; x+=r.step) v.push_back(x);
    return v;
  }
};