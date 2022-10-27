cmake_minimum_required(VERSION 3.23)
project(s21_containers)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        s21_vector.h
        )

set(SOURCE_FILES
        s21_vector.cc
        )

#add_executable(for_testing
#        for_testing.cc
#        for_testing.h)

add_library(vector STATIC ${SOURCE_FILES} ${HEADER_FILES})