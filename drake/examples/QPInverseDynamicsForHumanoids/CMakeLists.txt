set(qp_inverse_dynamics_controller_src
  humanoid_status.cc
  qp_controller.cc)

add_library(drakeQPController ${qp_inverse_dynamics_controller_src})
target_link_libraries(drakeQPController
  drakeOptimization
  drakeRBM
  drakeSide)

if(lcm_FOUND)
  add_library(drakeQPControllerLcmTranslator lcm_utils.cc)
  target_link_libraries(drakeQPControllerLcmTranslator
    drakeRBM
    drakeLCMTypes
    drakeLCMUtil
    lcmtypes_bot2-core-cpp)
endif()

add_subdirectory(param_parsers)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()

