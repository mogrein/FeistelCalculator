# CMakeList.txt: проект CMake для FeistelCalc; включите исходный код и определения
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник для исполняемого файла этого проекта.
add_executable (FeistelCalc "FeistelCalc.cpp" "FeistelCalc.h")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
