# Copyright of Akshay Karjol and Kedar Rege
# Created Date - 2 NOV 2025
# For the project GPU_vs_CPU_AEB

# Backend integration drivers

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "main_cpu",
    srcs = ["main_cpu.cpp"],
    deps = [
        "//solver/sim:solverlib",
        "//solver/backends:cpu_backend",  # explicit so it links CPU path
    ],
)

cc_binary(
    name = "main_gpu",
    srcs = ["main_gpu.cpp"],
    deps = [
        "//solver/sim:solverlib",
        "//solver/backends:gpu_backend",
    ],
    copts = select({
        "//solver:gpu": ["-DUSE_GPU"],
        "//conditions:default": [],
    }),
    linkopts = select({
        "//solver:gpu": [],
        "//conditions:default": [],
    }),
)