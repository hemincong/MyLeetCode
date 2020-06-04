cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

project(MyLeetCode)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

find_package(gtest)

# for gtest
set(CMAKE_C_FLAGS "-std=c99 -fno-omit-frame-pointer -O0")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${GTEST_CXXFLAGS})
include_directories(${GTEST_INCLUDE_DIR})
include_directories(${GTEST_DIR})

# TODO: add file name here!!
set(TEST_SRC_FILES xxxxxxxxx)

add_executable(MyLeetCode ${TEST_SRC_FILES} ${GTEST_SRC_DIR}/gtest-all.cc)
