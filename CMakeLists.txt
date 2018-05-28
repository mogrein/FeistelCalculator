# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("FeistelCalc")

# Включите подпроекты.
add_subdirectory ("FeistelCalc")


set(CMAKE_CXX_STANDARD 14)
