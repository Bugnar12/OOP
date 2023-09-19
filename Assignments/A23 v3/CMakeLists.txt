cmake_minimum_required(VERSION 3.16)
project(A23_v2 C)

set(CMAKE_C_STANDARD 11)

add_executable(A23_v2 main.c Domain.c Repository.h Repository.c Services.h Services.c Tests.h Tests.c UI.c UI.h DynamicArray.h DynamicArray.c Validator.h Validator.c Operations.c Operations.h)
