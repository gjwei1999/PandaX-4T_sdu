CMAKE_MINIMUM_REQUIRED(VERSION 3.0 FATAL_ERROR)
PROJECT(nest-lite)

set(nest-lite_VERSION "1.0")
set(PROJECT_VERTION ${nest-lite_VERSION})

include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++14" COMPILER_SUPPORTS_CXX14)

if (COMPILER_SUPPORTS_CXX14)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
	add_compile_options(-std=c++14)
else ()
  message (FATAL_ERROR "You need a compiler with standard c++14 support")
endif ()

# native optimized build
#  set(CMAKE_CXX_FLAGS_NATIVE "${CMAKE_CXX_FLAGS_RELEASE} -march=native
#      -mtune=native"
#      CACHE STRING "" FORCE)
#  set(CMAKE_C_FLAGS_NATIVE "${CMAKE_C_FLAGS_RELEASE} -march=native
#      -mtune=native"
#      CACHE STRING "" FORCE)


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic -Wall -Wextra -Werror")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--as-needed")

#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
#find_package(ROOT)

#include_directories(${ROOT_INCLUDE_DIR})
#include_directories(${CMAKE_SOURCE_DIR})



list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS} $ENV{ROOTSYS}/etc/cmake $ENV{ROOTSYS}/etc/root/cmake)
list(APPEND CMAKE_MODULE_PATH $ENV{ROOTSYS} $ENV{ROOTSYS}/etc/cmake $ENV{ROOTSYS}/etc/root/cmake)
  find_package(ROOT REQUIRED)
include_directories(${ROOT_INCLUDE_DIR})
include_directories(${ROOT_INCLUDE_DIRS})

install(DIRECTORY include/ DESTINATION include)

add_subdirectory(src)

set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR "TGZ")
include(CPack)
