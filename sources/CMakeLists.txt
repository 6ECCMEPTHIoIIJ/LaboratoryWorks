set(SOURCES "main.c" "mystring.c")
add_executable(${PROJECT_NAME} ${SOURCES})

set(TASK_1_SOURCES "1_remove_spaces.c" "mystring.c")
add_executable(${TASK_1_NAME} ${TASK_1_SOURCES})

set(TASK_2_SOURCES "2_1_remove_adjacent_equal_letters.c" "mystring.c")
add_executable(${TASK_2_NAME} ${TASK_2_SOURCES})