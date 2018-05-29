cmake_minimum_required(VERSION 3.7)

project(OpenPL LANGUAGES C)

option(BUILD_SHARED "Use this option for building shared libraries" 1)

include(${CMAKE_MODULE_PATH}/platform.cmake)

configuration_file(
     "${PROJECT_SOURCE_DIR}/include/pl/pl_config.h"
     "${PROJECT_BINARY_DIR}/pl_config.h"
)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_BINARY_DIR}")

add_subdirectory(src)
add_subdirectory(example)

