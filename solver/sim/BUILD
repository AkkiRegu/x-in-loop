# Copyright of Akshay Karjol and Kedar Rege
# Created Date - 2 NOV 2025
# For the project GPU_vs_CPU_AEB

# Simulation APIs

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "sim",
    hdrs = ["simulation_api.hpp"],
    deps = [
        "//solver/core:core",
        # Backend is chosen in drivers to avoid pulling both here.
    ],
    visibility = ["//visibility:public"],
)

# This bundles sim + a chosen backend into one linkable lib (nice for drivers)
cc_library(
    name = "solverlib",
    deps = select({
        "//solver:gpu": [
            ":sim",
            "//solver/backends:gpu_backend",
        ],
        "//solver:cpu": [
            ":sim",
            "//solver/backends:cpu_backend",
        ],
        "//conditions:default": [":sim"],  # default to CPU-only headers
    }),
    visibility = ["//visibility:public"],
)