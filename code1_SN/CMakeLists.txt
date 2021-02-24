#/***************************/
#/*                         */
#/*  Created by Jiawei Guo  */
#/*   Shandong University   */
#/*                         */
#/***************************/
#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
project(main)

#----------------------------------------------------------------------------
# Find Root package, activating all available UI and Vis drivers by default
#

find_package(ROOT 6.0 REQUIRED COMPONENTS)


#----------------------------------------------------------------------------
# Setup Root include directories and compile definitions
# Setup include directory for this project
#
###include(${Geant4_USE_FILE})
find_package(ROOT COMPONENTS MathMore)
include(${ROOT_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)


#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB executers ${PROJECT_SOURCE_DIR}/exe/*.C)

add_library(code1_lib STATIC ${sources})

#----------------------------------------------------------------------------
# Add the executable, and link it to the Root libraries
#
foreach(exe_file IN LISTS executers)
    get_filename_component(exe_name ${exe_file} NAME_WE)
    add_executable(${exe_name} ${exe_file})
    target_link_libraries(${exe_name} code1_lib ${ROOT_LIBRARIES})
endforeach()
#    add_executable(main main.C ${sources} ${headers})
  #  target_link_libraries(main ${ROOT_LIBRARIES})




#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS main DESTINATION bin)


