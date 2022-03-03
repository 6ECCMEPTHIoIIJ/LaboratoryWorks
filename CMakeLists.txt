cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME "5e") # name of MAIN target
set(TASK_1_NAME "1_remove_spaces") # name of TASK_1 target
set(TASK_2_1_NAME "2_1_remove_adjacent_equal_letters") # name of TASK_2_1 target
set(TASK_2_2_NAME "2_2_remove_extra_spaces") # name of TASK_2_2 target
project(${PROJECT_NAME} VERSION "0.0.1" LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory("sources")

target_include_directories(${PROJECT_NAME} PRIVATE "include" "tests")
set_target_properties(${PROJECT_NAME}
                      PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
                      RUNTIME_OUTPUT_NAME_DEBUG "${PROJECT_NAME}_debug")

target_include_directories(${TASK_1_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_1_NAME}
                      PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
                      RUNTIME_OUTPUT_NAME_DEBUG "${TASK_1_NAME}_debug")

target_include_directories(${TASK_2_1_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_2_1_NAME}
                    PROPERTIES
                    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
                    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
                    RUNTIME_OUTPUT_NAME_DEBUG "${TASK_2_1_NAME}_debug")

target_include_directories(${TASK_2_2_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_2_2_NAME}
                    PROPERTIES
                    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
                    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
                    RUNTIME_OUTPUT_NAME_DEBUG "${TASK_2_2_NAME}_debug")