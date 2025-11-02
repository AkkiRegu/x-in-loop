# Copyright of Akshay Karjol and Kedar Rege
# Created Date - 2 NOV 2025
# For the project GPU_vs_CPU_AEB

# Root BUILD file for GPU_vs_CPU_AEB project

package(default_visibility = ["//visibility:public"])

alias(
    name = "solverlib",
    actual = "//solver/sim:solverlib",
)

alias(
    name = "main_cpu",
    actual = "//solver/drivers:main_cpu",
)

alias(
    name = "main_gpu",
    actual = "//solver/drivers:main_gpu",
)

alias(
    name = "run_brake_simulation",
    actual = "//solver/drivers:run_brake_simulation",
)

filegroup(
    name = "params_file",
    srcs = ["params_AEB.json"],
    visibility = ["//visibility:public"],
)