cmake_minimum_required(VERSION 3.23)
project(s21_matrix_oop)

set(CMAKE_CXX_STANDARD 14)

#
#include_directories(src)
#add_subdirectory(src)
#add_subdirectory(test)
#add_subdirectory(Google_tests/lib)
#include_directories(Google_tests/lib/googletest/include)
#add_subdirectory(Google_tests/lib)
#
set(HEADER_FILES
        s21_matrix_oop.h
        )

set(SOURCE_FILES
        s21_matrix_oop.cpp
        )

#add_executable(s21_matrix_cpp
#        s21_matrix_oop.cpp
#        s21_matrix_oop.h)

add_library(s21_matrix_oop STATIC ${SOURCE_FILES} ${HEADER_FILES})