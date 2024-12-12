cmake_minimum_required(VERSION 3.10)
project(Lab5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ищем GTest
find_package(GTest REQUIRED)

# Создаём INTERFACE библиотеку для заголовочных файлов
add_library(pmr_list INTERFACE)
target_include_directories(pmr_list INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Исполняемый файл для основного кода (main.cpp)
add_executable(myapp main.cpp)
target_link_libraries(myapp PRIVATE pmr_list)

# Тестовый исполняемый файл (test.cpp)
add_executable(runTests test.cpp)
target_link_libraries(runTests PRIVATE GTest::gtest GTest::gtest_main pmr_list)

enable_testing()
add_test(NAME PmrListTest COMMAND runTests)