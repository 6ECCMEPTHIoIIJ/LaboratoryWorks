cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME "5d") # name of MAIN target
project(${PROJECT_NAME} VERSION "0.0.1" LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED on)

include_directories("include")
add_subdirectory("sources")

set_target_properties(${PROJECT_NAME}
                      PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG  "${CMAKE_SOURCE_DIR}/bin/debug"
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
                      RUNTIME_OUTPUT_NAME_DEBUG "${PROJECT_NAME}_debug")