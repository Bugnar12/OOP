cmake_minimum_required(VERSION 3.16)
project(a45_Bugnar12)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a45_Bugnar12
        Domain.cpp
        Domain.h main.cpp DynamicArray.h Tests.h Tests.cpp AdminRepo.h AdminRepo.cpp Services.h Services.cpp UI.h UI.cpp UserRepo.h UserRepo.cpp)
