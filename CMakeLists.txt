cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME "5e")
set(TASK_1_NAME "1_remove_spaces")
set(TASK_2_1_NAME "2_1_remove_adjacent_equal_letters")
set(TASK_2_2_NAME "2_2_remove_extra_spaces")
set(TASK_3_NAME "3_digit_to_start_reverse")
set(TASK_3_1_NAME "3_1_letters_to_start_digits_to_end")
set(TASK_4_NAME "4_replace_digits_by_spaces")
set(TASK_5_NAME "5_replace")
set(TASK_6_NAME "6_are_words_sorted")
set(TASK_7_NAME "7_output_words_in_reverse_order")
set(TASK_8_NAME "8_count_poly")
set(TASK_9_NAME "9_mix_words")
set(TASK_10_NAME "10_reverse_words_order")
set(TASK_19_NAME "19_is_substring_by_symbols")

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

target_include_directories(${TASK_3_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_3_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_3_NAME}_debug")

target_include_directories(${TASK_3_1_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_3_1_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_3_1_NAME}_debug")

target_include_directories(${TASK_4_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_4_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_4_NAME}_debug")

target_include_directories(${TASK_5_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_5_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_5_NAME}_debug")

target_include_directories(${TASK_6_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_6_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_6_NAME}_debug")

target_include_directories(${TASK_7_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_7_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_7_NAME}_debug")

target_include_directories(${TASK_8_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_8_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_8_NAME}_debug")

target_include_directories(${TASK_9_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_9_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_9_NAME}_debug")

target_include_directories(${TASK_10_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_10_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_10_NAME}_debug")



target_include_directories(${TASK_19_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_19_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_19_NAME}_debug")

