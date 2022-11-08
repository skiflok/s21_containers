cmake_minimum_required(VERSION 3.21.1)
project(s21_containers)

set(CMAKE_CXX_STANDARD 17)

#set(HEADER_FILES
#        for_testing.h
#        )
#
#set(SOURCE_FILES
#        for_testing.cc
#        )





#add_library(pair STATIC pair.cc pair.h)

#cmake_minimum_required(VERSION 3.22)
#project(CPP2_s21_containers_0)
#
#set(CMAKE_CXX_STANDARD 17)
#
#include_directories(src)
#
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG release-1.12.1
#)
#
#set(gtest_force_shared_crt ON CACHE BOOL " ")
#FetchContent_MakeAvailable(googletest)
#
#enable_testing()
#
#add_executable(test_all
#        src/array.h
#        src/array_test.cpp
#        src/btree.h
#        src/list.h
#        src/test_list.cpp
#        src/map.h
#        src/map_test.cpp
#        src/multiset.h
#        src/multiset_test.cpp
#        src/queue.h
#        src/queue_test.cpp
#        src/set.h
#        src/set_test.cpp
#        src/stack.h
#        src/stack_test.cpp
#        src/vector.h
#        src/vector_test.cpp
#        )
#
#target_link_libraries(
#        test_all
#        GTest::gtest_main
#)
#
#include(GoogleTest)
#gtest_discover_tests(test_all)