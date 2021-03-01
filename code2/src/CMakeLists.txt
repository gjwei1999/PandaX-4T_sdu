include_directories(${PROJECT_SOURCE_DIR}/include)

  add_library(det-sim STATIC det-sim.cc)
target_link_libraries(det-sim ${ROOT_LIBRARIES})

  add_library(pandax-quanta STATIC pandax-quanta.cc)
target_link_libraries(pandax-quanta ${ROOT_LIBRARIES})

  add_library(det-sim_s SHARED det-sim.cc)
target_link_libraries(det-sim_s ${ROOT_LIBRARIES})

  add_library(pandax-quanta_s SHARED pandax-quanta.cc)
target_link_libraries(pandax-quanta_s ${ROOT_LIBRARIES})

  add_executable(signal_mc_new signal_mc_new.cc)
target_link_libraries(signal_mc_new pandax-quanta det-sim  ${ROOT_LIBRARIES})

add_executable(signal_mc_old signal_mc_old.cc)
target_link_libraries(signal_mc_old pandax-quanta det-sim  ${ROOT_LIBRARIES})
  

install(TARGETS det-sim DESTINATION lib)
install(TARGETS pandax-quanta DESTINATION lib)
