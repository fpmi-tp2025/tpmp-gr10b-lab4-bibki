cmake_minimum_required(VERSION 3.10)
project(Tourism)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Настройка SQLite3
find_package(SQLite3 REQUIRED)

# Главное приложение (C)
add_executable(tourism_app
    src/main.c
    src/database.c
)

target_include_directories(tourism_app PRIVATE includes)
target_link_libraries(tourism_app PRIVATE SQLite::SQLite3)

# Тесты (C++)
enable_language(CXX)  # Включаем поддержку C++ только для тестов
find_package(GTest REQUIRED)