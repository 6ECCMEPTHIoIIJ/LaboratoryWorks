cmake_minimum_required(VERSION 3.23)

set(PRJCT "5d")
project(${PRJCT} VERSION "0.0.1" LANGUAGES C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG  "${CMAKE_SOURCE_DIR}/bin/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release")

add_subdirectory("sources")