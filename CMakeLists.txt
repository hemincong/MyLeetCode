cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

project(MyLeetCode)

# for gtest
set(CMAKE_C_FLAGS "-std=c99 -fno-omit-frame-pointer -O0")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${GTEST_CXXFLAGS})

# TODO: add file name here!!
set(TEST_SRC_FILES InterView_46_Translate_Number.cpp)

add_executable(MyLeetCode ${TEST_SRC_FILES})
