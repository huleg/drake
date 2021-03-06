# -*- python -*-
# This file contains rules for Bazel; see drake/doc/bazel.rst.

load("//tools:cpplint.bzl", "cpplint")

cc_library(
    name = "control_utils",
    srcs = [],
    hdrs = ["control_utils.h"],
    linkstatic = 1,
    deps = [
        "//drake/common",
        "//drake/math:geometric_transform",
    ],
)

cc_library(
    name = "rigid_body_tree_alias_groups",
    srcs = [
        "param_parsers/rigid_body_tree_alias_groups.cc",
    ],
    hdrs = [
        "param_parsers/rigid_body_tree_alias_groups.h",
    ],
    linkstatic = 1,
    deps = [
        "//drake/multibody:rigid_body_tree",
        "@yaml_cpp//:lib",
    ],
)

cc_library(
    name = "param_parser",
    srcs = [
        "param_parsers/param_parser.cc",
    ],
    hdrs = [
        "param_parsers/param_parser.h",
    ],
    linkstatic = 1,
    deps = [
        ":qp_controller",
        ":rigid_body_tree_alias_groups",
    ],
)

cc_library(
    name = "humanoid_status",
    srcs = ["humanoid_status.cc"],
    hdrs = ["humanoid_status.h"],
    linkstatic = 1,
    deps = [
        "//drake/common",
        "//drake/multibody:rigid_body_tree",
        "//drake/systems/robotInterfaces:side",
    ],
)

cc_library(
    name = "qp_controller",
    srcs = ["qp_controller.cc"],
    hdrs = ["qp_controller.h"],
    linkstatic = 1,
    deps = [
        ":humanoid_status",
        "//drake/common",
        "//drake/math:gradient",
        "//drake/solvers:mathematical_program",
    ],
)

# === test/ ===

cc_test(
    name = "valkyrie_balancing_test",
    srcs = ["test/valkyrie_balancing_test.cc"],
    data = [
        "config/alias_groups.yaml",
        "config/controller.yaml",
        "//drake/examples/Valkyrie:models",
    ],
    tags = [
        "exclusive",
        "gurobi",
        "local",
    ],
    deps = [
        ":control_utils",
        ":param_parser",
        ":qp_controller",
        "//drake/common:eigen_matrix_compare",
        "//drake/examples/Valkyrie:valkyrie_constants",
        "//drake/multibody/parsers",
        "@gtest//:main",
    ],
)

cc_test(
    name = "rigid_body_tree_alias_groups_test",
    srcs = ["param_parsers/test/rigid_body_tree_alias_groups_test.cc"],
    data = [
        "param_parsers/test/full.yaml",
        "param_parsers/test/no_body_groups.yaml",
        "param_parsers/test/no_joint_groups.yaml",
        "param_parsers/test/parse_fails.yaml",
        "//drake/multibody:test_models",
    ],
    deps = [
        ":rigid_body_tree_alias_groups",
        "//drake/common:eigen_matrix_compare",
        "//drake/multibody/parsers",
        "@gtest//:main",
    ],
)

cc_test(
    name = "param_parser_test",
    srcs = ["param_parsers/test/param_parser_test.cc"],
    data = [
        "param_parsers/test/alias_groups.yaml",
        "param_parsers/test/params.yaml",
        "//drake/examples/Valkyrie:models",
    ],
    deps = [
        ":param_parser",
        ":rigid_body_tree_alias_groups",
        "//drake/common:eigen_matrix_compare",
        "//drake/multibody/parsers",
        "@gtest//:main",
    ],
)

cpplint()
