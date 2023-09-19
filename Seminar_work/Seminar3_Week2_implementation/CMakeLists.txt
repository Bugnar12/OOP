cmake_minimum_required(VERSION 3.24)
project(Seminar3_Week2_implementation)

set(CMAKE_CXX_STANDARD 14)

include_directories(Seminar3_Week2_implementation)

add_executable(Seminar3_Week2_implementation
        Seminar3_Week2_implementation/DynamicVector.h
        Seminar3_Week2_implementation/LinkedList.h
        Seminar3_Week2_implementation/List.h
        Seminar3_Week2_implementation/main.cpp)
