set(SOURCES "main.c" "mystring.c")
add_executable(${PROJECT_NAME} ${SOURCES})

set(TASK_1_SOURCES "1_remove_spaces.c" "mystring.c")
add_executable(${TASK_1_NAME} ${TASK_1_SOURCES})

set(TASK_2_1_SOURCES "2_1_remove_adjacent_equal_letters.c" "mystring.c")
add_executable(${TASK_2_1_NAME} ${TASK_2_1_SOURCES})

set(TASK_2_2_SOURCES "2_2_remove_extra_spaces.c" "mystring.c")
add_executable(${TASK_2_2_NAME} ${TASK_2_2_SOURCES})

set(TASK_3_SOURCES "3_digit_to_start_reverse.c" "mystring.c")
add_executable(${TASK_3_NAME} ${TASK_3_SOURCES})

set(TASK_3_1_SOURCES "3_1_letters_to_start_digits_to_end.c" "mystring.c")
add_executable(${TASK_3_1_NAME} ${TASK_3_1_SOURCES})

set(TASK_4_SOURCES "4_replace_digits_by_spaces.c" "mystring.c")
add_executable(${TASK_4_NAME} ${TASK_4_SOURCES})

set(TASK_5_SOURCES "5_replace.c" "mystring.c")
add_executable(${TASK_5_NAME} ${TASK_5_SOURCES})

set(TASK_6_SOURCES "6_are_words_sorted.c" "mystring.c")
add_executable(${TASK_6_NAME} ${TASK_6_SOURCES})

set(TASK_19_SOURCES "19_is_substring_by_symbols.c" "mystring.c")
add_executable(${TASK_19_NAME} ${TASK_19_SOURCES})

