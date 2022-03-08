# последняя стабильная версия cmake - нужно устанавливать отдельно
cmake_minimum_required(VERSION 3.23)

# создали список переменных для именования целей, дабы потом не прописывать
# каждый раз их полные имена
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
set(TASK_11_NAME "11_get_word_before_first_word_with_symbol")
set(TASK_12_NAME "12_find_last_equal_word_in_both_str")
set(TASK_19_NAME "19_is_substring_by_symbols")

# написали версию сборки (зачем? - понятия не имею) и список связанных с
# проектом языков (их может быть и больше одного)
project(${PROJECT_NAME} VERSION "0.11.0" LANGUAGES C)

# указали стандарт С и С++ и указали, что необходимо запускать компиляцию в
# соответствии с этими стандартами
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory("sources")

# прописываем линковщику, где искать заголовочные файлы для конкретного
# подпроекта (позволяет не указывать полный путь до заголовочного файла,
# теперь достаточно просто написать имя библиотеки)
# существует глобальная команда include_directories(<пути до папок с
# заголовочными файлами>), однако все же хорошим стилем считается для каждой
# цели указывать связанные с ней библиотеки (хотя это и не критично)
target_include_directories(${PROJECT_NAME} PRIVATE "include" "tests")
set_target_properties(${PROJECT_NAME}
        PROPERTIES
        # теперь структура нашего проекта не привязана к clion-cmake-build
        # без этих строк готовую программу пришлось бы искать в разных папках
        # в зависимости от того, в какой среде мы работаем (например, та же
        # VS2020 или vscode создают папки build с другими именами и немного
        # не таким содержимым, даже при выборе соответствующих настроек, в
        # силу специфики свой работы)
        # указываем, куда компилировать сборку debug
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        # аналогично указываем, куда класть exe в сборке release
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        # чисто моя прихоть - хочу, чтобы проект в сборке debug имел
        # соответствующий суффикс, дабы его можно было отличить от рабочей
        # программы
        RUNTIME_OUTPUT_NAME_DEBUG "${PROJECT_NAME}_debug")

# аналогично делаем для каждой цели (существуют глобальные переменные
# CMAKE_RUNTIME_OUTPUT_DIRECTORY_<CONFIG>, где вместо <CONFIG> пишется
# DEBUG, RELEASE или ваша сборка, однако, так я использую свойство
# RUNTIME_OUTPUT_NAME_DEBUG, уникальное для каждой цели, то и остальные
# свойства придется прописывать везде, иначе их отсутствие перезапишет для цели
# значение глобальной переменной на стандартное)
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

target_include_directories(${TASK_11_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_11_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_11_NAME}_debug")

target_include_directories(${TASK_12_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_12_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_12_NAME}_debug")

target_include_directories(${TASK_19_NAME} PRIVATE "include" "tests")
set_target_properties(${TASK_19_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/release"
        RUNTIME_OUTPUT_NAME_DEBUG "${TASK_19_NAME}_debug")

